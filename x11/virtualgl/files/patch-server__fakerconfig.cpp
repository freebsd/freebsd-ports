--- server/fakerconfig.cpp.orig	2019-10-20 21:29:00 UTC
+++ server/fakerconfig.cpp
@@ -97,7 +97,7 @@ FakerConfig *fconfig_getinstance(void)
 			if((addr = shmat(fconfig_shmid, 0, 0)) == (void *)-1) THROW_UNIX();
 			if(!addr)
 				THROW("Could not attach to config structure in shared memory");
-			#ifdef linux
+			#if defined(linux) || defined(__FreeBSD__)
 			shmctl(fconfig_shmid, IPC_RMID, 0);
 			#endif
 			char *env = NULL;
