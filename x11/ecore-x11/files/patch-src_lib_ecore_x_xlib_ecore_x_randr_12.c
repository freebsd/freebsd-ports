--- src/lib/ecore_x/xlib/ecore_x_randr_12.c.orig	2010-09-29 17:38:19.000000000 -0700
+++ src/lib/ecore_x/xlib/ecore_x_randr_12.c	2010-12-12 20:35:14.000000000 -0800
@@ -370,6 +370,32 @@
 #endif
 }
 
+static size_t
+strnlen_local(const char *s, size_t maxlen)
+{
+        size_t len;
+
+        for (len = 0; len < maxlen; len++, s++) {
+                if (!*s)
+                        break;
+        }
+        return (len);
+}
+
+static char *
+strndup_local(const char *str, size_t n)
+{
+        size_t len;
+        char *copy;
+
+        len = strnlen_local(str, n);
+        if ((copy = malloc(len + 1)) == NULL)
+                return (NULL);
+        memcpy(copy, str, len);
+        copy[len] = '\0';
+        return (copy);
+}
+
 /*
  * @brief get detailed information for a given mode id
  * @param root window which's screen's ressources are queried
@@ -405,7 +431,7 @@
                   ret->vSyncEnd = res->modes[i].vSyncEnd;
                   ret->vTotal = res->modes[i].vTotal;
                   if (!(ret->name =
-                           strndup(res->modes[i].name, res->modes[i].nameLength)))
+                           strndup_local(res->modes[i].name, res->modes[i].nameLength)))
                     {
                        ret->name = NULL;
                        ret->nameLength = 0;
