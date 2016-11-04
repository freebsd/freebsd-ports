--- nucleo/plugins/ffmpeg/ffmpegImageSource.cxx.orig
+++ nucleo/plugins/ffmpeg/ffmpegImageSource.cxx
@@ -47,23 +47,23 @@
 
   bool
   ffmpegImageSource::start(void) {
-    int ret = av_open_input_file(&fctx, filename.c_str(), 0, 0, 0);
+    int ret = avformat_open_input(&fctx, filename.c_str(), 0, 0);
     if (ret<0) {
 	 std::cerr << "ffmpegImageSource: failed to open " << filename << " (" << ret << ")" << std::endl ;
 	 return false ;
     }
 
-    ret = av_find_stream_info(fctx) ;
+    ret = avformat_find_stream_info(fctx, NULL) ;
     if (ret<0) {
 	 std::cerr << "ffmpegImageSource: failed to find codec parameters for " << filename << " (" << ret << ")" << std::endl ;
 	 return false ;
     }
 
-    dump_format(fctx, 1, filename.c_str(), 0) ;
+    av_dump_format(fctx, 1, filename.c_str(), 0) ;
 
     bool found_video_stream = false ;
     for (unsigned int i=0; i<fctx->nb_streams; ++i) {
-	 if (fctx->streams[i]->codec->codec_type==CODEC_TYPE_VIDEO) {
+	 if (fctx->streams[i]->codec->codec_type==AVMEDIA_TYPE_VIDEO) {
 	   video_stream = i ;
 	   found_video_stream = true ;
 	 } else
@@ -86,7 +86,7 @@
 	 return false ;
     }
 
-    ret = avcodec_open(cctx, codec);
+    ret = avcodec_open2(cctx, codec, NULL);
     if (ret<0) {
 	 std::cerr << "ffmpegImageSource: unable to open codec" << std::endl ;
 	 return false ;
@@ -123,7 +123,7 @@
 #endif
 
 	 int got_picture = 0 ;
-	 avcodec_decode_video(cctx, &frame, &got_picture, packet.data, packet.size) ;
+	 avcodec_decode_video2(cctx, &frame, &got_picture, &packet) ;
 	 av_free_packet(&packet) ;
 	 if (!got_picture) continue ;
 
