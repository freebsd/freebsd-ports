--- nucleo/plugins/ffmpeg/ffmpegImageSink.H.orig	2009-05-25 12:53:15 UTC
+++ nucleo/plugins/ffmpeg/ffmpegImageSink.H
@@ -36,7 +36,7 @@ namespace nucleo {
     AVFrame srcPic, convPic, *picture ;
     int video_outbuf_size ;
     uint8_t *video_outbuf ;
-    enum PixelFormat srcEncoding ;
+    enum AVPixelFormat srcEncoding ;
 
     std::string filename ;   // if used as a file sink
 
