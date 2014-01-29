--- cinnamon-session/csm-dbus-client.c.orig	2013-11-24 01:26:24.698703150 +0000
+++ cinnamon-session/csm-dbus-client.c	2013-11-24 01:26:58.843700902 +0000
@@ -126,11 +126,20 @@
         char         buf[512];
         DBusMessage *reply;
 
+#ifdef __clang__
+#pragma clang diagnostic push
+#pragma clang diagnostic ignored "-Wformat-nonliteral"
+#endif
+
         va_list args;
         va_start (args, format);
         vsnprintf (buf, sizeof (buf), format, args);
         va_end (args);
 
+#ifdef __clang__
+#pragma clang diagnostic pop
+#endif
+
         reply = dbus_message_new_error (in_reply_to, error_name, buf);
         if (reply == NULL) {
                 g_error ("No memory");
