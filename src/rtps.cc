#include <fastrtps/fastrtps_all.h>
#include <chrono>
#include <thread>

#include "HelloWorldPubSubTypes.h"

/*
 * FastRTPS only version of ros.cc.
 * 10 publishers publish on 2 topics each. All 20 topics have at 10 subscribers.
 */

using namespace eprosima;
using namespace eprosima::fastrtps;
using namespace std::chrono_literals;

static HelloWorldPubSubType g_hello_world_type;
static SubscriberListener g_listener;

Subscriber* createSub(Participant* participant, std::string topic) {
  SubscriberAttributes att;
  att.topic.topicKind = rtps::NO_KEY;
  // Must be registered before the creation of the subscriber:
  att.topic.topicDataType = g_hello_world_type.getName();
  att.topic.topicName = topic;
  att.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
  att.topic.historyQos.depth = 10;
  return Domain::createSubscriber(participant, att,
                                  static_cast<SubscriberListener*>(&g_listener));
}

Publisher* createPub(Participant* participant, std::string topic) {
  PublisherAttributes att;
  att.topic.topicKind = rtps::NO_KEY;
  att.topic.topicDataType = g_hello_world_type.getName();
  att.topic.topicName = topic;
  att.topic.historyQos.kind = KEEP_LAST_HISTORY_QOS;
  att.topic.historyQos.depth = 10;
  return Domain::createPublisher(participant, att);
}

int main(int argc, char** argv) {
  int create = argc > 1 ? std::atoi(argv[1]) : 10;
  std::chrono::milliseconds interval(argc > 2 ? std::atoi(argv[2]) : 20);
  std::cout << "FastRTPS create " << create << " nodes @ " << interval.count() << "ms" << std::endl;

  ParticipantAttributes participant_att;
  participant_att.rtps.builtin.domainId = 189;
  participant_att.rtps.builtin.leaseDuration = c_TimeInfinite;
  participant_att.rtps.setName("Participant_publisher");  // You can put here the name you want
  auto participant = Domain::createParticipant(participant_att);

  std::vector<std::function<void()>> timer_cb;

  Domain::registerType(participant, static_cast<TopicDataType*>(&g_hello_world_type));

  for (int n = 0; n < create; ++n) {
    auto pub1 = createPub(participant, "topic_" + std::to_string(n));
    auto pub2 = createPub(participant, "topic_" + std::to_string(n + create));
    auto cb = [=]() {
      HelloWorld stub;
      stub.msg() = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
      pub1->write(&stub);
      pub2->write(&stub);
    };
    timer_cb.push_back(cb);

    for (int s = 0; s < 2 * create; ++s) {
      createSub(participant, "topic_" + std::to_string(s));
    }
  }

  while (1) {
    auto start = std::chrono::system_clock::now();
    for (auto cb : timer_cb) {
      cb();
    }
    auto end = std::chrono::system_clock::now();

    std::this_thread::sleep_for(interval - (end - start));
  }
}
