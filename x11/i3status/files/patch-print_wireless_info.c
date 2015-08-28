--- src/print_wireless_info.c.orig	2014-01-05 03:34:06.000000000 -0800
+++ src/print_wireless_info.c	2015-08-13 20:12:29.854380000 -0700
@@ -193,10 +193,14 @@ static int get_wireless_info(const char 
         return 1;
 #endif
 #if defined(__FreeBSD__) || defined(__DragonFly__)
-        int s, len, inwid;
-        uint8_t buf[24 * 1024], *cp;
+        int s, inwid;
+        union {
+                struct ieee80211req_sta_req req;
+                uint8_t buf[24 * 1024];
+        } u;
         struct ieee80211req na;
-        char network_id[IEEE80211_NWID_LEN + 1];
+        char bssid[IEEE80211_ADDR_LEN];
+        size_t len;
 
         if ((s = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
                 return (0);
@@ -224,31 +228,38 @@ static int get_wireless_info(const char 
 
         memset(&na, 0, sizeof(na));
         strlcpy(na.i_name, interface, sizeof(na.i_name));
-        na.i_type = IEEE80211_IOC_SCAN_RESULTS;
-        na.i_data = buf;
-        na.i_len = sizeof(buf);
+        na.i_type = IEEE80211_IOC_BSSID;
+        na.i_data = bssid;
+        na.i_len = sizeof(bssid);
+
+        if (ioctl(s, SIOCG80211, (caddr_t)&na) == -1) {
+                close(s);
+                return (0);
+        }
+
+        memcpy(u.req.is_u.macaddr, bssid, sizeof(bssid));
+        memset(&na, 0, sizeof(na));
+        strlcpy(na.i_name, interface, sizeof(na.i_name));
+        na.i_type = IEEE80211_IOC_STA_INFO;
+        na.i_data = &u;
+        na.i_len = sizeof(u);
 
         if (ioctl(s, SIOCG80211, (caddr_t)&na) == -1) {
-                printf("fail\n");
                 close(s);
                 return (0);
         }
 
         close(s);
-        len = na.i_len;
-        cp = buf;
-        struct ieee80211req_scan_result *sr;
-        uint8_t *vp;
-        sr = (struct ieee80211req_scan_result *)cp;
-        vp = (u_int8_t *)(sr + 1);
-        strlcpy(network_id, (const char *)vp, sr->isr_ssid_len + 1);
-        if (!strcmp(network_id, &info->essid[0])) {
-                info->signal_level = sr->isr_rssi;
+        if (na.i_len >= sizeof(u.req)) {
+                /*
+                 * Just use the first BSSID returned even if there are
+                 * multiple APs sharing the same BSSID.
+                 */
+                info->signal_level = u.req.info[0].isi_rssi / 2 +
+                    u.req.info[0].isi_noise;
                 info->flags |= WIRELESS_INFO_FLAG_HAS_SIGNAL;
-                info->noise_level = sr->isr_noise;
+                info->noise_level = u.req.info[0].isi_noise;
                 info->flags |= WIRELESS_INFO_FLAG_HAS_NOISE;
-                info->quality = sr->isr_intval;
-                info->flags |= WIRELESS_INFO_FLAG_HAS_QUALITY;
         }
 
         return 1;
