--- epplets/load.c.orig	2008-01-24 15:26:46.000000000 +0100
+++ epplets/load.c	2008-01-24 16:07:37.000000000 +0100
@@ -1,5 +1,6 @@
 /*
  * Copyright (C) 1999-2000, Michael Jennings
+ *               2008, Pietro Cerutti <gahr@FreeBSD.org> (FreeBSD adaptation)
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to
@@ -38,6 +39,10 @@
 #include <errno.h>
 #include <unistd.h>
 
+#ifdef __FreeBSD__
+#include <stdlib.h> /* getloadavg(3) */
+#endif
+
 #if 0
 #  define D(x) do {printf("%10s | %7d:  [debug] ", __FILE__, __LINE__); printf x; fflush(stdout);} while (0)
 #else
@@ -99,9 +104,15 @@
    sscanf(buff, "%lf %lf %lf", &a, &b, &c);
    SET_AND_RETURN(a, b, c);
 }
-
+#elif defined(__FreeBSD__)
+void
+get_load_average(double *one, double *five, double *fifteen)
+{
+   double load[3];
+   getloadavg(load, 3);
+   SET_AND_RETURN(load[0], load[1], load[2]);
+}
 #else
-/* A generic fallback that should work just about anywhere. */
 void
 get_load_average(double *one, double *five, double *fifteen)
 {
