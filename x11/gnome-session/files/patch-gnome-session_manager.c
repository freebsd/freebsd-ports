--- gnome-session/manager.c.orig	Tue Oct 12 14:04:26 2004
+++ gnome-session/manager.c	Tue Oct 12 14:05:51 2004
@@ -1042,9 +1042,10 @@
 
       if (interact_ping_replied)
 	{
+	  IceConn ice_conn;
 	  gsm_verbose ("have interact_list; sending ping with data to client %p\n", client);
 	  print_client (client);
-	  IceConn ice_conn = SmsGetIceConnection (client->connection);
+	  ice_conn = SmsGetIceConnection (client->connection);
 	  interact_ping_replied = FALSE;
 	  IcePing (ice_conn, interact_ping_reply, (IcePointer)client);
 	}
