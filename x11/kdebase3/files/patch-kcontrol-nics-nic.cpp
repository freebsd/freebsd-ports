--- kcontrol/nics/nic.cpp	15 Nov 2003 22:01:05 -0000	1.24
+++ kcontrol/nics/nic.cpp	21 Jan 2004 13:38:46 -0000
@@ -229,9 +229,14 @@ NICList* findNICs()
       tmp->addr = buf;
 
       if (ifa->ifa_netmask != NULL) {
+#ifdef Q_OS_FREEBSD
+	struct sockaddr_in *sinptr = (struct sockaddr_in *)ifa->ifa_netmask;
+	tmp->netmask=inet_ntoa(sinptr->sin_addr);
+#else
 	bzero(buf, 128);
 	getnameinfo(ifa->ifa_netmask, ifa->ifa_netmask->sa_len, buf, 127, 0, 0, NI_NUMERICHOST);
 	tmp->netmask = buf;
+#endif
       }
 
       if (ifa->ifa_flags & IFF_UP)
