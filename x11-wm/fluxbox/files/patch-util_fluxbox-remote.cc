Upstream fix for bogus pointer comparison:
Issue:  https://sourceforge.net/p/fluxbox/bugs/1138/ 
Commit: http://git.fluxbox.org/fluxbox.git/commit/util/fluxbox-remote.cc?id=22866c4d30f5b289c429c5ca88d800200db4fc4f

--- util/fluxbox-remote.cc.orig	2015-02-08 10:44:45 UTC
+++ util/fluxbox-remote.cc
@@ -73,7 +73,7 @@ int main(int argc, char **argv) {
     if (strcmp(cmd, "result") == 0) {
         XTextProperty text_prop;
         if (XGetTextProperty(disp, root, &text_prop, atom_result) != 0
-            && text_prop.value > 0
+            && text_prop.value != 0
             && text_prop.nitems > 0) {
 
             printf("%s", text_prop.value);
