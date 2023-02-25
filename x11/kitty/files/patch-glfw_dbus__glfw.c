--- glfw/dbus_glfw.c.orig	2022-11-07 10:06:42 UTC
+++ glfw/dbus_glfw.c
@@ -174,7 +174,7 @@ glfw_dbus_dispatch(DBusConnection *conn) {
 }
 
 void
-glfw_dbus_session_bus_dispatch() {
+glfw_dbus_session_bus_dispatch(void) {
     if (session_bus) glfw_dbus_dispatch(session_bus);
 }
 
@@ -344,7 +344,7 @@ glfw_dbus_connect_to_session_bus(void) {
 }
 
 DBusConnection *
-glfw_dbus_session_bus() {
+glfw_dbus_session_bus(void) {
     if (!session_bus) glfw_dbus_connect_to_session_bus();
     return session_bus;
 }
