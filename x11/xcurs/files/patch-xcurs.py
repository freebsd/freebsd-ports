--- xcurs.py.orig	Wed Sep  1 03:50:28 2004
+++ xcurs.py	Mon Dec 27 11:24:46 2004
@@ -1,6 +1,10 @@
 #!/usr/bin/python -OO
 
-import sys, re
+import os, sys, re
+
+prefix = os.path.split(os.path.dirname(sys.argv[0]))[0]
+sys.path.append(os.path.join(prefix, 'lib', 'xcurs'))
+
 import pygtk
 pygtk.require('2.0')
 import gtk.glade
@@ -8,7 +12,7 @@
 import gladew
 import Image
 
-import os, new, types
+import new, types
 
 # for  xcurs
 # import parsexcursor
