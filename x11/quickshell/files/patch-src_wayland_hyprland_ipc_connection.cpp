--- src/wayland/hyprland/ipc/connection.cpp.orig
+++ src/wayland/hyprland/ipc/connection.cpp
@@ -177,8 +177,12 @@
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
