--- lib/libxview/panel/p_utl.c.orig	2005-03-28 06:40:39.000000000 -0800
+++ lib/libxview/panel/p_utl.c	2012-02-03 08:39:12.397932758 -0800
@@ -169,7 +169,7 @@
             xv_free(image_string_wc(dest));
     }
 #else
-#if !defined(__linux__) && !defined(__CYGWIN__)
+#if !defined(__linux__) && !defined(__CYGWIN__) && !defined(__FreeBSD__)
     {
         if (image_string(dest))
             xv_free(image_string(dest));
@@ -197,7 +197,7 @@
 	    value_str = "";
 	if (!(str = (char *) panel_strsave((u_char *) value_str)))
 	    return (size);
-#if defined(__linux__) || defined(__CYGWIN__)
+#if defined(__linux__) || defined(__CYGWIN__) || defined(__FreeBSD__)
 /* XView bug: This routine sometimes used a value that was already freed,
  * leading to clobbered menu items. The problem is the 
  * 'xv_free(image_string(dest))' above. In some cases the new 'value' 
