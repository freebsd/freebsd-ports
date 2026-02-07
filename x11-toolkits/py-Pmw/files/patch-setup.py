--- setup.py.orig	2014-03-20 14:26:53 UTC
+++ setup.py
@@ -6,11 +6,6 @@ if sys.version_info[0]<3:
     version='2.0.1' # really '1.3.3'
     packages=['Pmw', 'Pmw.Pmw_1_3_3', 'Pmw.Pmw_1_3_3.lib',]
     package_data={'Pmw': ['Pmw_1_3_3/lib/Pmw.def',
-                        'Pmw_1_3_3/doc/*',
-                        'Pmw_1_3_3/contrib/*',
-                        'Pmw_1_3_3/demos/*',
-                        'Pmw_1_3_3/tests/*',
-                            'Pmw_1_3_3/bin/*',
                         ]
                     }
     development_status = 'Beta'
@@ -18,11 +13,6 @@ else:
     version='2.0.1'
     packages=['Pmw', 'Pmw.Pmw_2_0_1', 'Pmw.Pmw_2_0_1.lib',]
     package_data={'Pmw': ['Pmw_2_0_1/lib/Pmw.def',
-                            'Pmw_2_0_1/doc/*',
-                            'Pmw_2_0_1/contrib/*',
-                            'Pmw_2_0_1/demos/*',
-                            'Pmw_2_0_1/tests/*',
-                            'Pmw_2_0_1/bin/*',
                             ],
                     }
     development_status = 'Alpha'
