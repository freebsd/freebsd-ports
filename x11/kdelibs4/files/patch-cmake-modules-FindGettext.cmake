--- ../cmake/modules/FindGettext.cmake.orig	2008-07-11 18:32:43.000000000 +0200
+++ ../cmake/modules/FindGettext.cmake	2008-07-11 18:32:58.000000000 +0200
@@ -26,13 +26,12 @@
   include(CheckIncludeFiles)
   include(CheckLibraryExists)
   include(CheckFunctionExists)
-  
-  check_include_files(libintl.h HAVE_LIBINTL_H)
-  
-  set(GETTEXT_INCLUDE_DIR)
+
+  FIND_PATH(GETTEXT_INCLUDE_DIR libintl.h)
   set(GETTEXT_LIBRARIES)
   
-  if (HAVE_LIBINTL_H)
+  if (GETTEXT_INCLUDE_DIR)
+     set(HAVE_LIBINTL_H TRUE)
      check_function_exists(dgettext LIBC_HAS_DGETTEXT)
      if (LIBC_HAS_DGETTEXT)
         set(GETTEXT_SOURCE "built in libc")
@@ -47,7 +46,7 @@
            set(GETTEXT_FOUND TRUE)
         endif (LIBINTL_HAS_DGETTEXT)
      endif (LIBC_HAS_DGETTEXT)
-  endif (HAVE_LIBINTL_H)
+  endif (GETTEXT_INCLUDE_DIR)
   
   if (GETTEXT_FOUND)
      if (NOT Gettext_FIND_QUIETLY)
