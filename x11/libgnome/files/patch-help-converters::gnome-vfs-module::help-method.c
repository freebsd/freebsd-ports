
$FreeBSD$

--- help-converters/gnome-vfs-module/help-method.c.orig	Sat Jan 26 17:43:22 2002
+++ help-converters/gnome-vfs-module/help-method.c	Wed Feb 20 20:01:17 2002
@@ -371,7 +371,7 @@
                 else
                         buf = g_strdup_printf ("gnome/help/%s/%s/%s", base_name, lang, old_uri);
 
-		new_uri = g_strdup_printf ("/usr/share/%s", buf);
+		new_uri = g_strdup_printf (PREFIX "/share/%s", buf);
 /*  gnome_unconditional_datadir_file (buf); */
 		g_free (buf);
 
@@ -394,7 +394,7 @@
                                         
                                         old_help = g_strdup_printf ("gnome/help/%s/%s/index.html", base_name, lang);
                                         new_uri_with_extension = 
-                                                g_strdup_printf ("/usr/share/%s",
+                                                g_strdup_printf (PREFIX "/share/%s",
                                                                  old_help);
                                       
 /* gnome_unconditional_datadir_file (old_help); */
@@ -530,10 +530,10 @@
         int i;
 
         /* Check some hardcoded locations. */
-        if (strncmp (file, "/usr/info/", strlen ("/usr/info/")) == 0 ||
-            strncmp (file, "/usr/local/info/", strlen ("/usr/local/info/")) ||
-            strncmp (file, "/usr/gnome/info/", strlen ("/usr/gnome/info/")) ||
-	    strncmp (file, "/usr/share/info/", strlen ("/usr/share/info/"))) {
+        if (strncmp (file, "/usr/share/info/", strlen ("/usr/share/info/")) == 0 ||
+            strncmp (file, LOCALBASE "/info/", strlen (LOCALBASE "/info/")) ||
+            strncmp (file, X11BASE "/info/", strlen (X11BASE "/info/")) || 
+	    strncmp (file, PREFIX "/info/", strlen (PREFIX "/info/"))) {
                 return TRUE;
         }
 
