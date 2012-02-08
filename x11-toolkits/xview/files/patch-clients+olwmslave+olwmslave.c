--- clients/olwmslave/olwmslave.c.orig	2012-02-07 19:28:02.625687577 -0800
+++ clients/olwmslave/olwmslave.c	2012-02-07 19:38:15.496241454 -0800
@@ -44,9 +44,9 @@
 /* ----------------------------------------------------------------------
  *	Forward Definitions
  * ----------------------------------------------------------------------*/
-void		InitScreenInfo();
-void		ParseScreenArgs();
-Notify_value	InputReader();
+static void		InitScreenInfo();
+static void		ParseScreenArgs();
+static Notify_value	InputReader();
 
 /* ----------------------------------------------------------------------
  * 	main
@@ -73,13 +73,14 @@
 	if ((openwinDir = getenv("OPENWINHOME")) != 0)
 		(void)strcpy(localePath,openwinDir);
 	else
-#ifndef OPENWINHOME_DEFAULT
+#define OPENWINHOME_DEFAULT	"/usr/local/lib/X11"
+#ifdef OPENWINHOME_DEFAULT
 		/* martin-2.buck@student.uni-ulm.de */
 		(void)strcpy(localePath,OPENWINHOME_DEFAULT);
 #else
 		(void)strcpy(localePath,"/usr/share");
 #endif
-	(void)strcat(localePath,"/lib/locale");
+	(void)strcat(localePath,"/locale");
 	(void)bindtextdomain(domain,localePath);
 	textdomain(domain);
 	}
