--- programs/dtcm/dtcm/calendarA.c.orig	2021-07-03 12:35:15.000000000 -0700
+++ programs/dtcm/dtcm/calendarA.c	2021-07-12 13:58:22.306477000 -0700
@@ -2047,7 +2047,7 @@
 	set_message(c->message_text, buf);
 
 	sprintf(buf, "%s\n%s: %s, %s: %s", CATGETS(c->DT_catd, 1, 91,
-				   		"rpc.cmsd is not responding for your user name.\nMake sure the inetd process is running and the entry\nin inetd.conf for rpc.cmsd is correct for your host."),
+				   		"rpc.cmsd is not responding for your user name.\nMake sure the inetd process is running and the entry\nin /etc/rc.conf for rpc.cmsd is correct for your host."),
 		nl_user, name,
 		nl_host, host);
 
