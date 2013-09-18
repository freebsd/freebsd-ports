--- olvwmrc.y.orig	2013-09-17 21:38:07.492238885 -0700
+++ olvwmrc.y	2013-09-17 21:40:59.782778854 -0700
@@ -37,7 +37,7 @@
 char	*LookupToken();
 char	*FindOlvwmRC();
 void	resetKeys();
-char	*strexpand();
+static	char *strexpand();
 
 typedef struct progscreen {
     char        *target;
@@ -527,7 +527,9 @@
 	    }
 %%
 /* Programs */
+#ifndef YYDEBUG
 #define YYDEBUG 1
+#endif
 #include "parse.c"
 
 extern List	*ActiveClientList;
@@ -1160,7 +1162,7 @@
 	    for (c = ListEnum(&l); c != NULL; c = ListEnum(&l)) {
 		if (findClient(c, ie->identifier)) {
 		    ListApply(ie->doIf, applyAction, c);
-		    return;
+		    return 0;
 		}
 	    }
 	    ListApply(ie->doElse, applyAction, cli);
@@ -1260,7 +1262,7 @@
     if (path == NULL)
 	path = FindOlvwmRC(&olvwmBuf);
     if (path == NULL || (yyin = fopen(path, "r")) == NULL)
-	return;
+	return 0;
     olvwmOldBuf = olvwmBuf;
     dpy = ldpy;
     NumLockMask = FindModifierMask(XKeysymToKeycode(dpy, XK_Num_Lock));
@@ -1283,7 +1285,7 @@
 extern XrmDatabase OlwmDB;
 
     if (!p)
-	return;
+	return 0;
     if (olvwmBuf.st_mtime != olvwmOldBuf.st_mtime
           || olvwmBuf.st_size != olvwmOldBuf.st_size
           || olvwmBuf.st_dev != olvwmOldBuf.st_dev
