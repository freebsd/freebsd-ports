--- rules.mk	Wed Apr  7 09:15:54 2004
+++ rules.mk.bsd	Sun Apr 11 12:55:10 2004
@@ -91,6 +91,7 @@
 module_install:
 	$(INSTALLDIR) $(MODULEDIR)
 	$(LIBTOOL) --mode=install $(INSTALL) -s -m $(BIN_MODE) $(MODULE).la $(MODULEDIR)
+	$(INSTALL) -m $(BIN_MODE) $(MODULE).la $(MODULEDIR)
 
 clean_objs:
 	$(RM) -f $(OBJS)
