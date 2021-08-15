--- src/Wnck.cpp.orig	2021-08-07 07:23:13 UTC
+++ src/Wnck.cpp
@@ -35,7 +35,7 @@ namespace Wnck
 				int nbr = read(fd, buffer, 512);
 				::close(fd);
 
-				char* exe = basename(buffer);
+				char* exe = g_path_get_basename(buffer);
 				if (strcmp(exe, "python") != 0) // ADDIT graphical interpreters here
 					return exe;
 
@@ -44,7 +44,7 @@ namespace Wnck
 					;
 
 				if (it < buffer + nbr)
-					return basename(it);
+					return g_path_get_basename(it);
 			}
 
 			// fallback : return window's name
