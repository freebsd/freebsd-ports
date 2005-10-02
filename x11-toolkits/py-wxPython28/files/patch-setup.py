--- setup.py.orig	Sat Apr 16 18:41:06 2005
+++ setup.py	Sat Oct  1 21:43:17 2005
@@ -764,6 +764,7 @@
     EXTRA_PATH = None
        
 
+EXTRA_PATH = getExtraPath(addOpts=EP_ADD_OPTS)
 
 #----------------------------------------------------------------------
 # Do the Setup/Build/Install/Whatever
