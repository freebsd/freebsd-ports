--- pad.cpp.orig	2018-02-13 19:06:19 UTC
+++ pad.cpp
@@ -9,7 +9,7 @@
 // singleton specific code
 //
 
-pthread_mutex_t Synaptics::Pad::mMutex = PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+pthread_mutex_t Synaptics::Pad::mMutex = PTHREAD_MUTEX_INITIALIZER; // PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
 
 Synaptics::Pad* Synaptics::Pad::getInstance()
 {
