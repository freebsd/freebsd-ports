https://www.xpra.org/trac/changeset/18086/xpra

--- xpra/codecs/dec_avcodec2/decoder.pyx.orig	2017-03-17 07:24:28 UTC
+++ xpra/codecs/dec_avcodec2/decoder.pyx
@@ -51,7 +51,7 @@ cdef extern from "libavutil/pixfmt.h":
     AVPixelFormat AV_PIX_FMT_GBRP
 
 cdef extern from "libavcodec/avcodec.h":
-    int CODEC_FLAG2_FAST
+    int AV_CODEC_FLAG2_FAST
 
     ctypedef struct AVFrame:
         uint8_t **data
@@ -357,7 +357,7 @@ cdef class Decoder:
         self.codec_ctx.thread_safe_callbacks = 1
         self.codec_ctx.thread_type = 2      #FF_THREAD_SLICE: allow more than one thread per frame
         self.codec_ctx.thread_count = 0     #auto
-        self.codec_ctx.flags2 |= CODEC_FLAG2_FAST   #may cause "no deblock across slices" - which should be fine
+        self.codec_ctx.flags2 |= AV_CODEC_FLAG2_FAST    #may cause "no deblock across slices" - which should be fine
         r = avcodec_open2(self.codec_ctx, self.codec, NULL)
         if r<0:
             log.error("could not open codec: %s", av_error_str(r))
