--- src/e_mod_main.c.orig	2014-09-23 14:36:23 UTC
+++ src/e_mod_main.c
@@ -422,11 +422,9 @@ _mem_cb_check (void *data)
 
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
