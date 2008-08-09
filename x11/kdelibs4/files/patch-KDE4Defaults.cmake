--- ../cmake/modules/KDE4Defaults.cmake.orig	2008-05-21 13:06:10.000000000 +0200
+++ ../cmake/modules/KDE4Defaults.cmake	2008-05-27 18:51:10.000000000 +0200
@@ -29,11 +29,11 @@
 
 # define the generic version of the libraries here
 # this makes it easy to advance it when the next KDE release comes
-set(GENERIC_LIB_VERSION "4.1.0")
-set(GENERIC_LIB_SOVERSION "4")
+set(GENERIC_LIB_VERSION "5.0.0")
+set(GENERIC_LIB_SOVERSION "5")
 
-set(KDE_NON_GENERIC_LIB_VERSION "5.1.0")
-set(KDE_NON_GENERIC_LIB_SOVERSION "5")
+set(KDE_NON_GENERIC_LIB_VERSION "7.0.0")
+set(KDE_NON_GENERIC_LIB_SOVERSION "7")
 
 # windows does not support LD_LIBRARY_PATH or similar
 # all searchable directories has to be defined by the PATH environment var
