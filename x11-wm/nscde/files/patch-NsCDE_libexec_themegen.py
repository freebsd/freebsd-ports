--- NsCDE/libexec/themegen.py.orig	2021-05-02 13:42:24 UTC
+++ NsCDE/libexec/themegen.py
@@ -10,12 +10,7 @@ import os
 import sys
 import shutil
 
-nscde_root = os.environ.get('NSCDE_ROOT')
-if not nscde_root:
-   sys.stderr.write("NSCDE_ROOT not set. Stop.\n")
-   sys.exit(1)
-else:
-   sys.path.append(nscde_root + "/lib/python")
+sys.path.append("${PREFIX}/lib/nscde/python")
 
 themegen="""
 For this script to work you need to install the Python 3
@@ -46,7 +41,7 @@ Usage:
 
 Arguments:
     Palette name or file path
-    CDE color palettes, are located in NSCDE_ROOT/share/palettes
+    CDE color palettes, are located in ${PREFIX}/share/nscde/palettes
     or in $HOME/.NsCDE/palettes
 
     Number of colors: 8 or 4
@@ -93,8 +88,8 @@ nscdetheme = "NsCDE"
 
 if os.path.exists(userhome + "/.NsCDE/palettes/" + palettefile + ".dp"):
     opts.currentpalettefile=(userhome + "/.NsCDE/palettes/" + palettefile + ".dp")
-elif os.path.exists(nscde_root + "/share/palettes/" + palettefile + ".dp"):
-    opts.currentpalettefile=(nscde_root + "/share/palettes/" + palettefile + ".dp")
+elif os.path.exists("${PREFIX}/share/nscde/palettes/" + palettefile + ".dp"):
+    opts.currentpalettefile=("${PREFIX}/share/nscde/palettes/" + palettefile + ".dp")
 elif os.path.exists(palettefile):
     opts.currentpalettefile=palettefile
     # nscdetheme="NsCDE-" + os.path.basename(nscdetheme.replace(".dp", ""))
@@ -102,7 +97,7 @@ else:
     print ('Palette not found: ' + palettefile)
     sys.exit()
 
-Globals.themedir=nscde_root + "/share/config_templates/integration/gtk2_gtk3_qt"
+Globals.themedir="${PREFIX}/share/nscde/config_templates/integration/gtk2_gtk3_qt"
 Globals.userthemedir=os.path.join(userhome,'.themes',nscdetheme)
 Globals.themesrcdir=Globals.themedir
 Globals.palettedir=os.path.join(Globals.themedir,'palettes')
