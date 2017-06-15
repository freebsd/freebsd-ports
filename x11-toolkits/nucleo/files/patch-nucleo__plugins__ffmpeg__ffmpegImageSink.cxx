--- nucleo/plugins/ffmpeg/ffmpegImageSink.cxx.orig	2009-05-25 12:53:15 UTC
+++ nucleo/plugins/ffmpeg/ffmpegImageSink.cxx
@@ -118,17 +118,17 @@ namespace nucleo {
 
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
     if (!output_format)
 	 message = "Unable to find the requested format" ;
-    else if (output_format->video_codec == CODEC_ID_NONE) {
+    else if (output_format->video_codec == AV_CODEC_ID_NONE) {
 	 output_format = 0 ;
 	 message = "Not a video format" ;
     } else if (output_format->flags & AVFMT_NOFILE) {
@@ -156,12 +156,13 @@ namespace nucleo {
     snprintf(format_context->filename, sizeof(format_context->filename), 
 		   "%s", filename.c_str()) ;
  
-    vstream = av_new_stream(format_context, FREEPLAYER_VIDEO_PID) ;
+    vstream = avformat_new_stream(format_context, NULL) ;
     if (!vstream) {
 	 std::cerr << "ffmpegImageSink: unable to create the AVStream" << std::endl ;
 	 stop() ;
 	 return false ;
     }
+    vstream -> id = FREEPLAYER_VIDEO_PID;
 
     // ----------------
 
@@ -190,8 +191,8 @@ namespace nucleo {
 
     AVCodecContext *codec_context = vstream->codec ;
     codec_context->codec_id = output_format->video_codec ;
-    codec_context->codec_type = CODEC_TYPE_VIDEO ;
-    codec_context->pix_fmt = PIX_FMT_YUV420P ;
+    codec_context->codec_type = AVMEDIA_TYPE_VIDEO ;
+    codec_context->pix_fmt = AV_PIX_FMT_YUV420P ;
     codec_context->width = img->getWidth() ;  // must be a multiple of two
     codec_context->height = img->getHeight() ; // must be a multiple of two
     codec_context->me_method = ME_EPZS ; // ME_ZERO
@@ -210,12 +211,7 @@ namespace nucleo {
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
 
@@ -225,7 +221,7 @@ namespace nucleo {
 	 return false ;
     }
 
-    if (avcodec_open(codec_context, codec) < 0) {
+    if (avcodec_open2(codec_context, codec, NULL) < 0) {
 	 std::cerr << "ffmpegImageSink: could not open codec" << std::endl ;
 	 vstream->codec = 0 ;
 	 return false ;
@@ -235,7 +231,7 @@ namespace nucleo {
 
     if (filename!="") {
 	 sender = 0 ;
-	 if (url_fopen(&format_context->pb, filename.c_str(), URL_WRONLY) < 0) {
+	 if (avio_open(&format_context->pb, filename.c_str(), AVIO_FLAG_WRITE) < 0) {
 	   std::cerr << "ffmpegImageSink: could not open " << filename << std::endl ;
 	   return false ;
 	 }
@@ -245,37 +241,37 @@ namespace nucleo {
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
 
     switch (img->getEncoding()) {
     case Image::ARGB: 
-	 // PIX_FMT_RGBA32 is endian-sensitive...
-	 // srcEncoding = ByteOrder::isLittleEndian() ? PIX_FMT_RGB24 : PIX_FMT_RGBA32 ; 
-	 srcEncoding = PIX_FMT_RGB24 ;
+	 // AV_PIX_FMT_RGBA32 is endian-sensitive...
+	 // srcEncoding = ByteOrder::isLittleEndian() ? AV_PIX_FMT_RGB24 : AV_PIX_FMT_RGBA32 ; 
+	 srcEncoding = AV_PIX_FMT_RGB24 ;
 	 break ; 
-    case Image::L: srcEncoding = PIX_FMT_GRAY8 ; break ;
-    case Image::YpCbCr420: srcEncoding = PIX_FMT_YUV420P ; break ;
-    default: srcEncoding = PIX_FMT_RGB24 ; break ;
+    case Image::L: srcEncoding = AV_PIX_FMT_GRAY8 ; break ;
+    case Image::YpCbCr420: srcEncoding = AV_PIX_FMT_YUV420P ; break ;
+    default: srcEncoding = AV_PIX_FMT_RGB24 ; break ;
     }
 
-    avcodec_get_frame_defaults(&srcPic) ;
+    av_frame_unref(&srcPic) ;
     if (codec_context->pix_fmt==srcEncoding)
 	 picture = &srcPic ;
     else {
-	 avcodec_get_frame_defaults(&convPic) ;
+	 av_frame_unref(&convPic) ;
 	 int size = avpicture_get_size(codec_context->pix_fmt, codec_context->width, codec_context->height) ;
 	 avpicture_fill((AVPicture *)&convPic,
 				 new uint8_t [size],
@@ -304,7 +300,7 @@ namespace nucleo {
     // std::cerr << "base: " << vstream->time_base.num << " / " << vstream->time_base.den << std::endl ;
 
     AVCodecContext *cctx = vstream->codec ;
-    if (srcEncoding==PIX_FMT_RGB24) convertImage(img, Image::RGB) ;
+    if (srcEncoding==AV_PIX_FMT_RGB24) convertImage(img, Image::RGB) ;
     resizeImage(img, cctx->width, cctx->height) ;
     avpicture_fill((AVPicture *)&srcPic, img->getData(), srcEncoding,
 			    cctx->width, cctx->height) ;
@@ -330,23 +326,23 @@ namespace nucleo {
     picture->pts = pts ;
     // std::cerr << "pts: " << pts << std::endl ;
 
-    int out_size = avcodec_encode_video(cctx, video_outbuf, video_outbuf_size, picture) ;
-    if (!out_size) {
-	 std::cerr << "ffmpegImageSink: avcodec_encode_video returned 0" << std::endl ;
+    AVPacket pkt ;
+    av_init_packet(&pkt) ;
+    pkt.data = video_outbuf ;
+    pkt.size = video_outbuf_size ;
+
+    int got_packet = 0 ;
+    int ret = avcodec_encode_video2(cctx, &pkt, picture, &got_packet) ;
+    if (ret < 0 || !got_packet || pkt.size <= 0) {
+	 std::cerr << "ffmpegImageSink: avcodec_encode_video2 failed" << std::endl ;
 	 stop() ;
 	 return false ;
     }
 
-    // std::cerr << "out_size = " << out_size << std::endl ;
-
-    AVPacket pkt ;
-    av_init_packet(&pkt) ;
     pkt.stream_index = vstream->index ;
-    pkt.data = video_outbuf ;
-    pkt.size = out_size ;
     if (cctx->coded_frame) {
 	 pkt.pts = pkt.dts = pts ;
-	 if (cctx->coded_frame->key_frame) pkt.flags |= PKT_FLAG_KEY ;
+	 if (cctx->coded_frame->key_frame) pkt.flags |= AV_PKT_FLAG_KEY ;
     }
     if (av_write_frame(format_context, &pkt) != 0) {
 	 // std::cerr << "ffmpegImageSink: error while writing video frame" << std::endl ;
@@ -372,7 +368,7 @@ namespace nucleo {
 	 if (vstream->codec) {
 	   avcodec_close(vstream->codec) ;
 	   av_write_trailer(format_context) ;
-	   if (!sender) url_fclose(format_context->pb) ;
+	   if (!sender) avio_close(format_context->pb) ;
 	 }
 	 av_freep(&vstream) ;
     }
