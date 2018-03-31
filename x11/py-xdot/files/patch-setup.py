# https://github.com/jrfonseca/xdot.py/commit/3f866766be44adbe3634de95cd0a031e8a863c91

--- setup.py.orig	2018-03-30 00:51:44 UTC
+++ setup.py
@@ -31,7 +31,6 @@ setup(
         """,
     license="LGPL",
 
-    install_requires=['graphviz'],
     packages=['xdot', 'xdot/dot', 'xdot/ui'],
     entry_points=dict(gui_scripts=['xdot=xdot.__main__:main']),
 
