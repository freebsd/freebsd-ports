
$FreeBSD$

--- sgmldocs.make	2002/01/22 14:14:55	1.1
+++ sgmldocs.make	2002/01/22 14:15:31
@@ -32,7 +32,7 @@
 #   dist-hook: app-dist-hook
 #
 
-docdir = $(datadir)/gnome/help/$(docname)/$(lang)
+docdir = $(datadir)/help/$(docname)/$(lang)
 
 doc_DATA = index.html
 
