--- ./cmake/modules/FindAlsa.cmake.orig	2010-03-24 16:20:34.000000000 +0300
+++ ./cmake/modules/FindAlsa.cmake	2010-08-05 18:49:30.046930607 +0400
@@ -55,6 +55,7 @@
     check_include_files(/usr/src/sys/i386/isa/sound/awe_voice.h HAVE__USR_SRC_SYS_I386_ISA_SOUND_AWE_VOICE_H)
     check_include_files(/usr/src/sys/gnu/i386/isa/sound/awe_voice.h HAVE__USR_SRC_SYS_GNU_I386_ISA_SOUND_AWE_VOICE_H)
 
+    set(CMAKE_REQUIRED_INCLUDES ${ALSA_INCLUDES})
     check_include_file_cxx(sys/asoundlib.h HAVE_SYS_ASOUNDLIB_H)
     check_include_file_cxx(alsa/asoundlib.h HAVE_ALSA_ASOUNDLIB_H)
 
