https://www.xpra.org/trac/changeset/18088/xpra

--- xpra/codecs/enc_ffmpeg/encoder.pyx.orig	2017-03-17 07:24:28 UTC
+++ xpra/codecs/enc_ffmpeg/encoder.pyx
@@ -134,44 +134,36 @@ cdef extern from "libavcodec/avcodec.h":
     int FF_PROFILE_H264_HIGH_444_INTRA
     int FF_PROFILE_H264_CAVLC_444
 
-    int CODEC_FLAG_UNALIGNED
-    int CODEC_FLAG_QSCALE
-    int CODEC_FLAG_4MV
-    int CODEC_FLAG_OUTPUT_CORRUPT
-    int CODEC_FLAG_QPEL
-    int CODEC_FLAG_GMC
-    int CODEC_FLAG_MV0
-    int CODEC_FLAG_INPUT_PRESERVED
-    int CODEC_FLAG_PASS1
-    int CODEC_FLAG_PASS2
-    int CODEC_FLAG_GRAY
-    int CODEC_FLAG_EMU_EDGE
-    int CODEC_FLAG_PSNR
-    int CODEC_FLAG_TRUNCATED
-    int CODEC_FLAG_NORMALIZE_AQP
-    int CODEC_FLAG_INTERLACED_DCT
-    int CODEC_FLAG_GLOBAL_HEADER
+    int AV_CODEC_FLAG_UNALIGNED
+    int AV_CODEC_FLAG_QSCALE
+    int AV_CODEC_FLAG_4MV
+    int AV_CODEC_FLAG_OUTPUT_CORRUPT
+    int AV_CODEC_FLAG_QPEL
+    int AV_CODEC_FLAG_PASS1
+    int AV_CODEC_FLAG_PASS2
+    int AV_CODEC_FLAG_GRAY
+    int AV_CODEC_FLAG_PSNR
+    int AV_CODEC_FLAG_TRUNCATED
+    int AV_CODEC_FLAG_INTERLACED_DCT
+    int AV_CODEC_FLAG_GLOBAL_HEADER
 
-    int CODEC_FLAG2_FAST
+    int AV_CODEC_FLAG2_FAST
 
-    int CODEC_CAP_DRAW_HORIZ_BAND
-    int CODEC_CAP_DR1
-    int CODEC_CAP_TRUNCATED
-    int CODEC_CAP_HWACCEL
-    int CODEC_CAP_DELAY
-    int CODEC_CAP_SMALL_LAST_FRAME
-    int CODEC_CAP_HWACCEL_VDPAU
-    int CODEC_CAP_SUBFRAMES
-    int CODEC_CAP_EXPERIMENTAL
-    int CODEC_CAP_CHANNEL_CONF
-    int CODEC_CAP_NEG_LINESIZES
-    int CODEC_CAP_FRAME_THREADS
-    int CODEC_CAP_SLICE_THREADS
-    int CODEC_CAP_PARAM_CHANGE
-    int CODEC_CAP_AUTO_THREADS
-    int CODEC_CAP_VARIABLE_FRAME_SIZE
-    int CODEC_CAP_INTRA_ONLY
-    int CODEC_CAP_LOSSLESS
+    int AV_CODEC_CAP_DRAW_HORIZ_BAND
+    int AV_CODEC_CAP_DR1
+    int AV_CODEC_CAP_TRUNCATED
+    int AV_CODEC_CAP_DELAY
+    int AV_CODEC_CAP_SMALL_LAST_FRAME
+    int AV_CODEC_CAP_SUBFRAMES
+    int AV_CODEC_CAP_EXPERIMENTAL
+    int AV_CODEC_CAP_CHANNEL_CONF
+    int AV_CODEC_CAP_FRAME_THREADS
+    int AV_CODEC_CAP_SLICE_THREADS
+    int AV_CODEC_CAP_PARAM_CHANGE
+    int AV_CODEC_CAP_AUTO_THREADS
+    int AV_CODEC_CAP_VARIABLE_FRAME_SIZE
+    int AV_CODEC_CAP_INTRA_ONLY
+    int AV_CODEC_CAP_LOSSLESS
 
     ctypedef struct AVFrame:
         uint8_t     **data
