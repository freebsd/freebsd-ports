--- lumina-desktop/src-screensaver/LLockScreen.cpp.orig	2021-12-26 02:33:45 UTC
+++ lumina-desktop/src-screensaver/LLockScreen.cpp
@@ -79,7 +79,9 @@ void LLockScreen::TryUnlock(){
   this->setEnabled(false);
   QString pass = ui->line_password->text();
     ui->line_password->clear();
-  //Create a temporary file for the password, then pass that file descriptor to lumina-checkpass
+  // Create a temporary file for the password, then pass that file descriptor
+  // to lumina-checkpass. Might seem wacky to shell this out, but we need
+  // SUID to authenticate the pw with PAM.
   QTemporaryFile *TF = new QTemporaryFile(".XXXXXXXXXX");
   TF->setAutoRemove(true);
   bool ok = false;
@@ -90,7 +92,7 @@ void LLockScreen::TryUnlock(){
     if(DEBUG){ qDebug() << "Trying to unlock session:" << getlogin(); }
     LUtils::runCommand(ok, "lumina-checkpass",QStringList() << "-f" << TF->fileName() );
     if(DEBUG){ qDebug() << " - Success:" << ok; }
-    ok = true; //bypass for the moment
+    // ok = true; //bypass if lumina-checkpass is not working
   }
   delete TF; //ensure the temporary file is removed **right now** for security purposes
   if(ok){
