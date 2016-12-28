--- src/subtle/ruby.c.orig	2012-06-20 11:29:55 UTC
+++ src/subtle/ruby.c
@@ -2612,8 +2612,7 @@ RubyConfigLoadConfig(VALUE self,
 
       if((dirs = getenv("XDG_CONFIG_DIRS")))
         len += snprintf(tokens + len, sizeof(tokens), ":%s", dirs);
-      else len += snprintf(tokens + len, sizeof(tokens), ":%s/%s",
-        "/etc/xdg", PKG_NAME);
+      else len += snprintf(tokens + len, sizeof(tokens), ":%s", "/etc/xdg");
 
       if((home = getenv("XDG_DATA_HOME")))
         {
