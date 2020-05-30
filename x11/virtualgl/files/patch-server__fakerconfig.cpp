--- server/fakerconfig.cpp	2019-10-20 16:29:00.000000000 -0500
+++ server/fakerconfig.cpp	2020-04-14 10:37:51.384994000 -0500
@@ -97,7 +97,7 @@
 			if((addr = shmat(fconfig_shmid, 0, 0)) == (void *)-1) THROW_UNIX();
 			if(!addr)
 				THROW("Could not attach to config structure in shared memory");
-			#ifdef linux
+			#if defined(linux) || defined(__FreeBSD__)
 			shmctl(fconfig_shmid, IPC_RMID, 0);
 			#endif
 			char *env = NULL;
