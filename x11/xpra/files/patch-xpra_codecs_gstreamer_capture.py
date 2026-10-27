Description: xpra.codecs.gstreamer.capture imports CSC_ALIAS from
  xpra.codecs.constants, which 6.5.4 does not define, so the optional
  gstreamer capture codec fails to import. Drop the import and map NV12 to
  YUV420P inline, which is what CSC_ALIAS did, so the client gets a pixel
  format it can decode (the VAAPI/AMF encoders produce NV12).
Issue ID: https://github.com/Xpra-org/xpra/pull/5099
Changeset: none (still broken on upstream v6.5.x; master replaced the
  module in e7c3c948a5, "#4937 replace gstreamer with native pipewire calls")
TODO: Drop once a 6.5.x release includes it, or when updating to a release
  with the pipewire rewrite.

--- xpra/codecs/gstreamer/capture.py.orig	2026-09-27 15:24:27 UTC
+++ xpra/codecs/gstreamer/capture.py
@@ -17,7 +17,7 @@ from xpra.gstreamer.common import (
 )
 from xpra.util.gobject import n_arg_signal
 from xpra.gstreamer.pipeline import Pipeline
-from xpra.codecs.constants import get_profile, CSC_ALIAS, VideoSpec
+from xpra.codecs.constants import get_profile, VideoSpec
 from xpra.codecs.gstreamer.common import (
     get_version, get_type, get_info,
     get_video_encoder_caps, get_video_encoder_options,
@@ -251,7 +251,8 @@ class CaptureAndEncode(Capture):
             self.frames += 1
             client_info = self.extra_client_info
             client_info["frame"] = self.frames
-            client_info["csc"] = CSC_ALIAS.get(self.pixel_format, self.pixel_format)
+            # NV12 frames decode as YUV420P on the client (the old CSC_ALIAS)
+            client_info["csc"] = {"NV12": "YUV420P"}.get(self.pixel_format, self.pixel_format)
             self.extra_client_info = {}
             self.emit("new-image", self.encoding, data, client_info)
             if SAVE_TO_FILE:
