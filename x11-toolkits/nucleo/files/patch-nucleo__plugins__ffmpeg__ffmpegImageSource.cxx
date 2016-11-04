--- nucleo/plugins/ffmpeg/ffmpegImageSource.cxx.orig	2009-05-25 12:53:15 UTC
+++ nucleo/plugins/ffmpeg/ffmpegImageSource.cxx
@@ -47,23 +47,23 @@ namespace nucleo {
 
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
@@ -86,7 +86,7 @@ namespace nucleo {
 	 return false ;
     }
 
-    ret = avcodec_open(cctx, codec);
+    ret = avcodec_open2(cctx, codec, NULL);
     if (ret<0) {
 	 std::cerr << "ffmpegImageSource: unable to open codec" << std::endl ;
 	 return false ;
@@ -123,39 +123,39 @@ namespace nucleo {
 #endif
 
 	 int got_picture = 0 ;
-	 avcodec_decode_video(cctx, &frame, &got_picture, packet.data, packet.size) ;
+	 avcodec_decode_video2(cctx, &frame, &got_picture, &packet) ;
 	 av_free_packet(&packet) ;
 	 if (!got_picture) continue ;
 
 	 lastImage.setTimeStamp() ;
 	 switch (cctx->pix_fmt) {
-	 case PIX_FMT_GRAY8:
+	 case AV_PIX_FMT_GRAY8:
 	   lastImage.setDims(cctx->width, cctx->height) ;
 	   lastImage.setEncoding(Image::L) ;
 	   lastImage.setData(frame.data[0], cctx->width*cctx->height, Image::NONE) ;
 	   break ;
-	 case PIX_FMT_RGB24:
+	 case AV_PIX_FMT_RGB24:
 	   lastImage.setDims(cctx->width, cctx->height) ;
 	   lastImage.setEncoding(Image::RGB) ;
 	   lastImage.setData(frame.data[0], (cctx->width*cctx->height)*3, Image::NONE) ;
 	   break ;
 	 default: // Convert everything else to RGB24
-	   // PIX_FMT_YUV420P has three separate plans and ffmpeg converts
+	   // AV_PIX_FMT_YUV420P has three separate plans and ffmpeg converts
 	   // them to RGB faster than nucleo does...
-	   // PIX_FMT_RGBA32 and PIX_FMT_RGB565 are stored in cpu endianness
+	   // AV_PIX_FMT_RGBA32 and AV_PIX_FMT_RGB565 are stored in cpu endianness
 	   // On OS X (powerpc), they correspond to Image::ARGB and Image::RGB565
 	   lastImage.prepareFor(cctx->width, cctx->height, Image::RGB) ;
 	   AVFrame tmpframe ;
-	   avpicture_fill((AVPicture*)&tmpframe, lastImage.getData(), PIX_FMT_RGB24,
+	   avpicture_fill((AVPicture*)&tmpframe, lastImage.getData(), AV_PIX_FMT_RGB24,
 				   cctx->width, cctx->height) ;
 #if NO_SOFTWARE_SCALER
-	   img_convert((AVPicture*)&tmpframe, PIX_FMT_RGB24,
+	   img_convert((AVPicture*)&tmpframe, AV_PIX_FMT_RGB24,
 				(AVPicture*)&frame, cctx->pix_fmt, cctx->width, cctx->height) ;
 #else
 	   SwsContext *swsc = 0 ;
 	   swsc = sws_getCachedContext(swsc,
 							 cctx->width, cctx->height, cctx->pix_fmt, 
-							 cctx->width, cctx->height, PIX_FMT_RGB24,
+							 cctx->width, cctx->height, AV_PIX_FMT_RGB24,
 							 SWS_BICUBIC, NULL, NULL, NULL) ;
 	   if (!swsc) {
 		std::cerr << "ffmpegImageSource: sws_getCachedContext failed" << std::endl ;
