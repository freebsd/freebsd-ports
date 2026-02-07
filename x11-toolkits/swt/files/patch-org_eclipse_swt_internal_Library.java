--- org/eclipse/swt/internal/Library.java.orig	2021-09-06 01:22:24 UTC
+++ org/eclipse/swt/internal/Library.java
@@ -65,12 +65,12 @@ static {
 
 static String arch() {
 	String osArch = System.getProperty("os.arch"); //$NON-NLS-1$
-	if (osArch.equals ("amd64")) return "x86_64"; //$NON-NLS-1$ $NON-NLS-2$
 	return osArch;
 }
 
 static String os() {
 	String osName = System.getProperty("os.name"); //$NON-NLS-1$
+	if (osName.equals ("FreeBSD")) return "freebsd"; //$NON-NLS-1$ $NON-NLS-2$
 	if (osName.equals ("Linux")) return "linux"; //$NON-NLS-1$ $NON-NLS-2$
 	if (osName.equals ("Mac OS X")) return "macosx"; //$NON-NLS-1$ $NON-NLS-2$
 	if (osName.startsWith ("Win")) return "win32"; //$NON-NLS-1$ $NON-NLS-2$
