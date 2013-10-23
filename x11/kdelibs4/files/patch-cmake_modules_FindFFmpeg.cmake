--- ./cmake/modules/FindFFmpeg.cmake.orig	2013-06-28 17:03:40.713321000 +0000
+++ ./cmake/modules/FindFFmpeg.cmake	2013-10-23 13:30:59.895502135 +0000
@@ -71,13 +71,15 @@
       ${PC_LIB${_component}_INCLUDEDIR}
       ${PC_LIB${_component}_INCLUDE_DIRS}
     PATH_SUFFIXES
-      ffmpeg
+      ffmpeg${FFMPEG_SUFFIX}
   )
 
   find_library(${_component}_LIBRARIES NAMES ${_library}
-      HINTS
+    HINTS
       ${PC_LIB${_component}_LIBDIR}
       ${PC_LIB${_component}_LIBRARY_DIRS}
+    PATH_SUFFIXES
+      ffmpeg${FFMPEG_SUFFIX}
   )
 
   set(${_component}_DEFINITIONS  ${PC_${_component}_CFLAGS_OTHER} CACHE STRING "The ${_component} CFLAGS.")
@@ -98,12 +100,12 @@
 if (NOT FFMPEG_LIBRARIES)
 
   # Check for all possible component.
-  find_component(AVCODEC  libavcodec  avcodec  libavcodec/avcodec.h)
-  find_component(AVFORMAT libavformat avformat libavformat/avformat.h)
-  find_component(AVDEVICE libavdevice avdevice libavdevice/avdevice.h)
-  find_component(AVUTIL   libavutil   avutil   libavutil/avutil.h)
-  find_component(SWSCALE  libswscale  swscale  libswscale/swscale.h)
-  find_component(POSTPROC libpostproc postproc libpostproc/postprocess.h)
+  find_component(AVCODEC  libavcodec${FFMPEG_SUFFIX}  avcodec${FFMPEG_SUFFIX}  libavcodec/avcodec.h)
+  find_component(AVFORMAT libavformat${FFMPEG_SUFFIX} avformat${FFMPEG_SUFFIX} libavformat/avformat.h)
+  find_component(AVDEVICE libavdevice${FFMPEG_SUFFIX} avdevice${FFMPEG_SUFFIX} libavdevice/avdevice.h)
+  find_component(AVUTIL   libavutil${FFMPEG_SUFFIX}   avutil${FFMPEG_SUFFIX}   libavutil/avutil.h)
+  find_component(SWSCALE  libswscale${FFMPEG_SUFFIX}  swscale${FFMPEG_SUFFIX}  libswscale/swscale.h)
+  find_component(POSTPROC libpostproc${FFMPEG_SUFFIX} postproc${FFMPEG_SUFFIX} libpostproc/postprocess.h)
 
   # Check if the required components were found and add their stuff to the FFMPEG_* vars.
   foreach (_component ${FFmpeg_FIND_COMPONENTS})
