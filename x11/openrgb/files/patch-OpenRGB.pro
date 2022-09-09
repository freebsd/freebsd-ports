--- OpenRGB.pro.orig	2022-05-05 02:48:58 UTC
+++ OpenRGB.pro
@@ -40,7 +40,7 @@ TEMPLATE    = app
 # Automatically generated build information                                                     #
 #-----------------------------------------------------------------------------------------------#
 win32:BUILDDATE = $$system(date /t)
-unix:BUILDDATE  = $$system(date -R -d "@${SOURCE_DATE_EPOCH:-$(date +%s)}")
+unix:BUILDDATE  = $$system(date -R)
 GIT_COMMIT_ID   = $$system(git --git-dir $$_PRO_FILE_PWD_/.git --work-tree $$_PRO_FILE_PWD_ rev-parse HEAD)
 GIT_COMMIT_DATE = $$system(git --git-dir $$_PRO_FILE_PWD_/.git --work-tree $$_PRO_FILE_PWD_ show -s --format=%ci HEAD)
 GIT_BRANCH      = $$system(git --git-dir $$_PRO_FILE_PWD_/.git --work-tree $$_PRO_FILE_PWD_ rev-parse --abbrev-ref HEAD)
