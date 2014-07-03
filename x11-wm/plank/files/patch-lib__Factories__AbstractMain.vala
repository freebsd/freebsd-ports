--- ./lib/Factories/AbstractMain.vala.orig	2013-11-15 15:13:35.000000000 +0000
+++ ./lib/Factories/AbstractMain.vala	2014-05-23 18:39:31.000000000 +0000
@@ -163,7 +163,7 @@
 		protected virtual void initialize_program ()
 		{
 			// set program name
-			prctl (15, exec_name);
+			setproctitle (exec_name);
 			Environment.set_prgname (exec_name);
 			
 			Posix.signal(Posix.SIGINT, sig_handler);
