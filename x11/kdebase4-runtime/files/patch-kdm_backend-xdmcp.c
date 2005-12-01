--- kdm/backend/xdmcp.c	2005/05/04 06:07:06	409205
+++ kdm/backend/xdmcp.c	2005/10/15 09:04:13	470797
@@ -940,7 +940,12 @@
 			}
 			DisposeProtoDisplay( pdpy );
 			Debug( "starting display %s,%s\n", d->name, d->class2 );
-			StartDisplay( d );
+			if (LoadDisplayResources( d ) < 0) {
+				LogError( "Unable to read configuration for display %s; "
+				          "stopping it.\n", d->name );
+				StopDisplay( d );
+			} else
+				StartDisplay( d );
 			CloseGetter();
 		}
 	}
