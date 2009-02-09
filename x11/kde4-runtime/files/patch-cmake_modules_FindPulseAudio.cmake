--- ../cmake/modules/FindPulseAudio.cmake.orig	2008-09-03 11:24:24.000000000 +0000
+++ ../cmake/modules/FindPulseAudio.cmake	2008-12-27 14:20:09.000000000 +0000
@@ -16,16 +16,16 @@
    set(PULSEAUDIO_FIND_QUIETLY TRUE)
 endif (PULSEAUDIO_INCLUDE_DIR AND PULSEAUDIO_LIBRARY)
 
-if (NOT WIN32)
-   include(FindPkgConfig)
-   pkg_check_modules(PULSEAUDIO libpulse)
-   if(PULSEAUDIO_FOUND)
-      set(PULSEAUDIO_LIBRARY ${PULSEAUDIO_LIBRARIES} CACHE FILEPATH "Path to the PulseAudio library")
-      set(PULSEAUDIO_INCLUDE_DIR ${PULSEAUDIO_INCLUDEDIR} CACHE PATH "Path to the PulseAudio includes")
-      #  PULSEAUDIO_DEFINITIONS - Compiler switches required for using PulseAudio
-      #  set(PULSEAUDIO_DEFINITIONS ${PULSEAUDIO_CFLAGS})
-   endif(PULSEAUDIO_FOUND)
-endif (NOT WIN32)
+# if (NOT WIN32)
+#    include(FindPkgConfig)
+#    pkg_check_modules(PULSEAUDIO libpulse)
+#    if(PULSEAUDIO_FOUND)
+#       set(PULSEAUDIO_LIBRARY ${PULSEAUDIO_LIBRARIES} CACHE FILEPATH "Path to the PulseAudio library")
+#       set(PULSEAUDIO_INCLUDE_DIR ${PULSEAUDIO_INCLUDEDIR} CACHE PATH "Path to the PulseAudio includes")
+#       #  PULSEAUDIO_DEFINITIONS - Compiler switches required for using PulseAudio
+#       #  set(PULSEAUDIO_DEFINITIONS ${PULSEAUDIO_CFLAGS})
+#    endif(PULSEAUDIO_FOUND)
+# endif (NOT WIN32)
 
 if (NOT PULSEAUDIO_INCLUDE_DIR)
    FIND_PATH(PULSEAUDIO_INCLUDE_DIR pulse/pulseaudio.h)
