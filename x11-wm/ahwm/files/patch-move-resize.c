--- move-resize.c.orig	Sun Feb 17 04:58:21 2002
+++ move-resize.c	Fri Aug  6 21:39:09 2004
@@ -794,7 +794,8 @@
                                 x_start = client->x + client->width;
                                 y_start = client->y + client->height;
                                 break;
-                            default: /* shuts up compiler warning */
+                            default:
+                                ; /* shuts up compiler warning */
                         }
                     }
                     xrefresh();
@@ -1056,6 +1057,7 @@
             *old = WEST;
             break;
         default:
+            ;
     }
 }
 
@@ -1200,6 +1202,7 @@
                 }
                 break;
             default:
+                ;
         }
     }
     
@@ -1236,6 +1239,7 @@
                 }
                 break;
             default:
+                ;
         }
     }
     
