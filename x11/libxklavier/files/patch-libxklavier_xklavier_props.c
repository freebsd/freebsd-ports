--- libxklavier/xklavier_props.c.orig	Mon Apr  3 14:49:17 2006
+++ libxklavier/xklavier_props.c	Mon Apr  3 17:16:13 2006
@@ -319,7 +324,9 @@ Bool XklGetNamesProp( Atom rulesAtom,
             memcpy( var, varstart + 1, --varlen );
             var[varlen] = '\0';
             
-            ( (char*)realloc( *theLayout, laylen + 1 ) )[laylen] = '\0';
+            *theLayout = realloc (*theLayout, laylen + 1);
+            (*theLayout)[laylen] = '\0';
+            /*( (char*)realloc( *theLayout, laylen + 1 ) )[laylen] = '\0';*/
           }
         }
       }
