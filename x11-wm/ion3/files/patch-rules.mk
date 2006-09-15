--- ./rules.mk.orig	Thu Jul 29 00:10:32 2004
+++ ./rules.mk	Mon Jul 17 21:50:19 2006
@@ -91,6 +91,7 @@
 module_install:
 	$(INSTALLDIR) $(MODULEDIR)
 	$(LIBTOOL) --mode=install $(INSTALL) -s -m $(BIN_MODE) $(MODULE).la $(MODULEDIR)
+	$(INSTALL) -m $(BIN_MODE) $(MODULE).la $(MODULEDIR)
 
 clean_objs:
 	$(RM) -f $(OBJS)
