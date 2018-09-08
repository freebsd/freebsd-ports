Call 'setpwent' to rewind to the beginning of the passwd database.

--- src/greeter/UserModel.cpp.orig	2017-12-05 16:00:16 UTC
+++ src/greeter/UserModel.cpp
@@ -55,6 +55,7 @@ namespace SDDM {
         const QString defaultFace = QStringLiteral("file://%1/.face.icon").arg(facesDir);
 
         struct passwd *current_pw;
+        setpwent();
         while ((current_pw = getpwent()) != nullptr) {
 
             // skip entries with uids smaller than minimum uid
