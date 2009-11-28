--- gui/simple-greeter/gdm-greeter-login-window.c.orig	2009-10-24 20:05:24.000000000 -0400
+++ gui/simple-greeter/gdm-greeter-login-window.c	2009-10-24 20:11:02.000000000 -0400
@@ -56,10 +56,6 @@
 #include <dbus/dbus-glib.h>
 #include <dbus/dbus-glib-lowlevel.h>
 
-#ifdef HAVE_DEVICEKIT_POWER
-#include <devkit-power-gobject/devicekit-power.h>
-#endif
-
 #include "gdm-settings-client.h"
 #include "gdm-settings-keys.h"
 #include "gdm-profile.h"
@@ -83,6 +79,10 @@
 #define CK_SEAT_INTERFACE    "org.freedesktop.ConsoleKit.Seat"
 #define CK_SESSION_INTERFACE "org.freedesktop.ConsoleKit.Session"
 
+#define GPM_DBUS_NAME "org.freedesktop.PowerManagement"
+#define GPM_DBUS_PATH "/org/freedesktop/PowerManagement"
+#define GPM_DBUS_INTERFACE "org.freedesktop.PowerManagement"
+
 #define GLADE_XML_FILE       "gdm-greeter-login-window.glade"
 
 #define KEY_GREETER_DIR             "/apps/gdm/simple-greeter"
@@ -477,22 +477,46 @@ adjust_other_login_visibility(GdmGreeter
         }
 }
 
-#ifdef HAVE_DEVICEKIT_POWER
 static gboolean
 can_suspend (GdmGreeterLoginWindow *login_window)
 {
-        gboolean ret;
-        DkpClient *dkp_client;
+	DBusGConnection *connection;
+	DBusGProxy *proxy;
+	GError *error;
+	gboolean ret;
+	gboolean res;
+
+	error = NULL;
+	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
+	if (error != NULL) {
+		g_warning ("Couldn't connect to power manager: %s", error->message);
+		g_error_free (error);
+		return FALSE;
+	}
+	proxy = dbus_g_proxy_new_for_name (connection,
+					   GPM_DBUS_NAME,
+					   GPM_DBUS_PATH,
+					   GPM_DBUS_INTERFACE);
+
+	ret = FALSE;
+
+	res = dbus_g_proxy_call (proxy, "CanSuspend",
+				 &error,
+				 G_TYPE_INVALID,
+				 G_TYPE_BOOLEAN,
+				 &ret,
+				 G_TYPE_INVALID);
+	if (!res) {
+		if (error != NULL) {
+			g_warning ("Could not ask power manager if user can suspend: %s",
+				   error->message);
+			g_error_free (error);
+		}
+		ret = FALSE;
+	}
 
-        /* use DeviceKit-power to get data */
-        dkp_client = dkp_client_new ();
-        g_object_get (dkp_client,
-                      "can-suspend", &ret,
-                      NULL);
-        g_object_unref (dkp_client);
-        return ret;
+	return ret;
 }
-#endif
 
 static void
 remove_sensitize_power_buttons_timeout (GdmGreeterLoginWindow *login_window)
@@ -544,11 +568,7 @@ switch_mode (GdmGreeterLoginWindow *logi
 
         show_restart_buttons = get_show_restart_buttons (login_window);
 
-#ifdef HAVE_DEVICEKIT_POWER
         show_suspend_button = can_suspend (login_window);
-#else
-        show_suspend_button = FALSE;
-#endif
 
         /* we want to run this even if we're supposed to
            be in the mode already so that we reset everything
@@ -634,25 +654,39 @@ do_disconnect (GdmGreeterLoginWindow *lo
         gtk_main_quit ();
 }
 
-#ifdef HAVE_DEVICEKIT_POWER
 static void
 do_suspend (GdmGreeterLoginWindow *login_window)
 {
-        gboolean ret;
-        DkpClient *dkp_client;
-        GError *error = NULL;
-
-        /* use DeviceKit-power to get data */
-        dkp_client = dkp_client_new ();
-        ret = dkp_client_suspend (dkp_client, &error);
-        if (!ret) {
+	GError *error;
+	DBusGConnection *connection;
+	DBusGProxy *proxy;
+
+	g_debug ("GdmGreeterLoginWindow: Suspend button clicked");
+
+	error = NULL;
+	connection = dbus_g_bus_get (DBUS_BUS_SESSION, &error);
+	if (error != NULL) {
                 g_warning ("Couldn't suspend: %s", error->message);
                 g_error_free (error);
                 return;
         }
-        g_object_unref (dkp_client);
+	proxy = dbus_g_proxy_new_for_name (connection,
+					   GPM_DBUS_NAME,
+					   GPM_DBUS_PATH,
+					   GPM_DBUS_INTERFACE);
+	error = NULL;
+	dbus_g_proxy_call (proxy,
+			   "Suspend",
+			   &error,
+			   G_TYPE_INVALID,
+			   G_TYPE_INVALID);
+	if (error != NULL) {
+		g_warning ("Couldn't suspend: %s", error->message);
+		g_error_free (error);
+		return;
+	}
+	g_object_unref (proxy);
 }
-#endif
 
 static void
 delete_entry_text (GtkWidget *entry)
@@ -971,9 +1005,7 @@ static void
 suspend_button_clicked (GtkButton             *button,
                         GdmGreeterLoginWindow *login_window)
 {
-#ifdef HAVE_DEVICEKIT_POWER
         do_suspend (login_window);
-#endif
 }
 
 
