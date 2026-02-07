--- ./plugins/battery/battery.c.orig	2010-05-05 04:52:59.000000000 -0700
+++ ./plugins/battery/battery.c	2010-11-17 11:06:07.000000000 -0800
@@ -1,9 +1,14 @@
 #include "misc.h"
 #include "../meter/meter.h"
-#include <sys/ioctl.h>
+//#include <sys/ioctl.h>
 #include <sys/types.h>
-#include <sys/stat.h>
-#include <fcntl.h>
+//#include <sys/stat.h>
+//#include <fcntl.h>
+
+#if defined __FreeBSD__
+#include <sys/param.h>
+#include <sys/sysctl.h>
+#endif
 
 //#define DEBUGPRN
 #include "dbg.h"
@@ -18,7 +23,7 @@
     gboolean exist;
 } battery_priv;
 
-static gboolean battery_update_os(battery_priv *c);
+static void battery_update_os(battery_priv *c);
 
 static gchar *batt_working[] = {
     "battery_0",
@@ -53,6 +58,59 @@
 
 #if defined __linux__
 #include "os_linux.c"
+#elif defined __FreeBSD__
+static void
+battery_update_os(battery_priv * c)
+{
+	static int	mib_state[4], mib_life[4], miblen_state, miblen_life, init = 0;
+	size_t		len;
+	int		state;
+	int		life;
+
+	ENTER;
+	if (init == 0) {
+		miblen_state = 4;
+		if (sysctlnametomib("hw.acpi.battery.state", mib_state, &miblen_state) == -1) {
+			c->exist = FALSE;
+			RET();
+		}
+		miblen_life = 4;
+		if (sysctlnametomib("hw.acpi.battery.life", mib_life, &miblen_life) == -1) {
+			c->exist = FALSE;
+			RET();
+		}
+		init = 1;
+	}
+	len = sizeof(int);
+	if (sysctl(mib_state, miblen_state, &state, &len, NULL, 0) != -1) {
+		len = sizeof(int);
+		if (sysctl(mib_life, miblen_life, &life, &len, NULL, 0) != -1) {
+			switch (state) {
+			case 0:
+			case 2:/* charging */
+				c->exist = TRUE;
+				c->charging = TRUE;
+				c->level = life;
+				break;
+			case 1:/* discharging */
+			case 4:/* critical */
+			case 5:/* low */
+				c->exist = TRUE;
+				c->charging = FALSE;
+				c->level = life;
+				break;
+			case 7:/* not present */
+			default:
+				c->exist = FALSE;
+				break;
+			}
+		} else
+			c->exist = FALSE;
+	} else {
+		c->exist = FALSE;
+	}
+	RET();
+}
 #else
 
 static void
@@ -79,7 +137,7 @@
     } else {
         i = batt_na;
         gtk_widget_set_tooltip_markup(((plugin_instance *)c)->pwid,
-            "Runing on AC\nNo battery found");
+            "Running on AC\nNo battery found");
     }
     k->set_icons(&c->meter, i);
     k->set_level(&c->meter, c->level);
