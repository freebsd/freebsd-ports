$FreeBSD$
--- setup.py	Tue Apr 25 17:09:29 2006
+++ setup.py.port	Tue Jun 20 13:35:48 2006
@@ -34,9 +34,6 @@
                              'kiwiwidgets', '*.png')),
                   (get_site_packages_dir('gazpacho', 'widgets'),
                    listfiles('gazpacho-plugin', 'kiwiwidgets.py')),
-                  ('share/doc/kiwi',
-                   ('AUTHORS', 'ChangeLog', 'NEWS', 'README')),
-                  ('$sysconfdir/kiwi', ['setup.py']),
                   ],
       scripts=['bin/kiwi-i18n',
                'bin/kiwi-ui-test'],
