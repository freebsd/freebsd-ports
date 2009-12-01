--- org/eclipse/swt/internal/C.java.orig	2009-07-11 08:21:27.000000000 -0500
+++ org/eclipse/swt/internal/C.java	2009-07-11 08:22:21.000000000 -0500
@@ -13,9 +13,9 @@
 public class C extends Platform {
 
 	static {
-		if ("Linux".equals (System.getProperty ("os.name")) && "motif".equals (Platform.PLATFORM)) { //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
+		if ("FreeBSD".equals (System.getProperty ("os.name")) && "motif".equals (Platform.PLATFORM)) { //$NON-NLS-1$ //$NON-NLS-2$ //$NON-NLS-3$
 			try {
-				Library.loadLibrary ("libXm.so.2", false); //$NON-NLS-1$
+				Library.loadLibrary ("libXm.so.3", false); //$NON-NLS-1$
 			} catch (Throwable ex) {}
 		}
 		Library.loadLibrary ("swt"); //$NON-NLS-1$
