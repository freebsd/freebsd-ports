--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/diskstat.c	Mon Nov 19 17:07:01 2001
@@ -0,0 +1,257 @@
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
+	$Id: diskstat.c,v 1.2 2001/09/18 14:03:53 tokoe Exp $
+*/
+
+#include <stdio.h>
+#include <stdlib.h>
+#include <string.h>
+#include <sys/param.h>
+#include <sys/stat.h>
+#include <sys/ucred.h>
+#include <sys/mount.h>
+#include <time.h>
+#include <unistd.h>
+
+#include "Command.h"
+#include "ccont.h"
+#include "diskstat.h"
+#include "ksysguardd.h"
+
+typedef struct {
+	char device[256];
+	char mntpnt[256];
+	long blocks;
+	long bfree;
+	long bused;
+	int bused_percent;
+} DiskInfo;
+
+static CONTAINER DiskStatList = 0;
+
+char *getMntPnt(const char *cmd)
+{
+	static char device[1024];
+	char *ptr;
+
+	memset(device, 0, sizeof(device));
+	sscanf(cmd, "partitions%1024s", device);
+
+	ptr = (char *)rindex(device, '/');
+	*ptr = '\0';
+		
+	return (char *)device;
+}
+
+int numMntPnt(void)
+{
+	struct statfs *fs_info;
+	int i, n, counter = 0;
+
+	n = getmntinfo(&fs_info, MNT_WAIT);
+	for (i = 0; i < n; i++)
+		if (strcmp(fs_info[i].f_fstypename, "procfs") && strcmp(fs_info[i].f_fstypename, "swap") && strcmp(fs_info[i].f_fstypename, "devfs"))
+			counter++;
+
+	return counter;
+}
+
+/* ------------------------------ public part --------------------------- */
+
+void initDiskStat(void)
+{
+	char monitor[1024];
+	int i;
+
+	DiskStatList = new_ctnr(CT_DLL);
+
+	updateDiskStat();
+
+	registerMonitor("partitions/list", "listview", printDiskStat, printDiskStatInfo);
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		DiskInfo* disk_info = get_ctnr(DiskStatList, i);
+		snprintf(monitor, sizeof(monitor), "partitions%s/usedspace", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatUsed, printDiskStatUsedInfo);
+		snprintf(monitor, sizeof(monitor), "partitions%s/freespace", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatFree, printDiskStatFreeInfo);
+		snprintf(monitor, sizeof(monitor), "partitions%s/filllevel", disk_info->mntpnt);
+		registerMonitor(monitor, "integer", printDiskStatPercent, printDiskStatPercentInfo);
+	}
+}
+
+void checkDiskStat(void)
+{
+	if (numMntPnt() != level_ctnr(DiskStatList)) {
+		/* a filesystem was mounted or unmounted
+		   so we do a reset */
+		exitDiskStat();
+		initDiskStat();
+	}
+}
+
+void exitDiskStat(void)
+{
+	DiskInfo *disk_info;
+	char monitor[1024];
+	int i;
+
+	removeMonitor("partitions/list");
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		disk_info = remove_ctnr(DiskStatList, i--);
+
+		snprintf(monitor, sizeof(monitor), "partitions%s/usedspace", disk_info->mntpnt);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "partitions%s/freespace", disk_info->mntpnt);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "partitions%s/filllevel", disk_info->mntpnt);
+		removeMonitor(monitor);
+
+		free(disk_info);
+	}
+
+	if (DiskStatList)
+		destr_ctnr(DiskStatList, free);
+}
+
+int updateDiskStat(void)
+{
+	struct statfs *fs_info;
+	struct statfs fs;
+	float percent;
+	int i, mntcount;
+	DiskInfo *disk_info;
+
+	/* let's hope there is no difference between the DiskStatList and
+	   the number of mounted filesystems */
+	for (i = 0; i < level_ctnr(DiskStatList); i++)
+		free(remove_ctnr(DiskStatList, i--));
+
+	mntcount = getmntinfo(&fs_info, MNT_WAIT);
+
+	for (i = 0; i < mntcount; i++) {
+		fs = fs_info[i];
+		if (strcmp(fs.f_fstypename, "procfs") && strcmp(fs.f_fstypename, "devfs") && strcmp(fs.f_fstypename, "devfs")) {
+			percent = (((float)fs.f_blocks - (float)fs.f_bfree)/(float)fs.f_blocks);
+			percent = percent * 100;
+			if ((disk_info = (DiskInfo *)malloc(sizeof(DiskInfo))) == NULL) {
+				continue;
+			}
+			memset(disk_info, 0, sizeof(DiskInfo));
+			strncpy(disk_info->device, fs.f_mntfromname, 255);
+			if (!strcmp(fs.f_mntonname, "/")) {
+				strncpy(disk_info->mntpnt, "/root", 6);
+			} else {
+				strncpy(disk_info->mntpnt, fs.f_mntonname, 255);
+			}
+			disk_info->blocks = fs.f_blocks;
+			disk_info->bfree = fs.f_bfree;
+			disk_info->bused = (fs.f_blocks - fs.f_bfree);
+			disk_info->bused_percent = (int)percent;
+
+			push_ctnr(DiskStatList, disk_info);
+		}
+	}
+	
+	return 0;
+}
+
+void printDiskStat(const char* cmd)
+{
+	int i;
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		DiskInfo* disk_info = get_ctnr(DiskStatList, i);
+		fprintf(CurrentClient, "%s\t%ld\t%ld\t%ld\t%d\t%s\n",
+			disk_info->device,
+			disk_info->blocks,
+			disk_info->bused,
+			disk_info->bfree,
+			disk_info->bused_percent,
+			disk_info->mntpnt);
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Device\tBlocks\tUsed\tAvailable\tUsed %%\tMountPoint\n");
+}
+
+void printDiskStatUsed(const char* cmd)
+{
+	int i;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		DiskInfo* disk_info = get_ctnr(DiskStatList, i);
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%ld\n", disk_info->bused);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatUsedInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Used Blocks\t0\t-\tBlocks\n");
+}
+
+void printDiskStatFree(const char* cmd)
+{
+	int i;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		DiskInfo* disk_info = get_ctnr(DiskStatList, i);
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%ld\n", disk_info->bfree);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatFreeInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Free Blocks\t0\t-\tBlocks\n");
+}
+
+void printDiskStatPercent(const char* cmd)
+{
+	int i;
+	char *mntpnt = (char *)getMntPnt(cmd);
+
+	for (i = 0; i < level_ctnr(DiskStatList); i++) {
+		DiskInfo* disk_info = get_ctnr(DiskStatList, i);
+		if (!strcmp(mntpnt, disk_info->mntpnt)) {
+			fprintf(CurrentClient, "%d\n", disk_info->bused_percent);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printDiskStatPercentInfo(const char* cmd)
+{
+	fprintf(CurrentClient, "Used Blocks\t0\t100\t%%\n");
+}
