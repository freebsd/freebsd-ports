https://gitlab.gnome.org/GNOME/pangomm/-/commit/a8ab02ac9b96
https://gitlab.gnome.org/GNOME/pangomm/-/commit/c098f35144ff

attrlist.cc:38:20: error: use of undeclared identifier 'pango_parse_markup'
  gboolean bTest = pango_parse_markup(markup_text.c_str(), -1 /* means null-terminated */, accel_marker,
                   ^
attrlist.cc:65:20: error: use of undeclared identifier 'pango_parse_markup'
  gboolean bTest = pango_parse_markup(markup_text.c_str(), -1 /* means null-terminated */, accel_marker,
                   ^

--- pango/pangomm/attributes.h.orig	2016-08-19 13:58:37 UTC
+++ pango/pangomm/attributes.h
@@ -30,6 +30,9 @@
 #include <pangomm/color.h>
 #include <pangomm/fontdescription.h>
 #include <pango/pango-attributes.h>
+#if __has_include(<pango/pango-markup.h>)
+#include <pango/pango-markup.h>
+#endif
 #include <glibmm/slisthandle.h>
 
 
