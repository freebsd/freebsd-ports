--- vdkbuilder/vdkb_templates.cc.orig	Tue Jun  4 16:56:35 2002
+++ vdkbuilder/vdkb_templates.cc	Tue Nov 18 11:13:16 2003
@@ -873,7 +873,7 @@
 \n$(TARGET): $(OBJECTS)\
 \n\t$(LINK)  -o $(TARGET) $(OBJECTS) $(OTHERS_OBJECTS) $(LIBS)\
 \n\
-\n####### Running (used by builder)
+\n####### Running (used by builder)\
 \nrun: $(TARGET)\
 \n\tcd %s\
 \n\t%s $(PRG_ARGS)\
