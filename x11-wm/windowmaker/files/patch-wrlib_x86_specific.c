--- wrlib/x86_specific.c   2004-10-31 02:44:01.000000000 +0100
+++ wrlib/x86_specific.c   2005-08-22 21:07:57.000000000 +0200
@@ -98,15 +98,23 @@
                            int height,
                            int line_offset)
 {
-    long long rrggbbaa;
-    long long pixel;
+    union {
+       long long rrggbbaa;
+       struct {short int rr, gg, bb, aa;} words;
+    } rrggbbaa;
+    
+    union {
+       long long pixel;
+       struct {short int rr, gg, bb, aa;} words;
+    } pixel;
+
     short *tmp_err;
     short *tmp_nerr;
     int x;
 
     asm volatile
         (
-         "pushal                        \n\t"
+         "pushl %%ebx                        \n\t"
 
          // pack dr, dg and db into mm6
          "movl  %7, %%eax               \n\t"
@@ -290,7 +298,7 @@
 
 ".Enda:                                 \n\t" // THE END
          "emms                          \n\t"
-         "popal                         \n\t"
+         "popl %%ebx                         \n\t"
          :
          :
          "m" (image),                      // %0
@@ -309,17 +317,18 @@
          "m" (width),                      // %13
          "m" (height),                     // %14
          "m" (line_offset),                // %15
-         "m" (rrggbbaa),                   // %16 (access to rr)
-         "m" ((*((short*)(&rrggbbaa)+1))), // %17 (access to gg)
-         "m" ((*((short*)(&rrggbbaa)+2))), // %18 (access to bb)
-         "m" ((*((short*)(&rrggbbaa)+3))), // %19 (access to aa)
-         "m" (pixel),                      // %20 (access to pixel.r)
-         "m" ((*((short*)(&pixel)+1))),    // %21 (access to pixel.g)
-         "m" ((*((short*)(&pixel)+2))),    // %22 (access to pixel.b)
-         "m" ((*((short*)(&pixel)+3))),    // %23 (access to pixel.a)
+         "m" (rrggbbaa.rrggbbaa),          // %16 (access to rr)
+         "m" (rrggbbaa.words.gg),          // %17 (access to gg)
+         "m" (rrggbbaa.words.bb),          // %18 (access to bb)
+         "m" (rrggbbaa.words.aa),          // %19 (access to aa)
+         "m" (pixel.pixel),                // %20 (access to pixel.r)
+         "m" (pixel.words.gg),             // %21 (access to pixel.g)
+         "m" (pixel.words.bb),             // %22 (access to pixel.b)
+         "m" (pixel.words.aa),             // %23 (access to pixel.a)
          "m" (tmp_err),                    // %24
          "m" (tmp_nerr),                   // %25
          "m" (x)                           // %26
+        : "eax", "ecx", "edx", "esi", "edi"
         );
 }
 
@@ -342,8 +351,15 @@
                            int height,
                            int line_offset)
 {
-    long long rrggbbaa;
-    long long pixel;
+    union {
+       long long rrggbbaa;
+       struct {short int rr, gg, bb, aa;} words;
+    } rrggbbaa;
+    
+    union {
+       long long pixel;
+       struct {short int rr, gg, bb, aa;} words;
+    } pixel;
 
     short *tmp_err;
     short *tmp_nerr;
@@ -354,7 +370,7 @@
 
     asm volatile
         (
-         "pushal                        \n\t"
+         "pushl %%ebx                        \n\t"
 
          "movl %13, %%eax               \n\t" // eax = width
          "movl %%eax, %%ebx             \n\t"
@@ -424,7 +440,7 @@
 
 ".Endc:                                 \n\t" // THE END
          "emms                          \n\t"
-         "popal                         \n\t"
+         "popl %%ebx                         \n\t"
          :
          :
          "m" (image),                      // %0
@@ -443,19 +459,20 @@
          "m" (width),                      // %13
          "m" (height),                     // %14
          "m" (line_offset),                // %15
-         "m" (rrggbbaa),                   // %16 (access to rr)
-         "m" ((*((short*)(&rrggbbaa)+1))), // %17 (access to gg)
-         "m" ((*((short*)(&rrggbbaa)+2))), // %18 (access to bb)
-         "m" ((*((short*)(&rrggbbaa)+3))), // %19 (access to aa)
-         "m" (pixel),                      // %20 (access to pixel.r)
-         "m" ((*((short*)(&pixel)+1))),    // %21 (access to pixel.g)
-         "m" ((*((short*)(&pixel)+2))),    // %22 (access to pixel.b)
-         "m" ((*((short*)(&pixel)+3))),    // %23 (access to pixel.a)
+         "m" (rrggbbaa.rrggbbaa),          // %16 (access to rr)
+         "m" (rrggbbaa.words.gg),          // %17 (access to gg)
+         "m" (rrggbbaa.words.bb),          // %18 (access to bb)
+         "m" (rrggbbaa.words.aa),          // %19 (access to aa)
+         "m" (pixel.pixel),                // %20 (access to pixel.r)
+         "m" (pixel.words.gg),             // %21 (access to pixel.g)
+         "m" (pixel.words.bb),             // %22 (access to pixel.b)
+         "m" (pixel.words.aa),             // %23 (access to pixel.a)
          "m" (tmp_err),                    // %24
          "m" (tmp_nerr),                   // %25
          "m" (x),                          // %26
          "m" (w1),                         // %27
          "m" (w2)                          // %28
+         : "eax", "ecx", "edx", "esi", "edi"
         );
 }
 
