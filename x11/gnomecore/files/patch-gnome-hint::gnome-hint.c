
$FreeBSD$

--- gnome-hint/gnome-hint.c	2002/05/01 10:43:20	1.1
+++ gnome-hint/gnome-hint.c	2002/05/01 10:43:49
@@ -163,7 +163,7 @@
 	hintnum++;
 
 	/* see if we find the directory with the hints */
-	name = gnome_datadir_file ("gnome/hints");
+	name = gnome_datadir_file ("hints");
 	if (name == NULL)
 		return;
 	if (stat (name, &s) != 0 ||
