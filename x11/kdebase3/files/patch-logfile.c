--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/logfile.c	Mon Nov 19 17:07:55 2001
@@ -0,0 +1,181 @@
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
+	$Id: logfile.c,v 1.2 2001/09/18 14:03:53 tokoe Exp $
+*/
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include "Command.h"
+#include "ccont.h"
+#include "conf.h"
+#include "ksysguardd.h"
+#include "logfile.h"
+
+static CONTAINER LogFiles = 0;
+static unsigned long counter = 1;
+
+typedef struct {
+	char name[256];
+	FILE* fh;
+	unsigned long id;
+} LogFileEntry;
+
+extern CONTAINER LogFileList;
+
+/*
+================================ public part =================================
+*/
+
+void initLogFile(void)
+{
+	int i;
+	char monitor[1024];
+
+	registerCommand("logfile_register", registerLogFile);
+	registerCommand("logfile_unregister", unregisterLogFile);
+	registerCommand("logfile_registered", printRegistered);
+
+	for (i = 0; i < level_ctnr(LogFileList); i++)
+	{
+		FILE* fp;
+		ConfigLogFile *entry = get_ctnr(LogFileList, i);
+		/* register the log file if we can actually read the file. */
+		if ((fp = fopen(entry->path, "r")) != NULL)
+		{
+			fclose(fp);
+			snprintf(monitor, 1024, "logfiles/%s", entry->name);
+			registerMonitor(monitor, "logfile", printLogFile,
+							printLogFileInfo);
+		}
+	}
+
+	LogFiles = new_ctnr(CT_DLL);
+}
+
+void exitLogFile(void)
+{
+	if (LogFiles)
+		destr_ctnr(LogFiles, free);
+}
+
+void printLogFile(const char* cmd)
+{
+	char line[1024];
+	unsigned long id;
+	int i;
+	char ch;
+	
+	sscanf(cmd, "%*s %lu", &id);
+
+	for (i = 0; i < level_ctnr(LogFiles); i++) {
+		LogFileEntry *entry = get_ctnr(LogFiles, i);
+
+		if (entry->id == id) {
+			while (fgets(line, sizeof(line), entry->fh) != NULL) {
+				fprintf(CurrentClient, "%s", line);
+			}
+			clearerr(entry->fh);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printLogFileInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "LogFile\n");
+}
+
+void registerLogFile(const char* cmd)
+{
+	char name[256];
+	FILE* file;
+	LogFileEntry *entry;
+	int i;
+
+	memset(name, 0, sizeof(name));
+	sscanf(cmd, "%*s %256s", name);
+	
+	for (i = 0; i < level_ctnr(LogFileList); i++) {
+		ConfigLogFile *conf = get_ctnr(LogFileList, i);
+		if (!strcmp(conf->name, name)) {
+			if ((file = fopen(conf->path, "r")) == NULL) {
+				print_error("fopen()");
+				fprintf(CurrentClient, "0\n");
+				return;
+			}
+
+			fseek(file, 0, SEEK_END);
+
+			if ((entry = (LogFileEntry *)malloc(sizeof(LogFileEntry))) == NULL) {
+				print_error("malloc()");
+				fprintf(CurrentClient, "0\n");
+				return;
+			}
+
+			entry->fh = file;
+			strncpy(entry->name, conf->name, 256);
+			entry->id = counter;
+
+			push_ctnr(LogFiles, entry);	
+
+			fprintf(CurrentClient, "%lu\n", counter);
+			counter++;
+
+			return;
+		}
+	}
+
+	fprintf(CurrentClient, "0\n");
+}
+
+void unregisterLogFile(const char* cmd)
+{
+	unsigned long id;
+	int i;
+
+	sscanf(cmd, "%*s %lu", &id);
+	
+	for (i = 0; i < level_ctnr(LogFiles); i++) {
+		LogFileEntry *entry = get_ctnr(LogFiles, i);
+
+		if (entry->id == id) {
+			fclose(entry->fh);
+			free(remove_ctnr(LogFiles, i));
+			fprintf(CurrentClient, "\n");
+			return;
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printRegistered(const char* cmd)
+{
+	int i;
+
+	for (i = 0; i < level_ctnr(LogFiles); i++) {
+		LogFileEntry *entry = get_ctnr(LogFiles, i);
+		fprintf(CurrentClient, "%s:%lu\n", entry->name, entry->id);
+	}
+
+	fprintf(CurrentClient, "\n");
+}
