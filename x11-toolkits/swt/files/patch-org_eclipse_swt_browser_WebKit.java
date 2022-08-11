--- org/eclipse/swt/browser/WebKit.java.orig	2022-06-06 23:55:44 UTC
+++ org/eclipse/swt/browser/WebKit.java
@@ -121,7 +121,7 @@ class WebKit extends WebBrowser {
 	 * https://www.nczonline.net/blog/2009/01/05/what-determines-that-a-script-is-long-running/
 	 * https://stackoverflow.com/questions/3030024/maximum-execution-time-for-javascript
 	 */
-	static final int ASYNC_EXEC_TIMEOUT_MS = 10000;
+	static final int ASYNC_EXEC_TIMEOUT_MS = 100; // Dirty hack for webkit issues on FreeBSD
 
 	/** Workaround for bug 522733 */
 	static boolean bug522733FirstInstanceCreated = false;
