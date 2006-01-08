--- khtml/ecma/kjs_window.cpp	2005/11/11 21:07:48	479809
+++ khtml/ecma/kjs_window.cpp	2005/11/25 18:54:04	483261
@@ -21,6 +21,16 @@
  */
 #include "config.h"
 
+#include "khtmlview.h"
+#include "khtml_part.h"
+#include "khtmlpart_p.h"
+#include "khtml_settings.h"
+#include "xml/dom2_eventsimpl.h"
+#include "xml/dom_docimpl.h"
+#include "misc/htmltags.h"
+#include "html/html_documentimpl.h"
+#include "rendering/render_frames.h"
+
 #include <qstylesheet.h>
 #include <qtimer.h>
 #include <qpaintdevicemetrics.h>
@@ -60,16 +70,6 @@
 #include "xmlserializer.h"
 #include "domparser.h"
 
-#include "khtmlview.h"
-#include "khtml_part.h"
-#include "khtmlpart_p.h"
-#include "khtml_settings.h"
-#include "xml/dom2_eventsimpl.h"
-#include "xml/dom_docimpl.h"
-#include "misc/htmltags.h"
-#include "html/html_documentimpl.h"
-#include "rendering/render_frames.h"
-
 using namespace KJS;
 
 namespace KJS {
