--- FvwmCompositor/eigen/matrix.h.orig	2008-03-25 17:15:13.000000000 +0000
+++ FvwmCompositor/eigen/matrix.h
@@ -170,7 +170,7 @@ public:
       */
     Matrix( const Matrix & other )
     {
-        readArray( other.array() );
+        this->readArray( other.array() );
     }
 
     /**
@@ -179,7 +179,7 @@ public:
       */
     Matrix( const T * array )
     {
-        readArray( array );
+        this->readArray( array );
     }
 
     /**
@@ -322,7 +322,7 @@ public:
     MatrixX( const MatrixX & other )
     {
         init( other.size() );
-        readArray( other.array() );
+        this->readArray( other.array() );
     }
 
     /**
@@ -336,7 +336,7 @@ public:
     MatrixX( int size, const T * array )
     {
         init( size );
-        readArray( array );
+        this->readArray( array );
     }
 
     /**
