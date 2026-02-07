--- setup.py.orig	2019-06-23 16:14:24 UTC
+++ setup.py
@@ -23,9 +23,6 @@ exec(open(os.path.join(NAME, 'about.py')).read())
 VERSION = __version__
 
 extra = {}
-if sys.version_info >= (3,):
-    extra['use_2to3'] = True
-    extra['use_2to3_exclude_fixers'] = ['lib2to3.fixes.fix_import']
 
 classifiers = [
     # Get more strings from
