--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/diskstat.h	Mon Nov 19 17:07:01 2001
@@ -0,0 +1,41 @@
+/*
+    KSysGuard, the KDE System Guard
+	   
+    Copyright (c) 2001 Tobias Koenig <tokoe82@yahoo.de>
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
+	$Id: diskstat.h,v 1.2 2001/09/18 14:03:53 tokoe Exp $
+*/
+
+#ifndef _diskstat_h_
+#define _diskstat_h_
+
+void initDiskStat(void);
+void exitDiskStat(void);
+
+int updateDiskStat(void);
+void checkDiskStat(void);
+
+void printDiskStat(const char* cmd);
+void printDiskStatInfo(const char* cmd);
+
+void printDiskStatUsed(const char* cmd);
+void printDiskStatUsedInfo(const char* cmd);
+void printDiskStatFree(const char* cmd);
+void printDiskStatFreeInfo(const char* cmd);
+void printDiskStatPercent(const char* cmd);
+void printDiskStatPercentInfo(const char* cmd);
+
+#endif
