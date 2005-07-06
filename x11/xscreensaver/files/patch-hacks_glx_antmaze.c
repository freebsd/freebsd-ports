--- hacks/glx/antmaze.c.orig	Sun Jun 26 16:22:35 2005
+++ hacks/glx/antmaze.c	Sun Jun 26 16:26:02 2005
@@ -975,6 +975,7 @@ void update_ants(void) {
 
   /* fade out */
   if(fadeoutspeed < -0.00001) {
+    GLfloat df[4];
 
     if(fadeout <= 0.0) {
       /* switch boards: rebuild old board, increment current */
@@ -985,20 +986,27 @@ void update_ants(void) {
     
     fadeout += fadeoutspeed;
 
-    GLfloat df[4] = {0.8*fadeout, 0.8*fadeout, 0.8*fadeout, 1.0};
+    df[0] = 0.8*fadeout;
+    df[1] = 0.8*fadeout;
+    df[2] = 0.8*fadeout;
+    df[3] = 1.0;
     glLightfv(GL_LIGHT0, GL_DIFFUSE, df);
     glLightfv(GL_LIGHT1, GL_DIFFUSE, df);
   }
 
   /* fade in */
   if(fadeoutspeed > 0.0001) {
+    GLfloat df[4];
     fadeout += fadeoutspeed;
     if(fadeout >= 1.0) {
       fadeout = 1.0;
       fadeoutspeed = 0.0;
       entroducing = 12;
     }
-    GLfloat df[4] = {0.8*fadeout, 0.8*fadeout, 0.8*fadeout, 1.0};
+    df[0] = 0.8*fadeout;
+    df[1] = 0.8*fadeout;
+    df[2] = 0.8*fadeout;
+    df[3] = 1.0;
     glLightfv(GL_LIGHT0, GL_DIFFUSE, df);
     glLightfv(GL_LIGHT1, GL_DIFFUSE, df);    
   }
@@ -1160,6 +1168,7 @@ void update_ants(void) {
       double dx = antpath[i][part[i]][0] - antposition[i][0];
       double dz = - antpath[i][part[i]][1] + antposition[i][1];
       double theta, ideal;
+      double dt;
 
       if(dz > EPSILON)
 	theta = atan(dz/dx);
@@ -1171,7 +1180,7 @@ void update_ants(void) {
 	ideal += Pi;
 
       /* compute correction */
-      double dt = sign(ideal) * min(fabs(ideal), PI/90.0);
+      dt = sign(ideal) * min(fabs(ideal), PI/90.0);
       antdirection[i] += dt;
       if(antdirection[i] > 2.0*PI)
 	antdirection[i] = 0.0;
