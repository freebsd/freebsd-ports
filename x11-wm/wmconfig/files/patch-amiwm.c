--- amiwm.c.orig	Wed Nov 17 23:01:30 2004
+++ amiwm.c	Thu Jan 27 00:04:07 2005
@@ -40,9 +40,9 @@
    /* Amiwm seems to have no restart or quit function
    and Amiwm requires that there's no ending & */
    if (! app->restart) {
-    printf("ToolItem \"%s\" ", app->name);
     char *b;
     int l;
+    printf("ToolItem \"%s\" ", app->name);
     b = app->exec;
     l = strlen(b);
     if (app->terminal)
