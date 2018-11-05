We don't use inetd-- that involves messing with inetd.conf.  May as well
just launch as a daemon, which also deals with rpcbind dependency.

--- programs/dtcm/dtcm/calendarA.c.orig	2016-09-14 10:18:38 UTC
+++ programs/dtcm/dtcm/calendarA.c
@@ -2051,7 +2051,7 @@ error_open(Calendar *c) {
 	set_message(c->message_text, buf);
 
 	sprintf(buf, "%s\n%s: %s, %s: %s", catgets(c->DT_catd, 1, 91,
-				   		"rpc.cmsd is not responding for your user name.\nMake sure the inetd process is running and the entry\nin inetd.conf for rpc.cmsd is correct for your host."),
+				   		"rpc.cmsd is not responding for your user name.\nMake sure that rpc.cmsd is running and enabled\nin /etc/rc.conf (dtcms_enable=yes)."),
 		nl_user, name,
 		nl_host, host);
 
