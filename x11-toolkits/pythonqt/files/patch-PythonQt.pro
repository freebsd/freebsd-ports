--- PythonQt.pro.orig	2026-06-05 12:41:07 UTC
+++ PythonQt.pro
@@ -2,7 +2,7 @@ TEMPLATE = subdirs
 
 # Define the full set of subdirectories, including the generator.
 # This list is used as the default build target.
-ALL_SUBDIRS = generator src extensions tests examples
+ALL_SUBDIRS = generator src extensions #tests examples
 
 tests.depends += src extensions
 extensions.depends += src
@@ -21,4 +21,4 @@ CONFIG(generator_only) {
 } else {
     # If neither special option is set, use the default build which includes everything.
     SUBDIRS = $$ALL_SUBDIRS
-}
\ No newline at end of file
+}
