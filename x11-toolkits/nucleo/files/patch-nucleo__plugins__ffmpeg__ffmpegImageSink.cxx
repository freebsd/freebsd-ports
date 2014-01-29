--- nucleo/plugins/ffmpeg/ffmpegImageSink.cxx.orig
+++ nucleo/plugins/ffmpeg/ffmpegImageSink.cxx
@@ -118,11 +118,11 @@
 
     output_format = 0 ;
     if (uri.scheme=="mpegts-udp") {
-	 output_format = guess_format("mpegts", NULL, NULL) ;
+	 output_format = av_guess_format("mpegts", NULL, NULL) ;
     } else {
 	 filename = uri.opaque!="" ? uri.opaque : uri.path ;
-	 if (guessFormat) output_format = guess_format(NULL, filename.c_str(), NULL) ;
-	 if (!output_format) output_format = guess_format(format.c_str(), NULL, NULL) ;
+	 if (guessFormat) output_format = av_guess_format(NULL, filename.c_str(), NULL) ;
+	 if (!output_format) output_format = av_guess_format(format.c_str(), NULL, NULL) ;
     } 
 
     std::string message ;
@@ -190,7 +190,7 @@
 
     AVCodecContext *codec_context = vstream->codec ;
     codec_context->codec_id = output_format->video_codec ;
-    codec_context->codec_type = CODEC_TYPE_VIDEO ;
+    codec_context->codec_type = AVMEDIA_TYPE_VIDEO ;
     codec_context->pix_fmt = PIX_FMT_YUV420P ;
     codec_context->width = img->getWidth() ;  // must be a multiple of two
     codec_context->height = img->getHeight() ; // must be a multiple of two
@@ -210,12 +210,7 @@
 	   || !strcmp(format_context->oformat->name, "3gp"))
 	 codec_context->flags |= CODEC_FLAG_GLOBAL_HEADER ;
 
-    if (av_set_parameters(format_context, NULL) < 0) {
-	 std::cerr << "ffmpegImageSink: invalid output format parameters" << std::endl ;
-	 return false ;
-    }
-
-    dump_format(format_context, 0, filename.c_str(), 1) ; // FIXME: for debug only
+    av_dump_format(format_context, 0, filename.c_str(), 1) ; // FIXME: for debug only
 
     // ------------------
 
@@ -225,7 +220,7 @@
 	 return false ;
     }
 
-    if (avcodec_open(codec_context, codec) < 0) {
+    if (avcodec_open2(codec_context, codec, NULL) < 0) {
 	 std::cerr << "ffmpegImageSink: could not open codec" << std::endl ;
 	 vstream->codec = 0 ;
 	 return false ;
@@ -235,7 +230,7 @@
 
     if (filename!="") {
 	 sender = 0 ;
-	 if (url_fopen(&format_context->pb, filename.c_str(), URL_WRONLY) < 0) {
+	 if (avio_open(&format_context->pb, filename.c_str(), AVIO_FLAG_WRITE) < 0) {
 	   std::cerr << "ffmpegImageSink: could not open " << filename << std::endl ;
 	   return false ;
 	 }
@@ -245,17 +240,17 @@
 	 int port = uri.port ;
 	 if (!port) port = 1234 ;
 	 sender = new UdpSender(uri.host.c_str(), port) ;
-	 if (init_put_byte(format_context->pb, buffer, buffer_size,
+	 if (avio_alloc_context(buffer, buffer_size,
 				    1, (void *)this,
 				    0, udp_callback, 0) < 0) {
 	   std::cerr << "ffmpegImageSink: init_put_byte failed" << std::endl ;
 	   return false ;
 	 }
-	 format_context->pb->is_streamed = 1 ; // no seek
+	 format_context->pb->seekable = 0 ; // no seek
 	 format_context->pb->max_packet_size = buffer_size ;
     }
     
-    av_write_header(format_context) ;
+    avformat_write_header(format_context, NULL) ;
 
     video_outbuf_size = 256*1024 ; // FIXME ?
     video_outbuf = new uint8_t [video_outbuf_size] ;
@@ -346,7 +341,7 @@
     pkt.size = out_size ;
     if (cctx->coded_frame) {
 	 pkt.pts = pkt.dts = pts ;
-	 if (cctx->coded_frame->key_frame) pkt.flags |= PKT_FLAG_KEY ;
+	 if (cctx->coded_frame->key_frame) pkt.flags |= AV_PKT_FLAG_KEY ;
     }
     if (av_write_frame(format_context, &pkt) != 0) {
 	 // std::cerr << "ffmpegImageSink: error while writing video frame" << std::endl ;
@@ -372,7 +367,7 @@
 	 if (vstream->codec) {
 	   avcodec_close(vstream->codec) ;
 	   av_write_trailer(format_context) ;
-	   if (!sender) url_fclose(format_context->pb) ;
+	   if (!sender) avio_close(format_context->pb) ;
 	 }
 	 av_freep(&vstream) ;
     }
