--- kinit/start_kdeinit_wrapper.c.orig	2007-10-29 22:49:04.000000000 +0100
+++ kinit/start_kdeinit_wrapper.c	2007-10-29 22:49:21.000000000 +0100
@@ -85,7 +85,7 @@
    if(argc == 0)
       return 1;
    argv[0] = "start_kdeinit";
-   execv("start_kdeinit",argv);
+   execvp("start_kdeinit",argv);
    perror("start_kdeinit");
    return 1;
 }
