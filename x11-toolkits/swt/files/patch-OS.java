--- org/eclipse/swt/internal/gtk/OS.java.orig	2018-03-01 07:35:24.000000000 +0100
+++ org/eclipse/swt/internal/gtk/OS.java	2018-06-27 11:17:53.291216000 +0200
@@ -20,19 +20,20 @@
 
 public class OS extends C {
 	/** OS Constants */
-	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX, IsWin32, BIG_ENDIAN;
+	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX, IsWin32, BIG_ENDIAN, IsFreeBSD;
 	static {
 
 		/* Initialize the OS flags and locale constants */
 		String osName = System.getProperty ("os.name");
-		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false, isWin32 = false;
+		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false, isWin32 = false, isFreeBSD = false;
 		if (osName.equals ("Linux")) isLinux = true;
 		if (osName.equals ("AIX")) isAIX = true;
 		if (osName.equals ("Solaris")) isSunOS = true;
 		if (osName.equals ("SunOS")) isSunOS = true;
 		if (osName.equals ("HP-UX")) isHPUX = true;
 		if (osName.startsWith("Windows")) isWin32 = true;
-		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsHPUX = isHPUX; IsWin32 = isWin32;
+		if (osName.equals ("FreeBSD")) isFreeBSD = true;
+		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsHPUX = isHPUX; IsWin32 = isWin32;  IsFreeBSD = isFreeBSD;
 
 		byte[] buffer = new byte[4];
 		long /*int*/ ptr = OS.malloc(4);
