--- ./setup.py.orig	2011-12-11 00:33:12.000000000 +0100
+++ ./setup.py	2011-12-11 00:33:48.000000000 +0100
@@ -57,13 +57,6 @@
           ('share/glade3/catalogs', ['kiwiwidgets.xml']),
           ('$libdir/glade3/modules', ['kiwiwidgets.py']),
           ('share/glade3/pixmaps', pixmaps),
-          # Documentation
-          ('share/doc/kiwi',
-           ('AUTHORS', 'NEWS', 'README')),
-          ('share/doc/kiwi/howto',
-           listfiles('doc/howto/', '*')),
-          ('share/doc/kiwi/api',
-           listfiles('doc/api/', '*')),
       ],
       scripts=['bin/kiwi-i18n',
                'bin/kiwi-ui-test'],
