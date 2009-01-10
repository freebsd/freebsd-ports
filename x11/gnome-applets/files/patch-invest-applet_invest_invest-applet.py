--- invest-applet/invest/invest-applet.py.orig	2008-03-15 19:39:32.000000000 -0400
+++ invest-applet/invest/invest-applet.py	2008-04-28 13:27:46.000000000 -0400
@@ -26,8 +26,8 @@ import invest, invest.applet, invest.def
 import gettext, locale
 gettext.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
 gettext.textdomain(invest.defs.GETTEXT_PACKAGE)
-locale.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
-locale.textdomain(invest.defs.GETTEXT_PACKAGE)
+#locale.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
+#locale.textdomain(invest.defs.GETTEXT_PACKAGE)
 
 from gettext import gettext as _
 
