--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/ksysguardd.h	Mon Nov 19 17:07:38 2001
@@ -0,0 +1,34 @@
+/*
+    KSysGuard, the KDE System Guard
+   
+	Copyright (c) 1999-2001 Chris Schlaeger <cs@kde.org>
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
+	$Id: ksysguardd.h,v 1.2 2001/11/08 10:52:55 tokoe Exp $
+*/
+
+#ifndef _ksysguardd_h_
+#define _ksysguardd_h_
+
+#include <stdio.h>
+
+extern int QuitApp;
+extern int RunAsDaemon;
+extern FILE* CurrentClient;
+
+void updateModules(void);
+void checkModules(void);
+
+#endif
