--- prefs.c.orig	Sun Feb 24 16:31:27 2002
+++ prefs.c	Fri Aug  6 21:36:57 2004
@@ -642,7 +642,7 @@
                 mouseunbinding_apply(client, lp->line_value.mouseunbinding);
                 break;
             default:
-                /* nothing */
+                ; /* nothing */
         }
     }
 }
@@ -839,7 +839,7 @@
             p->raise_delay_set = opt->option_setting;
             break;
         default:
-            /* nothing */
+            ; /* nothing */
     }
 }
 
