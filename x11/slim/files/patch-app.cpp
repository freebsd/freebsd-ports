--- app.cpp.orig	2013-10-01 18:38:05.000000000 -0400
+++ app.cpp	2014-12-18 00:18:29.000000000 -0500
@@ -14,6 +14,7 @@
 #include <unistd.h>
 #include <fcntl.h>
 #include <stdint.h>
+#include <login_cap.h>
 #include <cstring>
 #include <cstdio>
 #include <iostream>
@@ -32,6 +33,20 @@
 
 using namespace std;
 
+static const int LOGIN_CAP_VAR_COUNT = 4;
+static const char* LOGIN_CAP_VARS[] = {
+	"lang",
+	"charset",
+	"timezone",
+	"manpath",
+};
+static const char* LOGIN_CAP_ENVS[] = {
+	"LANG",
+	"MM_CHARSET",
+	"TZ",
+	"MANPATH",
+};
+
 #ifdef USE_PAM
 #include <string>
 
@@ -123,6 +138,22 @@
 	signal(sig, User1Signal);
 }
 
+static void AddToEnv(char*** curr_env, const char *name, const char *value) {
+	int n;
+	for (n = 0; (*curr_env)[n] != NULL; n++) ;
+	n++;
+	char** new_env = static_cast<char**>(malloc(sizeof(char*) * (n + 1)));
+	memcpy(new_env, *curr_env, sizeof(char*) * n);
+	char* entry = static_cast<char*>(malloc(strlen(name) + strlen(value) + 2));
+	strcpy(entry, name);
+	strcat(entry, "=");
+	strcat(entry, value);
+	new_env[n-1] = entry;
+	new_env[n] = NULL;
+	free(*curr_env);
+	*curr_env = new_env;
+}
+
 #ifdef USE_PAM
 App::App(int argc, char** argv)
   : pam(conv, static_cast<void*>(&LoginPanel)),
@@ -627,6 +658,17 @@
 
 #endif
 
+		login_cap_t *lc = login_getpwclass(pw);
+		if (lc != NULL) {
+			for (int i = 0; i < LOGIN_CAP_VAR_COUNT; i++) {
+				const char *value = login_getcapstr(lc, LOGIN_CAP_VARS[i], NULL, NULL);
+				if (value != NULL) {
+					AddToEnv(&child_env, LOGIN_CAP_ENVS[i], value);
+				}
+			}
+			login_close(lc);
+		}
+
 		/* Login process starts here */
 		SwitchUser Su(pw, cfg, DisplayName, child_env);
 		string session = LoginPanel->getSession();
@@ -941,7 +983,7 @@
 	}
 
 	if (!hasVtSet && daemonmode) {
-		server[argc++] = (char*)"vt07";
+		server[argc++] = (char*)"vt09";
 	}
 	server[argc] = NULL;
 
