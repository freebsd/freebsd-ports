--- src/ssgAux/ssgaSky.h.orig	Fri Apr  6 03:58:33 2007
+++ src/ssgAux/ssgaSky.h	Fri Apr  6 03:58:45 2007
@@ -104,7 +104,7 @@
   ssgaCelestialBodyList ( int init = 3 )
 	  : ssgSimpleList ( sizeof(ssgaCelestialBody*), init ) { }
 
-  ssgaCelestialBodyList::~ssgaCelestialBodyList () { removeAll(); }
+  ~ssgaCelestialBodyList () { removeAll(); }
 
   int getNum (void) { return total ; }
 
@@ -192,7 +192,7 @@
   ssgaCloudLayerList ( int init = 3 )
 	  : ssgSimpleList ( sizeof(ssgaCloudLayer*), init ) { }
 
-  ssgaCloudLayerList::~ssgaCloudLayerList () { removeAll(); }
+  ~ssgaCloudLayerList () { removeAll(); }
 
   int getNum (void) { return total ; }
 
