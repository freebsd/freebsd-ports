From 1027d5df07398c1507fb1fe3a9981aa6b4bc3a56 Mon Sep 17 00:00:00 2001
From: Matthias Hopf <mhopf@suse.de>
Date: Tue, 01 Mar 2011 18:37:34 +0000
Subject: Create shell-escape-safe cpp options in the non-pathetic-cpp case.

Fixes CVE-2011-0465.

Signed-off-by: Matthias Hopf <mhopf@suse.de>
Reviewed-by: Adam Jackson <ajax@redhat.com>
---
diff --git a/xrdb.c b/xrdb.c
index c3ef0fd..ea698b9 100644
--- xrdb.c
+++ xrdb.c
@@ -142,6 +142,8 @@ static Entries newDB;
 
 static void fatal(char *, ...);
 static void addstring ( String *arg, const char *s );
+static void addescapedstring ( String *arg, const char *s );
+static void addtokstring ( String *arg, const char *s );
 static void FormatEntries ( Buffer *buffer, Entries *entries );
 static void StoreProperty ( Display *dpy, Window root, Atom res_prop );
 static void Process ( int scrno, Bool doScreen, Bool execute );
@@ -433,14 +435,20 @@ AddDef(String *buff, char *title, char *value)
 	    addstring(buff, " -D");
     } else
 	addstring(buff, "-D");
-    addstring(buff, title);
+    addtokstring(buff, title);
     if (value && (value[0] != '\0')) {
 	addstring(buff, "=");
-	addstring(buff, value);
+	addescapedstring(buff, value);
     }
 }
 
 static void
+AddSimpleDef(String *buff, char *title)
+{
+    AddDef(buff, title, (char *)NULL);
+}
+
+static void
 AddDefQ(String *buff, char *title, char *value)
 {
 #ifdef PATHETICCPP
@@ -449,8 +457,9 @@ AddDefQ(String *buff, char *title, char *value)
     else
 #endif
     if (value && (value[0] != '\0')) {
-	AddDef(buff, title, "\"");
-	addstring(buff, value);
+	AddSimpleDef(buff, title);
+	addstring(buff, "=\"");
+	addescapedstring(buff, value);
 	addstring(buff, "\"");
     } else
 	AddDef(buff, title, NULL);
@@ -465,24 +474,28 @@ AddNum(String *buff, char *title, int value)
 }
 
 static void
-AddSimpleDef(String *buff, char *title)
+AddDefTok(String *buff, char *prefix, char *title)
 {
-    AddDef(buff, title, (char *)NULL);
+    char name[512];
+
+    snprintf(name, sizeof(name), "%s%s", prefix, title);
+    AddSimpleDef(buff, name);
 }
 
 static void
-AddDefTok(String *buff, char *prefix, char *title)
+AddDefHostname(String *buff, char *title, char *value)
 {
     char *s;
     char name[512];
     char c;
 
-    snprintf(name, sizeof(name), "%s%s", prefix, title);
+    strncpy (name, value, sizeof(name)-1);
+    name[sizeof(name)-1] = '\0';
     for (s = name; (c = *s); s++) {
-	if (!isalpha(c) && !isdigit(c) && c != '_')
+	if (!isalpha(c) && !isdigit(c) && c != '_' && c != '.' && c != ':' && c != '-')
 	    *s = '_';
     }
-    AddSimpleDef(buff, name);
+    AddDef(buff, title, name);
 }
 
 static void
@@ -502,7 +515,7 @@ AddUndef(String *buff, char *title)
 	    addstring(buff, " -U");
     } else
 	addstring(buff, "-U");
-    addstring(buff, title);
+    addtokstring(buff, title);
 }
 
 static void 
@@ -565,11 +578,11 @@ DoDisplayDefines(Display *display, String *defs, char *host)
     }
     if (!*server || !strcmp(server, "unix") || !strcmp(server, "localhost"))
 	strcpy(server, client);
-    AddDef(defs, "HOST", server); /* R3 compatibility */
-    AddDef(defs, "SERVERHOST", server);
+    AddDefHostname(defs, "HOST", server); /* R3 compatibility */
+    AddDefHostname(defs, "SERVERHOST", server);
     AddDefTok(defs, "SRVR_", server);
     AddNum(defs, "DISPLAY_NUM", n);
-    AddDef(defs, "CLIENTHOST", client);
+    AddDefHostname(defs, "CLIENTHOST", client);
     AddDefTok(defs, "CLNT_", client);
     AddNum(defs, "VERSION", ProtocolVersion(display));
     AddNum(defs, "REVISION", ProtocolRevision(display));
@@ -612,7 +625,7 @@ DoScreenDefines(Display *display, int scrno, String *defs)
     AddNum(defs, "Y_RESOLUTION", Resolution(screen->height,screen->mheight));
     AddNum(defs, "PLANES", DisplayPlanes(display, scrno));
     AddNum(defs, "BITS_PER_RGB", visual->bits_per_rgb);
-    AddDef(defs, "CLASS", ClassNames[visual->class]);
+    AddDefQ(defs, "CLASS", ClassNames[visual->class]);
     snprintf(name, sizeof(name), "CLASS_%s", ClassNames[visual->class]);
     AddNum(defs, name, (int)visual->visualid);
     switch(visual->class) {
@@ -780,6 +793,40 @@ addstring(String *arg, const char *s)
     arg->used += strlen(s);
 }   
 
+static void
+addescapedstring(String *arg, const char *s)
+{
+    char copy[512], *c;
+
+    for (c = copy; *s && c < &copy[sizeof(copy)-1]; s++) {
+	switch (*s) {
+	case '"':       case '\'':      case '`':
+	case '$':       case '\\':
+	    *c++ = '_';
+	    break;
+	default:
+	    *c++ = *s;
+	}
+    }
+    *c = 0;
+    addstring (arg, copy);
+}
+
+static void
+addtokstring(String *arg, const char *s)
+{
+    char copy[512], *c;
+
+    for (c = copy; *s && c < &copy[sizeof(copy)-1]; s++) {
+	if (!isalpha(*s) && !isdigit(*s) && *s != '_')
+	    *c++ = '_';
+	else
+	    *c++ = *s;
+    }
+    *c = 0;
+    addstring (arg, copy);
+}
+
 
 int
 main(int argc, char *argv[])
@@ -892,7 +939,7 @@ main(int argc, char *argv[])
 		continue;
 	    } else if (arg[1] == 'I') {
 		addstring(&includes, " ");
-		addstring(&includes, arg);
+		addescapedstring(&includes, arg);
 		continue;
 	    } else if (arg[1] == 'U' || arg[1] == 'D') {
 		if (num_cmd_defines < MAX_CMD_DEFINES) {
--
cgit v0.8.3-6-g21f6
