--- src/wayland/buffer/dmabuf.cpp.orig	2026-05-09 11:53:15 UTC
+++ src/wayland/buffer/dmabuf.cpp
@@ -955,9 +955,9 @@ WlBufferQSGTexture* WlDmaBuffer::createQsgTextureGl(QQ
 
 	// clang-format off
 	auto attribs = std::vector<EGLAttrib> {
-		EGL_WIDTH, this->width,
-		EGL_HEIGHT, this->height,
-		EGL_LINUX_DRM_FOURCC_EXT, this->format,
+		EGL_WIDTH, static_cast<int>(this->width),
+		EGL_HEIGHT, static_cast<int>(this->height),
+		EGL_LINUX_DRM_FOURCC_EXT, static_cast<int>(this->format),
 	};
 	// clang-format on
 
@@ -973,8 +973,8 @@ WlBufferQSGTexture* WlDmaBuffer::createQsgTextureGl(QQ
 		// clang-format off
 		attribs.insert(attribs.end(), {
 		    names.fd, plane.fd,
-		    names.offset, plane.offset,
-		    names.pitch, plane.stride,
+		    names.offset, static_cast<int>(plane.offset),
+		    names.pitch, static_cast<int>(plane.stride),
 		});
 		// clang-format on
 
