--- src/wayland/buffer/dmabuf.cpp.orig	2026-01-13 05:59:50 UTC
+++ src/wayland/buffer/dmabuf.cpp
@@ -599,9 +599,9 @@ WlBufferQSGTexture* WlDmaBuffer::createQsgTexture(QQui
 
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
 
@@ -617,8 +617,8 @@ WlBufferQSGTexture* WlDmaBuffer::createQsgTexture(QQui
 		// clang-format off
 		attribs.insert(attribs.end(), {
 		    names.fd, plane.fd,
-		    names.offset, plane.offset,
-		    names.pitch, plane.stride,
+		    names.offset, static_cast<int>(plane.offset),
+		    names.pitch, static_cast<int>(plane.stride),
 		});
 		// clang-format on
 
