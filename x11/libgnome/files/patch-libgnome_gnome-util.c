--- libgnome/gnome-util.c.orig	Mon Jul 10 15:25:22 2006
+++ libgnome/gnome-util.c	Mon Jul 10 15:25:55 2006
@@ -79,11 +79,11 @@
 	const char shells [][14] = {
 		/* Note that on some systems shells can also
 		 * be installed in /usr/bin */
-		"/bin/bash", "/usr/bin/bash",
-		"/bin/zsh", "/usr/bin/zsh",
-		"/bin/tcsh", "/usr/bin/tcsh",
-		"/bin/ksh", "/usr/bin/ksh",
-		"/bin/csh", "/bin/sh"
+		LOCALBASE "/bin/bash",
+		LOCALBASE "/bin/zsh",
+		LOCALBASE "/bin/ksh",
+		0
+
 	};
 
 	if (geteuid () == getuid () &&
