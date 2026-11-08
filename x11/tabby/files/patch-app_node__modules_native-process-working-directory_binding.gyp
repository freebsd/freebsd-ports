--- app/node_modules/native-process-working-directory/binding.gyp.orig	2026-11-07 14:58:12 UTC
+++ app/node_modules/native-process-working-directory/binding.gyp
@@ -19,6 +19,18 @@
                         'src/darwin.cc'
                     ],
                 }],
+                ['OS=="freebsd"', {
+                    'include_dirs': [
+                        "<!@(node -p \"require('node-addon-api').include\")",
+                    ],
+                    'cflags_cc': [
+                        '-DNAPI_DISABLE_CPP_EXCEPTIONS',
+                        '-Wall',
+                    ],
+                    'sources': [
+                        'src/freebsd.cc'
+                    ],
+                }],
                 ['OS=="win"', {
                     'defines': ['UNICODE'],
                     'include_dirs': [
