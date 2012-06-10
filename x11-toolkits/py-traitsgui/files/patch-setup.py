--- ./setup.py.orig	2012-06-10 20:44:25.000000000 +1000
+++ ./setup.py	2012-06-10 20:45:54.000000000 +1000
@@ -107,7 +107,6 @@
         },
     packages = find_packages(),
     platforms = ["Windows", "Linux", "Mac OS-X", "Unix", "Solaris"],
-    setup_requires = 'setupdocs>=1.0',
     tests_require = [
         'nose >= 0.10.3',
         ],
