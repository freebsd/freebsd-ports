--- src/icesound.cc.orig	Sun May 23 15:18:19 2004
+++ src/icesound.cc	Wed Aug  4 23:45:45 2004
@@ -190,7 +190,8 @@
     virtual int init(int & argc, char **& argv);
     
 private:
-    friend class CommandLine : public YCommandLine {
+    friend class CommandLine;
+    class CommandLine : public YCommandLine {
     public:
 	CommandLine(int & argc, char **& argv, YOSSAudio & oss):
 	    YCommandLine(argc, argv), oss(oss) {}
@@ -226,6 +227,7 @@
 	YOSSAudio & oss;
     };
 
+    friend class CommandLine;
     char const * device;
 };
 
@@ -326,7 +328,8 @@
     virtual int init(int & argc, char **& argv);
 
 private:
-    friend class CommandLine : public YCommandLine {
+    friend class CommandLine;
+    class CommandLine : public YCommandLine {
     public:
 	CommandLine(int & argc, char **& argv, YESDAudio & esd):
 	    YCommandLine(argc, argv), esd(esd) {}
@@ -364,6 +367,7 @@
     };
 
 protected:
+    friend class CommandLine;
     char const * speaker;
     int sample[ACOUNT(gui_events)];	// cache sample ids
     int socket;				// socket to ESound Daemon
@@ -502,7 +506,8 @@
     	      Coefficient lVol = 1.0, Coefficient rVol = 1.0);
 
 private:
-    friend class CommandLine : public YCommandLine {
+    friend class CommandLine;
+    class CommandLine : public YCommandLine {
     public:
 	CommandLine(int & argc, char **& argv, YY2Audio & yiff):
 	    YCommandLine(argc, argv), yiff(yiff) {}
