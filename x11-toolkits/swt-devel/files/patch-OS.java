--- ./org/eclipse/swt/internal/gtk/OS.java.orig	Thu Dec 15 15:19:38 2005
+++ ./org/eclipse/swt/internal/gtk/OS.java	Mon Jan 23 23:51:20 2006
@@ -20,18 +20,20 @@
 	}
 	
 	/** OS Constants */
-	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX;
+	public static final boolean IsAIX, IsSunOS, IsLinux, IsHPUX, IsFreeBSD;
 	static {
 		
 		/* Initialize the OS flags and locale constants */
+		/* make bootstrap compatible with `uname -s` for FreeBSD */
 		String osName = System.getProperty ("os.name");
-		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false;
+		boolean isAIX = false, isSunOS = false, isLinux = false, isHPUX = false, isFreeBSD = false;
 		if (osName.equals ("Linux")) isLinux = true;
+		if (osName.equals ("FreeBSD")) isFreeBSD = true;
 		if (osName.equals ("AIX")) isAIX = true;
 		if (osName.equals ("Solaris")) isSunOS = true;
 		if (osName.equals ("SunOS")) isSunOS = true;
 		if (osName.equals ("HP-UX")) isHPUX = true;
-		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsHPUX = isHPUX;
+		IsAIX = isAIX;  IsSunOS = isSunOS;  IsLinux = isLinux;  IsFreeBSD = isFreeBSD;  IsHPUX = isHPUX;
 	}
 
 	/** Constants */
