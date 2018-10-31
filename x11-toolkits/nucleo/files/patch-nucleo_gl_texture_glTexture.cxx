--- nucleo/gl/texture/glTexture.cxx.orig	2009-06-02 09:34:34 UTC
+++ nucleo/gl/texture/glTexture.cxx
@@ -426,7 +426,9 @@ namespace nucleo {
 	   {left, top, 0.0}
 	 } ;
 
-	 GLdouble texinfo[] = { left, bottom, tWidth, tHeight, 1.0, 1.0 } ;
+	 GLdouble texinfo[] = { left, bottom,
+	   static_cast<GLdouble>(tWidth), static_cast<GLdouble>(tHeight),
+	   1.0, 1.0 } ;
 	 if (tTarget==GL_TEXTURE_2D) {
 	   texinfo[4] = t->getTextureWidth() ;
 	   texinfo[5] = t->getTextureHeight() ;
