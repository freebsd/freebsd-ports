--- src/doc-generator.c.orig	Tue May 10 02:29:52 2005
+++ src/doc-generator.c	Tue May 10 02:30:23 2005
@@ -8,9 +8,10 @@
 
          
 static void output_range(xmlTextWriterPtr writer, GParamSpec *param) {
+  GType type;
   g_return_if_fail (writer != NULL);
   g_return_if_fail (param != NULL);
-  GType type = G_PARAM_SPEC_TYPE (param);
+  type = G_PARAM_SPEC_TYPE (param);
 #define OUTPUT_RANGE(t, T, format) \
        if (type == G_TYPE_PARAM_##T) { \
          GParamSpec##t *p = G_PARAM_SPEC_##T (param); \
