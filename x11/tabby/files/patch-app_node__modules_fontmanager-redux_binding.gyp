--- app/node_modules/fontmanager-redux/binding.gyp.orig	2026-11-07 14:58:12 UTC
+++ app/node_modules/fontmanager-redux/binding.gyp
@@ -37,6 +37,13 @@
           "sources": ["src/FontManagerLinux.cc"],
           "link_settings": {
             "libraries": ["-lfontconfig"]
+          }
+        }],
+        ['OS=="freebsd"', {
+          "sources": ["src/FontManagerLinux.cc"],
+          "include_dirs": ["<!@(pkg-config --cflags-only-I fontconfig | sed -e s/-I//g)"],
+          "link_settings": {
+            "libraries": ["<!@(pkg-config --libs fontconfig)"]
           }
         }]
       ]
