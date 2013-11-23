--- invest-applet/invest/invest-applet.py.orig	2008-03-15 19:39:32.000000000 -0400
+++ invest-applet/invest/invest-applet.py	2008-04-28 13:27:46.000000000 -0400
@@ -26,8 +26,8 @@ import mate_invest, mate_invest.applet, mate_invest.def
 import gettext, locale
 gettext.bindtextdomain(mate_invest.defs.GETTEXT_PACKAGE, mate_invest.defs.MATELOCALEDIR)
 gettext.textdomain(mate_invest.defs.GETTEXT_PACKAGE)
-locale.bindtextdomain(mate_invest.defs.GETTEXT_PACKAGE, mate_invest.defs.MATELOCALEDIR)
-locale.textdomain(mate_invest.defs.GETTEXT_PACKAGE)
+#locale.bindtextdomain(mate_invest.defs.GETTEXT_PACKAGE, mate_invest.defs.MATELOCALEDIR)
+#locale.textdomain(mate_invest.defs.GETTEXT_PACKAGE)
 
 from gettext import gettext as _
 
