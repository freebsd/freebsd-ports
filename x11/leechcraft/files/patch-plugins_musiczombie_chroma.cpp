https://github.com/0xd34df00d/leechcraft/commit/307be1dd37059e49eca37f77ddc4806125a8f843
https://github.com/0xd34df00d/leechcraft/commit/53d56cafd3a1d299601d9f3bfd4ee051ae9121ba
https://github.com/0xd34df00d/leechcraft/commit/875e3b43b7a91656f61180b2b2179137f18e6d71

--- plugins/musiczombie/chroma.cpp.orig	2014-07-28 18:35:44 UTC
+++ plugins/musiczombie/chroma.cpp
@@ -38,7 +38,6 @@ extern "C"
 {
 #include <libavcodec/avcodec.h>
 #include <libavformat/avformat.h>
-#include <libavutil/audioconvert.h>
 #include <libavutil/samplefmt.h>
 #include <libavutil/opt.h>
 #include <libswresample/swresample.h>
@@ -122,8 +121,8 @@ namespace MusicZombie
 		auto remaining = maxLength * codecCtx->channels * codecCtx->sample_rate;
 		chromaprint_start (Ctx_, codecCtx->sample_rate, codecCtx->channels);
 
-		std::shared_ptr<AVFrame> frame (avcodec_alloc_frame (),
-				[] (AVFrame *frame) { avcodec_free_frame (&frame); });
+		std::shared_ptr<AVFrame> frame (av_frame_alloc (),
+				[] (AVFrame *frame) { av_frame_free (&frame); });
 		auto maxDstNbSamples = 0;
 
 		uint8_t *dstData [1] = { nullptr };
@@ -140,7 +139,7 @@ namespace MusicZombie
 			if (packet.stream_index != streamIndex)
 				continue;
 
-			avcodec_get_frame_defaults (frame.get ());
+			av_frame_unref (frame.get ());
 			int gotFrame = false;
 			auto consumed = avcodec_decode_audio4 (codecCtx.get (), frame.get (), &gotFrame, &packet);
 
