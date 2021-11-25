Fix build against llvm13

Obtained from:
	https://invent.kde.org/utilities/konsole/-/commit/1defe4f6c19c1c255b20bb56be64a7199048429f

--- src/widgets/EditProfileDialog.cpp.orig	2021-11-25 09:02:00 UTC
+++ src/widgets/EditProfileDialog.cpp
@@ -1702,7 +1702,7 @@ void EditProfileDialog::setupMousePage(const Profile::
 
 void EditProfileDialog::setTextEditorCombo(const Profile::Ptr &profile)
 {
-    std::array<Enum::TextEditorCmd, 7> editorsList = { Enum::Kate, Enum::KWrite,
+    static const Enum::TextEditorCmd editorsList[] = { Enum::Kate, Enum::KWrite,
                                                        Enum::KDevelop, Enum::QtCreator,
                                                        Enum::Gedit, Enum::gVim,
                                                        Enum::CustomTextEditor };
