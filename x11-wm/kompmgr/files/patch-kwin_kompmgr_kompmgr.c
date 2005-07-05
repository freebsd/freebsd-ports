--- kwin/kompmgr/kompmgr.c.orig	Tue Jul  5 16:23:25 2005
+++ kwin/kompmgr/kompmgr.c	Tue Jul  5 16:25:43 2005
@@ -1807,6 +1807,7 @@
 {
 	win				*new = malloc (sizeof (win));
 	win				**p;
+	unsigned int 			tmp;
 
 	if (!new)
 		return;
@@ -1867,7 +1868,7 @@
 	new->shadowSize = get_shadow_prop (dpy, new);
 	new->shapable = get_shapable_prop(dpy, new);
 	new->titleHeight = get_titleHeight_prop(dpy, new);
-        unsigned int tmp = get_dim_prop(dpy, new);
+        tmp = get_dim_prop(dpy, new);
         new->dimPicture = (tmp < OPAQUE) ? solid_picture (dpy, True, (double)tmp/OPAQUE, 0.1, 0.1, 0.1) : None;
 	new->windowType = determine_wintype (dpy, new->id);
         determine_mode (dpy, new);
@@ -2411,7 +2411,7 @@
 		const char *home = getenv("HOME");
 		const char *configfile = "/.xcompmgrrc"; 
         wasNull = True;
-		filename = (char*)malloc((strlen(home)+strlen(configfile)+1)*sizeof(char));
+		filename = (char*)calloc((strlen(home)+strlen(configfile)+1), sizeof(char));
 
 		strcat(filename, home);
 		strcat(filename, configfile);
