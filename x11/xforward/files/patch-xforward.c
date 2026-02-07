--- xforward.c.orig	1993-06-04 19:30:16.000000000 -0700
+++ xforward.c	2023-02-14 20:42:29.724713000 -0800
@@ -292,7 +292,7 @@
 	struct timeval timeout;
 	struct pend_conn *cur,*prev;
 	pid_t temppid;
-	union wait wstatus;
+	int wstatus;
 	int exitstat,wopts,newoutgoing;
 
 	/* for each entry, call waitpid */
@@ -525,7 +525,7 @@
 			app_con = XtCreateApplicationContext();
 			dpy = XtOpenDisplay(app_con,disp_str,NULL,"Xforward",
 					    NULL,0,&argc,argv);
-			topshell = XtAppCreateShell(NULL,"Xforward",applicationShellWidgetClass, dpy, NULL,NULL);
+			topshell = XtAppCreateShell(NULL,"Xforward",applicationShellWidgetClass, dpy, NULL, (Cardinal)NULL);
 			sprintf(dialog_message,"Allow X connection from %s ?",
 				okhost_names[i]);
 			msg_str = XmStringCreateSimple(dialog_message);
