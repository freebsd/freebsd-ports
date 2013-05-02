--- WindowMaker/plmenu.es.orig	2013-05-03 03:12:25.000000000 +0900
+++ WindowMaker/plmenu.es	2013-05-03 03:12:17.000000000 +0900
@@ -23,7 +23,7 @@
   ("LyX", EXEC, "lyx"),
   ("Netscape", EXEC, "netscape"),
   ("Ghostview", EXEC, "ghostview %a(Escribe el archivo que desees ver:)"),
-  ("Acrobat", EXEC, "/usr/local/Acrobat3/bin/acroread %a(Escribe el archivo PDF que desees ver:)"),
+  ("Acrobat", EXEC, PREFIX "/Acrobat3/bin/acroread %a(Escribe el archivo PDF que desees ver:)"),
   ("TkDesk", EXEC, "tkdesk")
   ),
  ("Editores",
@@ -66,9 +66,9 @@
   ("Borrar sesion", CLEAR_SESSION)
   ),
  ("Apariencia",
-  ("Temas", OPEN_MENU, "-noext /usr/local/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes WITH setstyle"),
-  ("Estilos", OPEN_MENU, "-noext /usr/local/share/WindowMaker/Styles $HOME/GNUstep/Library/WindowMaker/Styles WITH setstyle"),
-  ("Grupos de iconos", OPEN_MENU, "-noext /usr/local/share/WindowMaker/IconSets $HOME/GNUstep/Library/WindowMaker/IconSets WITH seticons"),
+  ("Temas", OPEN_MENU, "-noext "PREFIX "/share/WindowMaker/Themes $HOME/GNUstep/Library/WindowMaker/Themes WITH setstyle"),
+  ("Estilos", OPEN_MENU, "-noext "PREFIX "/share/WindowMaker/Styles $HOME/GNUstep/Library/WindowMaker/Styles WITH setstyle"),
+  ("Grupos de iconos", OPEN_MENU, "-noext "PREFIX "/share/WindowMaker/IconSets $HOME/GNUstep/Library/WindowMaker/IconSets WITH seticons"),
   ("Papel Tapiz",
    ("Solido",
     ("Negro", EXEC, "wdwrite WindowMaker WorkspaceBack '(solid, black)'"),
@@ -90,11 +90,11 @@
     ("Sombras grises",   EXEC, "wdwrite WindowMaker WorkspaceBack '(vgradient, \"#636380\", \"#131318\")'"),
     ("Sombras vino",   EXEC, "wdwrite WindowMaker WorkspaceBack '(vgradient, \"#600040\", \"#180010\")'")
     ),
-   ("Imagenes", OPEN_MENU, "-noext /usr/local/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds WITH wmsetbg -u -t")
+   ("Imagenes", OPEN_MENU, "-noext "PREFIX "/share/WindowMaker/Backgrounds $HOME/GNUstep/Library/WindowMaker/Backgrounds WITH wmsetbg -u -t")
    ),   
   ("Guardar tema", SHEXEC, "getstyle -t $HOME/GNUstep/Library/WindowMaker/Themes/\"%a(Theme name)\""),
   ("Guardar iconos", SHEXEC, "geticonset $HOME/GNUstep/Library/WindowMaker/IconSets/\"%a(IconSet name)\""),
-  ("Preferencias", EXEC, "/usr/local/GNUstep/Applications/WPrefs.app/WPrefs")
+  ("Preferencias", EXEC, PREFIX "/GNUstep/Applications/WPrefs.app/WPrefs")
   ), 
  ("Salir",
   ("Reiniciar", RESTART),
