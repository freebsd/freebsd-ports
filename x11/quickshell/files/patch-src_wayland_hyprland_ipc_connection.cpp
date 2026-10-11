--- src/wayland/hyprland/ipc/connection.cpp.orig	2026-10-08 08:42:54 UTC
+++ src/wayland/hyprland/ipc/connection.cpp
@@ -189,8 +189,12 @@ void HyprlandIpc::makeRequest(
 	auto connectedCallback = [this, request, requestSocket, callback]() {
 		auto responseCallback = [requestSocket, callback]() {
 			auto response = requestSocket->readAll();
+			// Runs inside the socket's readyRead emission, after which QIODevice
+			// still touches the socket: defer deleting it, and stop further
+			// signals so the callback runs only once.
+			requestSocket->disconnect();
+			requestSocket->deleteLater();
 			callback(true, std::move(response));
-			delete requestSocket;
 		};
 
 		QObject::connect(requestSocket, &QLocalSocket::readyRead, this, responseCallback);