@@ -385,7 +377,6 @@ cdef extern from "libavformat/avformat.h":
     int AVFMT_NOFILE                #Demuxer will use avio_open, no opened file should be provided by the caller
     int AVFMT_NEEDNUMBER            #Needs '%d' in filename
     int AVFMT_SHOW_IDS              #Show format stream IDs numbers
-    int AVFMT_RAWPICTURE            #Format wants AVPicture structure for raw picture data. @deprecated Not used anymore
     int AVFMT_GLOBALHEADER          #Format wants global header
     int AVFMT_NOTIMESTAMPS          #Format does not need / have any timestamps
     int AVFMT_GENERIC_INDEX         #Use generic index building code
@@ -489,27 +480,22 @@ AVFMTCTX = {
             }
 
 CODEC_FLAGS = {
-               CODEC_FLAG_UNALIGNED         : "UNALIGNED",
-               CODEC_FLAG_QSCALE            : "QSCALE",
-               CODEC_FLAG_4MV               : "4MV",
-               CODEC_FLAG_OUTPUT_CORRUPT    : "OUTPUT_CORRUPT",
-               CODEC_FLAG_QPEL              : "QPEL",
-               CODEC_FLAG_GMC               : "GMC",
-               CODEC_FLAG_MV0               : "MV0",
-               CODEC_FLAG_INPUT_PRESERVED   : "INPUT_PRESERVED",
-               CODEC_FLAG_PASS1             : "PASS1",
-               CODEC_FLAG_PASS2             : "PASS2",
-               CODEC_FLAG_GRAY              : "GRAY",
-               CODEC_FLAG_EMU_EDGE          : "EMU_EDGE",
-               CODEC_FLAG_PSNR              : "PSNR",
-               CODEC_FLAG_TRUNCATED         : "TRUNCATED",
-               CODEC_FLAG_NORMALIZE_AQP     : "NORMALIZE_AQP",
-               CODEC_FLAG_INTERLACED_DCT    : "INTERLACED_DCT",
-               CODEC_FLAG_GLOBAL_HEADER     : "GLOBAL_HEADER",
+               AV_CODEC_FLAG_UNALIGNED          : "UNALIGNED",
+               AV_CODEC_FLAG_QSCALE             : "QSCALE",
+               AV_CODEC_FLAG_4MV                : "4MV",
+               AV_CODEC_FLAG_OUTPUT_CORRUPT     : "OUTPUT_CORRUPT",
+               AV_CODEC_FLAG_QPEL               : "QPEL",
+               AV_CODEC_FLAG_PASS1              : "PASS1",
+               AV_CODEC_FLAG_PASS2              : "PASS2",
+               AV_CODEC_FLAG_GRAY               : "GRAY",
+               AV_CODEC_FLAG_PSNR               : "PSNR",
+               AV_CODEC_FLAG_TRUNCATED          : "TRUNCATED",
+               AV_CODEC_FLAG_INTERLACED_DCT     : "INTERLACED_DCT",
+               AV_CODEC_FLAG_GLOBAL_HEADER      : "GLOBAL_HEADER",
                }
 
 CODEC_FLAGS2 = {
-                CODEC_FLAG2_FAST : "FAST",
+                AV_CODEC_FLAG2_FAST : "FAST",
                 }
 
 FMT_FLAGS = {
@@ -535,7 +521,6 @@ AVFMT = {
          AVFMT_NOFILE           : "NOFILE",
          AVFMT_NEEDNUMBER       : "NEEDNUMBER",
          AVFMT_SHOW_IDS         : "SHOW_IDS",
-         AVFMT_RAWPICTURE       : "RAWPICTURE",
          AVFMT_GLOBALHEADER     : "GLOBALHEADER",
          AVFMT_NOTIMESTAMPS     : "NOTIMESTAMPS",
          AVFMT_GENERIC_INDEX    : "GENERIC_INDEX",
@@ -554,24 +539,21 @@ AVFMT = {
 
 
 CAPS = {
-        CODEC_CAP_DRAW_HORIZ_BAND       : "DRAW_HORIZ_BAND",
-        CODEC_CAP_DR1                   : "DR1",
-        CODEC_CAP_TRUNCATED             : "TRUNCATED",
-        CODEC_CAP_HWACCEL               : "HWACCEL",
-        CODEC_CAP_DELAY                 : "DELAY",
-        CODEC_CAP_SMALL_LAST_FRAME      : "SMALL_LAST_FRAME",
-        CODEC_CAP_HWACCEL_VDPAU         : "HWACCEL_VDPAU",
-        CODEC_CAP_SUBFRAMES             : "SUBFRAMES",
-        CODEC_CAP_EXPERIMENTAL          : "EXPERIMENTAL",
-        CODEC_CAP_CHANNEL_CONF          : "CHANNEL_CONF",
-        CODEC_CAP_NEG_LINESIZES         : "NEG_LINESIZES",
-        CODEC_CAP_FRAME_THREADS         : "FRAME_THREADS",
-        CODEC_CAP_SLICE_THREADS         : "SLICE_THREADS",
-        CODEC_CAP_PARAM_CHANGE          : "PARAM_CHANGE",
-        CODEC_CAP_AUTO_THREADS          : "AUTO_THREADS",
-        CODEC_CAP_VARIABLE_FRAME_SIZE   : "VARIABLE_FRAME_SIZE",
-        CODEC_CAP_INTRA_ONLY            : "INTRA_ONLY",
-        CODEC_CAP_LOSSLESS              : "LOSSLESS",
+        AV_CODEC_CAP_DRAW_HORIZ_BAND        : "DRAW_HORIZ_BAND",
+        AV_CODEC_CAP_DR1                    : "DR1",
+        AV_CODEC_CAP_TRUNCATED              : "TRUNCATED",
+        AV_CODEC_CAP_DELAY                  : "DELAY",
+        AV_CODEC_CAP_SMALL_LAST_FRAME       : "SMALL_LAST_FRAME",
+        AV_CODEC_CAP_SUBFRAMES              : "SUBFRAMES",
+        AV_CODEC_CAP_EXPERIMENTAL           : "EXPERIMENTAL",
+        AV_CODEC_CAP_CHANNEL_CONF           : "CHANNEL_CONF",
+        AV_CODEC_CAP_FRAME_THREADS          : "FRAME_THREADS",
+        AV_CODEC_CAP_SLICE_THREADS          : "SLICE_THREADS",
+        AV_CODEC_CAP_PARAM_CHANGE           : "PARAM_CHANGE",
+        AV_CODEC_CAP_AUTO_THREADS           : "AUTO_THREADS",
+        AV_CODEC_CAP_VARIABLE_FRAME_SIZE    : "VARIABLE_FRAME_SIZE",
+        AV_CODEC_CAP_INTRA_ONLY             : "INTRA_ONLY",
+        AV_CODEC_CAP_LOSSLESS               : "LOSSLESS",
         }
 log("CODEC_CAP:")
 print_nested_dict(dict((hex(abs(k)),v) for k,v in CAPS.items()), print_fn=log.debug)
@@ -890,8 +872,8 @@ cdef class Encoder(object):
         self.video_ctx.thread_type = THREAD_TYPE
         self.video_ctx.thread_count = THREAD_COUNT     #0=auto
         #if oformat.flags & AVFMT_GLOBALHEADER:
-        self.video_ctx.flags |= CODEC_FLAG_GLOBAL_HEADER
-        self.video_ctx.flags2 |= CODEC_FLAG2_FAST   #may cause "no deblock across slices" - which should be fine
+        self.video_ctx.flags |= AV_CODEC_FLAG_GLOBAL_HEADER
+        self.video_ctx.flags2 |= AV_CODEC_FLAG2_FAST   #may cause "no deblock across slices" - which should be fine
         if self.encoding.startswith("h264") and profile:
             r = av_dict_set(&opts, b"vprofile", strtobytes(profile), 0)
             log("av_dict_set vprofile=%s returned %i", profile, r)
