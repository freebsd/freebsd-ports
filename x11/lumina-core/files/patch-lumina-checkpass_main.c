--- lumina-checkpass/main.c.orig	2021-12-26 02:33:45 UTC
+++ lumina-checkpass/main.c
@@ -18,11 +18,14 @@
 #include <stdio.h> 	// Usage output
 #include <pwd.h>  		// User DB information
 #include <string.h>
+#include <sysexits.h>
 
 //PAM/security libraries
 #include <sys/types.h>
 #include <security/pam_appl.h>
 
+#define	AUTH_FAILED	1
+
 //Found this little snippet from SDDM - nice alternative to using the entire openpam library from FreeBSD
 static int PAM_conv(
 	int num_msg,
@@ -30,18 +33,19 @@ static int PAM_conv(
 	struct pam_response **resp,
 	void *ctx)
 {
-	return 0;
+	return PAM_SUCCESS;
 }
 //-----
 
 
 void showUsage(){
-    puts("lumina-checkpass: Simple user-level check for password validity (for screen unlockers and such).");
-    puts("Usage:");
-    //puts("  lumina-checkpass <password>");
-    puts("  lumina-checkpass -fd <file descriptor>");
-    puts("  lumina-checkpass -f <file path>");
-    puts("Returns: 0 for a valid password, 1 for invalid");
+    fputs("lumina-checkpass: Simple user-level check for password validity (for screen unlockers and such).", stderr);
+    fputs("Usage:", stderr);
+    //fputs("  lumina-checkpass <password>", stderr);
+    fputs("  lumina-checkpass -fd <file descriptor>", stderr);
+    fputs("  lumina-checkpass -f <file path>", stderr);
+    fputs("Returns: 0 for a valid password, 1 for invalid", stderr);
+    exit(AUTH_FAILED);	// FIXME: Switch to EX_USAGE, or do callers depend on 1?
 }
 
 int main(int argc, char** argv){
@@ -49,13 +53,20 @@ int main(int argc, char** argv){
   if(argc!=3){
     //Invalid inputs - show the help text
     showUsage();
-    return 1;
   }
-  char*pass = 0;
+  char *pass = NULL;
   if(argc==3 && 0==strcmp(argv[1],"-fd") ){
-    FILE *fp = fdopen(atoi(argv[2]), "r");
+    // This replaces dangerous atoi(), which does no validation
+    char *end;
+    int fd = strtol(argv[2], &end, 10);
+    if ( *end != '\0' )
+    {
+      fprintf(stderr, "Invalid file descriptor: %s\n", argv[2]);
+      showUsage();
+    }
+    FILE *fp = fdopen(fd, "r");
     size_t len;
-    if(fp!=0){
+    if(fp!=NULL){
       ssize_t slen = getline(&pass, &len, fp);
       if(pass[slen-1]=='\n'){ pass[slen-1] = '\0'; }
     }
@@ -63,26 +74,25 @@ int main(int argc, char** argv){
   }else if(argc==3 && 0==strcmp(argv[1],"-f") ){
     FILE *fp = fopen(argv[2], "r");
     size_t len;
-    if(fp!=0){
+    if(fp!=NULL){
       ssize_t slen = getline(&pass, &len, fp);
       if(pass[slen-1]=='\n'){ pass[slen-1] = '\0'; }
     }else{
-      puts("[ERROR] Unknown option provided");
-      puts("----------------");
+      fputs("[ERROR] Unknown option provided", stderr);
+      fputs("----------------", stderr);
       showUsage();
-      return 1;
     }
     fclose(fp);
   }
-  if(pass == 0){ puts("Could not read password!!"); return 1; } //error in reading password
+  if(pass == NULL){ fputs("Could not read password!!", stderr); return AUTH_FAILED; } //error in reading password
   //puts("Read Password:");
   //puts(pass);
   //Validate current user (make sure current UID matches the logged-in user,
   char* cUser = getlogin();
-  struct passwd *pwd = 0;
+  struct passwd *pwd = NULL;
   pwd = getpwnam(cUser);
-  if(pwd==0){ return 1; } //Login user could not be found in the database? (should never happen)
-  if( getuid() != pwd->pw_uid ){ return 1; } //Current UID does not match currently logged-in user UID
+  if(pwd==NULL){ return AUTH_FAILED; } //Login user could not be found in the database? (should never happen)
+  if( getuid() != pwd->pw_uid ){ return AUTH_FAILED; } //Current UID does not match currently logged-in user UID
   //Create the non-interactive PAM structures
   pam_handle_t *pamh;
   struct pam_conv pamc = { &PAM_conv, 0 };
@@ -92,15 +102,15 @@ int main(int argc, char** argv){
 #else
     int ret = pam_start( "system-auth", cUser, &pamc, &pamh);
 #endif
-    if(ret != PAM_SUCCESS){ puts("Could not initialize PAM"); return 1; } //could not init PAM
+    if(ret != PAM_SUCCESS){ fputs("Could not initialize PAM", stderr); return AUTH_FAILED; } //could not init PAM
     //char* cPassword = argv[1];
     ret = pam_set_item(pamh, PAM_AUTHTOK, pass);
-    if(ret != PAM_SUCCESS){ puts("Could not set conversation structure"); }
+    if(ret != PAM_SUCCESS){ fputs("Could not set conversation structure", stderr); }
     //Authenticate with PAM
     ret = pam_authenticate(pamh,0); //this can be true without verifying password if pam_self.so is used in the auth procedures (common)
     if( ret == PAM_SUCCESS ){ ret = pam_acct_mgmt(pamh,0); } //Check for valid, unexpired account and verify access restrictions
     //Stop the PAM instance
     pam_end(pamh,ret);
   //return verification result
-  return ((ret==PAM_SUCCESS) ? 0 : 1);
+  return ret == PAM_SUCCESS ? EX_OK : AUTH_FAILED;
 }
