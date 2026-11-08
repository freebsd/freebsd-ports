Description: AudioSource: pick the first PulseAudio monitor device without
 indexing a dict view.  monitor_devices is a dict, and on Python 3
 dict.items() is not subscriptable, so .items()[0][0] raised TypeError
 whenever no source type was given and monitor devices were present.
 Use next(iter(monitor_devices)), the first key.
Issue ID: https://github.com/Xpra-org/xpra/pull/5098
Changeset: none (still present in Xpra-org/xpra master as of 2026-10-14)
TODO: Drop once a release includes it.

--- xpra/audio/src.py.orig	2026-09-27 15:24:27 UTC
+++ xpra/audio/src.py
@@ -89,7 +89,7 @@ class AudioSource(AudioPipeline):
                 src_type = "audiotestsrc"
                 default_src_options = {"wave": 2, "freq": 100, "volume": 0.4}
             else:
-                monitor_device = monitor_devices.items()[0][0]
+                monitor_device = next(iter(monitor_devices))
                 log.info("using pulseaudio source device:")
                 log.info(" '%s'", monitor_device)
                 src_type = "pulsesrc"
