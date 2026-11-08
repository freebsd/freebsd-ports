--- xembed-sni-proxy/sniproxy.cpp.orig	2026-03-03 09:36:38 UTC
+++ xembed-sni-proxy/sniproxy.cpp
@@ -324,7 +324,7 @@ QImage SNIProxy::getImageNonComposite() const
             return elaborateConversion;
     } else {
         // Now we are sure we can eventually delete the xcb_image_t with this version
-        return {image->data, image->width, image->height, image->stride, QImage::Format_ARGB32, sni_cleanup_xcb_image, image};
+        return {image->data, image->width, image->height, static_cast<qsizetype>(image->stride), QImage::Format_ARGB32, sni_cleanup_xcb_image, image};
     }
 }
 
