$FreeBSD$

--- modules/FvwmIconMan/FvwmIconMan.c.orig	Thu Oct 30 12:53:01 2003
+++ modules/FvwmIconMan/FvwmIconMan.c	Thu Oct 30 13:10:36 2003
@@ -315,6 +315,23 @@
     return copy_string (s1, s2);
 }
 
+#if __GNUC__ > 2
+#define SET_MANAGER(manager,field,value)                           \
+   do {                                                            \
+     int id = manager;                                             \
+     if (id == -1) {                                               \
+       for (id = 0; id < globals.num_managers; id++) {             \
+	 globals.managers[id].field = value;                     \
+       }                                                           \
+     }                                                             \
+     else if (id < globals.num_managers) {                         \
+       globals.managers[id].field = value;                       \
+     }                                                             \
+     else {                                                        \
+       ConsoleMessage ("Internal error in SET_MANAGER: %d\n", id); \
+     }                                                             \
+   } while (0)
+#else 
 #define SET_MANAGER(manager,field,value)                           \
    do {                                                            \
      int id = manager;                                             \
@@ -330,6 +347,7 @@
        ConsoleMessage ("Internal error in SET_MANAGER: %d\n", id); \
      }                                                             \
    } while (0)
+#endif /* GCC 2 */
 
 static void read_in_resources (char *file)
 {
