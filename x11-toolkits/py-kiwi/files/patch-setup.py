--- setup.py	Fri Sep 15 18:39:09 2006
+++ setup.py.port	Wed Nov  8 21:41:48 2006
@@ -34,12 +34,6 @@
                              'kiwiwidgets', '*.png')),
                   (get_site_packages_dir('gazpacho', 'widgets'),
                    listfiles('gazpacho-plugin', 'kiwiwidgets.py')),
-                  ('share/doc/kiwi',
-                   ('AUTHORS', 'ChangeLog', 'NEWS', 'README')),
-                  ('share/doc/kiwi/howto',
-                   listfiles('doc/howto/', '*')),
-                  ('share/doc/kiwi/api',
-                   listfiles('doc/api/', '*')),
                   ],
       scripts=['bin/kiwi-i18n',
                'bin/kiwi-ui-test'],
