--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/logfile.h	Mon Nov 19 17:07:55 2001
@@ -0,0 +1,37 @@
+/*
+    KSysGuard, the KDE System Guard
+   
+	Copyright (c) 2001 Tobias Koenig <tokoe82@yahoo.de>
+    
+    This program is free software; you can redistribute it and/or
+    modify it under the terms of version 2 of the GNU General Public
+    License as published by the Free Software Foundation.
+
+    This program is distributed in the hope that it will be useful,
+    but WITHOUT ANY WARRANTY; without even the implied warranty of
+    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+    GNU General Public License for more details.
+
+    You should have received a copy of the GNU General Public License
+    along with this program; if not, write to the Free Software
+    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
+
+	$Id: logfile.h,v 1.2 2001/09/18 14:03:53 tokoe Exp $
+*/
+
+#ifndef _logfile_h_
+#define _logfile_h_
+
+void initLogFile(void);
+void exitLogFile(void);
+
+void printLogFile(const char* cmd);
+void printLogFileInfo(const char* cmd);
+
+void registerLogFile(const char* cmd);
+void unregisterLogFile(const char* cmd);
+
+/* debug command */
+void printRegistered(const char* cmd);
+
+#endif
