--- invest-applet/invest/invest-applet.py.orig	Wed Sep 13 20:42:15 2006
+++ invest-applet/invest/invest-applet.py	Wed Sep 13 20:42:28 2006
@@ -26,8 +26,8 @@ import invest, invest.applet, invest.def
 import gettext, locale
 gettext.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
 gettext.textdomain(invest.defs.GETTEXT_PACKAGE)
-locale.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
-locale.textdomain(invest.defs.GETTEXT_PACKAGE)
+#locale.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
+#locale.textdomain(invest.defs.GETTEXT_PACKAGE)
 gtk.glade.bindtextdomain(invest.defs.GETTEXT_PACKAGE, invest.defs.GNOMELOCALEDIR)
 gtk.glade.textdomain(invest.defs.GETTEXT_PACKAGE)
 
