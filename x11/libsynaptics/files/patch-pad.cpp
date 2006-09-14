--- pad.cpp.orig	Thu Sep 14 13:51:00 2006
+++ pad.cpp	Thu Sep 14 13:53:35 2006
@@ -15,12 +15,14 @@
 #include "version.h"
 
 #include <X11/Xdefs.h> // for typedef Bool
+#include <sys/types.h>
 #include <sys/shm.h>
 #include <stdlib.h>
+#include <stdio.h>
 #include <unistd.h>
 
 #include <pthread.h>
-static pthread_mutex_t lock;
+static pthread_mutex_t mylock;
 
 #define PAROFF( verId, par ) \
     offsetof( SynShm, verId ) + offsetof( ShmSegment##verId, par )
@@ -32,7 +34,7 @@
     p.max_val = max;
 
 #define NODRIVERVER VER( 0, 0, 0 )
-#define RETURN( val ) pthread_mutex_unlock( &lock ); return ( val )
+#define RETURN( val ) pthread_mutex_unlock( &mylock ); return ( val )
 
 
 //
@@ -82,7 +84,7 @@
         mSelf = new Synaptics::Pad(); // call constructor
     else
     {
-        pthread_mutex_lock( &lock );
+        pthread_mutex_lock( &mylock );
         return;
     }
 
@@ -333,7 +335,7 @@
     PadType pt = PT_NONE;
 
     // FIXME: detection just based on the assumption that the driver will register as unknown
-    if ( mHasShm and mDetectedDriver == DV_UNKNOWN )
+    if ( mHasShm && mDetectedDriver == DV_UNKNOWN )
         pt = PT_UNKNOWN;
     else
     {
@@ -368,19 +370,19 @@
     {
         Param p = mSupportedDriver[ DRIVERSTR ][ param ];
 
-        if ( ( p.type == PT_BOOL ) or ( p.type == PT_BOOL_RO ) )
+        if ( ( p.type == PT_BOOL ) || ( p.type == PT_BOOL_RO ) )
         {
             rb = *(Bool*)(((char*)mSynShm) + p.offset );
             RETURN( rb );
         }
 
-        if ( ( p.type == PT_INT ) or ( p.type == PT_INT_RO ) )
+        if ( ( p.type == PT_INT ) || ( p.type == PT_INT_RO ) )
         {
             ri = *(int*)(((char*)mSynShm) + p.offset );
             RETURN( ri );
         }
 
-        if ( ( p.type == PT_DOUBLE ) or ( p.type == PT_DOUBLE_RO ) )
+        if ( ( p.type == PT_DOUBLE ) || ( p.type == PT_DOUBLE_RO ) )
         {
             rd = *(double*)(((char*)mSynShm) + p.offset );
             RETURN( rd );
@@ -399,7 +401,7 @@
     {
         Param p = mSupportedDriver[ DRIVERSTR ][ param ];
 
-        if ( ( p.min_val <= v ) and ( p.max_val >= v ) )
+        if ( ( p.min_val <= v ) && ( p.max_val >= v ) )
         {
             if ( p.type == PT_BOOL )
                 (*(Bool*)(((char*)mSynShm) + p.offset)) = (Bool)v;
@@ -414,7 +416,7 @@
         }
     }
     // instead of RETURN(void)
-    pthread_mutex_unlock( &lock );
+    pthread_mutex_unlock( &mylock );
 }
 
 int Synaptics::Pad::driverVersion()
