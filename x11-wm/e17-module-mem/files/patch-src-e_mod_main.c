diff -ur src.old/e_mod_main.c src/e_mod_main.c
--- src.old/e_mod_main.c	2010-11-13 17:56:21.000000000 +0200
+++ src/e_mod_main.c	2012-02-21 23:43:46.548797357 +0200
@@ -424,11 +424,9 @@
 
    if (!inst->ci->show_percent)
      {
-	snprintf (real_str, sizeof (real_str), "Real: %d/%d MB", (real / 1024),
-		  (total_real / 1024));
+	snprintf (real_str, sizeof (real_str), "Real: %d/%d MB", real, total_real);
 	if ( total_swap )
-	  snprintf (swap_str, sizeof (swap_str), "Swap: %d/%d MB", (swap / 1024),
-		    (total_swap / 1024));
+	  snprintf (swap_str, sizeof (swap_str), "Swap: %d/%d MB", swap, total_swap);
      }
    else
      {
