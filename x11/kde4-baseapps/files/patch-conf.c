--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/conf.c	Mon Nov 19 17:06:50 2001
@@ -0,0 +1,133 @@
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
+	$Id: conf.c,v 1.3 2001/11/05 23:24:19 tokoe Exp $
+*/
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+
+#include "Command.h"
+#include "ccont.h"
+#include "conf.h"
+
+CONTAINER LogFileList = 0;
+CONTAINER SensorList = 0;
+
+void parseConfigFile(const char *filename)
+{
+	FILE* config;
+	char line[2048];
+	char *begin, *token, *tmp, *confSensor;
+	ConfigLogFile *confLog;
+	
+
+	if (LogFileList)
+		destr_ctnr(LogFileList, free);
+
+	if (SensorList)
+		destr_ctnr(SensorList, free);
+
+	LogFileList = new_ctnr(CT_DLL);
+	SensorList = new_ctnr(CT_DLL);
+
+	if ((config = fopen(filename, "r")) == NULL) {
+		log_error("can't open config file '%s'", filename);
+
+		/* if we can't open a config file we have to add the
+		   available sensors manually
+		*/
+
+		confSensor = strdup("ProcessList");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("Memory");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("Stat");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("NetDev");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("NetStat");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("CpuInfo");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("LoadAvg");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("DiskStat");
+		push_ctnr(SensorList, confSensor);
+		confSensor = strdup("LogFile");
+		push_ctnr(SensorList, confSensor);
+
+		return;
+	}
+
+	while (fgets(line, sizeof(line), config) != NULL) {
+		if ((line[0] == '#') || (strlen(line) == 0)) {
+			continue;
+		}
+
+		if (strchr(line, '#'))
+			*(strchr(line, '#')) = '\0';
+
+		if (line[strlen(line) - 1] == '\n')
+			line[strlen(line) - 1] = '\0';
+
+		if (!strncmp(line, "LogFiles", 8)) {
+			begin = strchr(line, '=');
+			begin++;
+
+			for (token = strtok(begin, ","); token; token = strtok(NULL, ",")) {
+				if ((confLog = (ConfigLogFile *)malloc(sizeof(ConfigLogFile))) == NULL) {
+					log_error("malloc() no free memory avail");
+					continue;
+				}
+				confLog->name = strdup(token);
+				tmp = strchr(confLog->name, ':');
+				*tmp = '\0';
+				confLog->path = tmp;
+				confLog->path++;
+
+				push_ctnr(LogFileList, confLog);
+			}
+		}
+		if (!strncmp(line, "Sensors", 7)) {
+			begin = strchr(line, '=');
+			begin++;
+
+			for (token = strtok(begin, ","); token; token = strtok(NULL, ",")) {
+				confSensor = strdup(token);
+				push_ctnr(SensorList, confSensor);
+			}
+		}
+	}
+
+	fclose(config);
+}
+
+int sensorAvailable(const char *sensor)
+{
+	int i;
+	
+	for (i = 0; i < level_ctnr(SensorList); i++) {
+		char* name = get_ctnr(SensorList, i);
+		if (!strcmp(name, sensor))
+			return 1;
+	}
+
+	return 0;
+}
