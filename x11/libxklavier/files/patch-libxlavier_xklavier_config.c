--- libxklavier/xklavier_config.c.orig	Thu May 15 00:43:07 2003
+++ libxklavier/xklavier_config.c	Thu May 15 00:45:12 2003
@@ -42,6 +42,18 @@
 static XkbComponentNamesRec componentNames;
 static char *locale;
 
+static char *
+xxx_strndup(const char *str, int len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    memcpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+
 static Bool _XklConfigInitialized(  )
 {
   return theRegistry.xpathContext != NULL;
@@ -306,13 +318,13 @@
     while( ( npc = strchr( pc, ',' ) ) != NULL )
     {
       int len = npc - pc;
-      *ppc = ( char * ) strndup( pc, len );
+      *ppc = ( char * ) xxx_strndup( pc, len );
       ppc++;
       pc = npc + 1;
     }
 
     len = npc - pc;
-    *ppc = ( char * ) strndup( pc, len );
+    *ppc = ( char * ) xxx_strndup( pc, len );
   }
 }
 
