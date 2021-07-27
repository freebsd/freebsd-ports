--- org/eclipse/swt/internal/gtk/OS.java.orig	2021-06-11 17:24:22 UTC
+++ org/eclipse/swt/internal/gtk/OS.java
@@ -61,15 +61,16 @@ import org.eclipse.swt.internal.*;
  */
 public class OS extends C {
 	/** OS Constants */
-	public static final boolean IsLinux, IsWin32, BIG_ENDIAN;
+	public static final boolean IsLinux, IsWin32, BIG_ENDIAN, IsFreeBSD;
 	static {
 
 		/* Initialize the OS flags and locale constants */
 		String osName = System.getProperty ("os.name");
-		boolean isLinux = false, isWin32 = false;
+		boolean isLinux = false, isWin32 = false, isFreeBSD = false;
 		if (osName.equals ("Linux")) isLinux = true;
 		if (osName.startsWith("Windows")) isWin32 = true;
-		IsLinux = isLinux;  IsWin32 = isWin32;
+		if (osName.equals ("FreeBSD")) isFreeBSD = true;
+		IsLinux = isLinux;  IsWin32 = isWin32;  IsFreeBSD = isFreeBSD;
 
 		byte[] buffer = new byte[4];
 		long ptr = C.malloc(4);
