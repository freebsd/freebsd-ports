--- clients/olwm/client.c.orig	2005-03-28 06:39:46.000000000 -0800
+++ clients/olwm/client.c	2013-09-17 22:50:16.981049021 -0700
@@ -250,7 +250,7 @@
 	Client	*cli;
 {
 	if (!DoingWindowState)
-		return;
+		return 0;
 
 	/*
  	 * If the client has specified the window state then interpret it.
@@ -281,15 +281,15 @@
 	OLWindowState	winState;
 
 	if (!DoingWindowState)
-		return;
+		return 0;
 
 	if (cli->framewin == NULL)
-		return;
+		return 0;
 
 	pane = PANEWINOFCLIENT(cli);
 
 	if (!PropGetOLWindowState(cli->dpy,pane,&winState))
-		return;
+		return 0;
 
 	if (cli->windowState == NULL)
 		cli->windowState = MemNew(OLWindowState);
