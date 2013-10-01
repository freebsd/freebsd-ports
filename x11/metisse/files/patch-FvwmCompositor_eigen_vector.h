--- FvwmCompositor/eigen/vector.h.orig	2008-03-25 17:15:13.000000000 +0000
+++ FvwmCompositor/eigen/vector.h
@@ -141,7 +141,7 @@ public:
       */
     Vector( const Vector &v )
     {
-        readArray( v.array() );
+        this->readArray( v.array() );
     }
 
     /**
@@ -149,7 +149,7 @@ public:
       */
     Vector( const T *array )
     {
-        readArray( array );
+        this->readArray( array );
     }
 
     /**
@@ -160,7 +160,7 @@ public:
     Vector( int unused_size, const T *array )
     {
         assert( unused_size == this->size() );
-        readArray( array );
+        this->readArray( array );
     }
 
     /**
@@ -312,7 +312,7 @@ public:
     VectorX( const VectorX & other )
     {
         init( other._size() );
-        readArray( other.array() );
+        this->readArray( other.array() );
     }
 
     /**
@@ -328,7 +328,7 @@ public:
     VectorX( int size, const T * array )
     {
         init( size );
-        readArray( array );
+        this->readArray( array );
     }
 
     ~VectorX()
