#include "EchoWebsock.h"

struct Subscriber {
  std::string chatRoomName_;
  drogon::SubscriberID id_;
};

void EchoWebsock::handleNewMessage(const WebSocketConnectionPtr& wsConnPtr,
                                   std::string&& message,
                                   const WebSocketMessageType& type) {
  LOG_DEBUG << "new websocket message:" << message;
  if (type == WebSocketMessageType::Ping) {
    LOG_DEBUG << "recv a ping";
  } else if (type == WebSocketMessageType::Text) {
    auto& s = wsConnPtr->getContextRef<Subscriber>();
    chatRooms_.publish(s.chatRoomName_, message);
  }
}
void EchoWebsock::handleNewConnection(const HttpRequestPtr& req,
                                      const WebSocketConnectionPtr& wsConnPtr) {
  LOG_DEBUG << "new websocket connection!";
  wsConnPtr->send("haha!!!");
  Subscriber s;
  s.chatRoomName_ = req->getParameter("room_name");
  s.id_ = chatRooms_.subscribe(
      s.chatRoomName_,
      [wsConnPtr](const std::string& topic, const std::string& message) {
        // Suppress unused variable warning
        (void)topic;
        wsConnPtr->send(message);
      });
  wsConnPtr->setContext(std::make_shared<Subscriber>(std::move(s)));
}
void EchoWebsock::handleConnectionClosed(
    const WebSocketConnectionPtr& wsConnPtr) {
  LOG_DEBUG << "websocket closed!";
  auto& s = wsConnPtr->getContextRef<Subscriber>();
  chatRooms_.unsubscribe(s.chatRoomName_, s.id_);
}
