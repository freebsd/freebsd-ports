Index: xmovectrl/xmovectrl.c
@@ -33,6 +33,8 @@
 int auth_namelen, auth_datalen;
 char *auth_name, *auth_data;
 
+void DoServerSetup(int server_fd);
+
 main(int argc, char **argv, char **envp)
 {
      char **cur_argv = argv + 1;
@@ -143,6 +145,7 @@
 }     
 
 
+void
 DoServerSetup(int server_fd)
 {
      unsigned char iobuf[512];
