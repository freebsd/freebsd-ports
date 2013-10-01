--- FvwmCompositor/eigen/ludecomposition.h.orig	2008-03-25 17:15:13.000000000 +0000
+++ FvwmCompositor/eigen/ludecomposition.h
@@ -85,7 +85,7 @@ class LUDecomposition
 public:
 
     /** Performs the LU Decomposition of mat. Use this constructor. */
-    LUDecomposition( const Matrix<T, Size> & mat ) { perform( mat ); }
+    LUDecomposition( const Matrix<T, Size> & mat ) { this->perform( mat ); }
 
 protected:
     /** Default constructor. Does nothing. \internal
@@ -128,7 +128,7 @@ class LUDecompositionX
 
 public:
     /** Performs the LU Decomposition of mat. Use this constructor. */
-    LUDecompositionX( const MatrixX<T> & mat ) { perform( mat ); }
+    LUDecompositionX( const MatrixX<T> & mat ) { this->perform( mat ); }
 
 protected:
     /** Default constructor. Does nothing. \internal
