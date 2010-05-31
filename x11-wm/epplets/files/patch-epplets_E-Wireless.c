--- epplets/E-Wireless.c.orig	2006-04-16 00:32:43.000000000 +0200
+++ epplets/E-Wireless.c	2008-03-10 21:21:36.000000000 +0100
@@ -3,6 +3,8 @@
  *  copyleft (C) Mark C. Langston 1999
  *  Damn near all the code originally from: cocidius@telebot.net
  *   and his E-CpuX Epplet.
+ *
+ *  Copyright (C) 2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  */
 
 #include <stdio.h>
@@ -13,6 +15,18 @@
 #include <errno.h>
 #include <epplet.h>
 
+#ifdef __FreeBSD__
+#include <sys/param.h>
+#include <sys/types.h>
+#include <sys/socket.h>
+#include <sys/sockio.h>
+#include <net/if.h>
+#include <net/if_media.h>
+#include <net80211/ieee80211_ioctl.h>
+#include <ifaddrs.h>
+#include <strings.h>
+#endif
+
 #define HEIGHT 30
 #define WIDTH  40
 
@@ -25,7 +39,7 @@
 int                 cpu_hist_size = 0;
 int                *cpu_hist = NULL;
 int                 hist_pos = 0;
-int                 color = 0;
+size_t              color = 0;
 unsigned long       prev_total = 0;
 unsigned long       prev_out = 0;
 unsigned long       prev_in = 0;
@@ -152,11 +166,71 @@
 static void
 cb_timer(void *data)
 {
+   double sigstr = 0;
+   unsigned long l0;
+   char ss[64];
+   int percent;
+
+/*
+ * Sorry, no support for FreeBSD 5.x
+ */
+#ifdef __FreeBSD__ 
+   char if_name[IFNAMSIZ];
+   int sock;
+   char buffer[24 * 1024];
+   struct ifaddrs *ifa, *ifa_iter;
+   struct ifmediareq ifmr;
+   struct ieee80211req ireq;
+   struct ieee80211req_scan_result scan;
+
+   bzero(if_name, sizeof(if_name));
+
+   if((sock = socket(PF_INET, SOCK_DGRAM, 0)) == -1) {
+      perror("socket");
+      goto common;
+   }
+
+   if(getifaddrs(&ifa)) {
+      perror("getifaddrs");
+      goto common;
+   }
+
+   ifa_iter = ifa;
+   do
+   {
+      bzero(&ifmr, sizeof(ifmr));
+      strncpy(ifmr.ifm_name, ifa_iter->ifa_name, sizeof(ifmr.ifm_name)-1);
+
+      if(ioctl(sock, SIOCGIFMEDIA, &ifmr) < 0) continue;
+      if(!(ifmr.ifm_status & IFM_AVALID)) continue;
+      if(IFM_TYPE(ifmr.ifm_active) != IFM_IEEE80211) continue;
+      strncpy(if_name, ifa_iter->ifa_name, sizeof(if_name)-1);
+      break;
+   } while((ifa_iter = ifa_iter->ifa_next));
+
+   freeifaddrs(ifa);
+
+   if(!*if_name) goto common;
+
+   strncpy(ireq.i_name, if_name, sizeof(ireq.i_name) - 1);
+   ireq.i_type = IEEE80211_IOC_SCAN_RESULTS;
+   ireq.i_data = buffer;
+   ireq.i_len = sizeof(buffer);
+
+   if(ioctl(sock, SIOCG80211, &ireq) < 0) {
+      close(sock);
+      goto common;
+   }
+   close(sock);
+
+   if(ireq.i_len < sizeof(scan))
+      goto common;
+
+   bcopy(buffer, &scan, sizeof(scan));
+   sigstr = scan.isr_rssi;
+#else
    FILE               *fpStat;
-   int                 percent;
-   double              sigstr;
-   char                s[256], ss[64];
-   unsigned long       l0;
+   char                s[256];
 
    fpStat = fopen("/proc/net/wireless", "r");
    if (fpStat)
@@ -169,8 +243,15 @@
 	sscanf(s, "%*s %*s %s %*s %*s %*s %*s %*s", ss);
 
 	sigstr = atof(ss);
+	fclose(fpStat);
+     }
+#endif
+
+common:
+
+   l0 = sigstr;
+	percent = (100 * l0 / 92);
 
-	l0 = sigstr;
 	percent = (100 * l0 / 92);
 	if (percent > 100)
 	   percent = 100;
@@ -179,13 +260,11 @@
 	sprintf(ss, "%d%%", percent);
 	Epplet_change_label(lbl_usage, ss);
 
-	fclose(fpStat);
 	draw_graph();
 	hist_pos++;
 	hist_pos %= WIDTH;
 	Epplet_paste_buf(buf, win, 0, 0);
 	Epplet_timer(cb_timer, NULL, 1, "TIMER");
-     }
    data = NULL;
 }
 
@@ -283,10 +362,10 @@
 
    p = Epplet_create_popup();
    Epplet_add_popup_entry(p, "Green", NULL, cb_color, (void *)0L);
-   Epplet_add_popup_entry(p, "Blue", NULL, cb_color, (void *)1L);
-   Epplet_add_popup_entry(p, "Red", NULL, cb_color, (void *)2L);
-   Epplet_add_popup_entry(p, "Yellow", NULL, cb_color, (void *)3L);
-   Epplet_add_popup_entry(p, "Cyan", NULL, cb_color, (void *)4L);
+   Epplet_add_popup_entry(p, "Red", NULL, cb_color, (void *)1L);
+   Epplet_add_popup_entry(p, "Blue", NULL, cb_color, (void *)2L);
+   Epplet_add_popup_entry(p, "Cyan", NULL, cb_color, (void *)3L);
+   Epplet_add_popup_entry(p, "Yellow", NULL, cb_color, (void *)4L);
    Epplet_add_popup_entry(p, "Magenta", NULL, cb_color, (void *)5L);
    Epplet_add_popup_entry(p, "Gray", NULL, cb_color, (void *)6L);
    popup = Epplet_create_popupbutton("Colors", NULL, 6, 24, 36, 12, NULL, p);
