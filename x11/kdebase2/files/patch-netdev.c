--- /dev/null	Mon Nov 19 17:14:17 2001
+++ ksysguard/ksysguardd/FreeBSD/netdev.c	Mon Nov 19 17:08:04 2001
@@ -0,0 +1,319 @@
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
+	$Id: netdev.c,v 1.2 2001/09/18 14:03:53 tokoe Exp $
+*/
+
+#include <fcntl.h>
+#include <sys/socket.h>
+#include <net/if.h>
+#include <net/if_mib.h>
+#include <stdio.h>
+#include <string.h>
+#include <sys/sysctl.h>
+#include <sys/time.h>
+#include <sys/types.h>
+#include <unistd.h>
+
+
+#include "Command.h"
+#include "ksysguardd.h"
+#include "netdev.h"
+
+
+typedef struct {
+	char name[32];
+	u_long recBytes;
+	u_long recPacks;
+	u_long recErrs;
+	u_long recDrop;
+	u_long recMulticast;
+	u_long sentBytes;
+	u_long sentPacks;
+	u_long sentErrs;
+	u_long sentMulticast;
+	u_long sentColls;
+} NetDevInfo;
+
+#define MAXNETDEVS 64
+static NetDevInfo NetDevs[MAXNETDEVS];
+static int NetDevCnt = 0;
+
+char **parseCommand(const char *cmd)
+{
+	char tmp_cmd[1024];
+	char *begin;
+	static char sensor[100];
+	static char interface[100];
+	static char* retval[2];
+
+	strncpy(tmp_cmd, cmd, 1024);
+
+	begin = rindex(tmp_cmd, '/');
+	*begin = '\0';
+	begin++;
+	strcpy(sensor, begin);
+	retval[1] = sensor;
+
+	begin = rindex(tmp_cmd, '/');
+	*begin = '\0';
+	begin = rindex(tmp_cmd, '/');
+	begin++;
+	strcpy(interface, begin);
+	retval[0] = interface;
+
+	return retval;
+}
+
+int numActivIfaces(void)
+{
+	int counter = 0;
+	int name[6];
+	int num_iface, i;
+	size_t len;
+	struct ifmibdata ifmd;
+
+	len = sizeof(num_iface);
+	sysctlbyname("net.link.generic.system.ifcount", &num_iface, &len, NULL, 0);
+
+	for (i = 1; i < num_iface + 1; i++) {
+		name[0] = CTL_NET;
+		name[1] = PF_LINK;
+		name[2] = NETLINK_GENERIC;
+		name[3] = IFMIB_IFDATA;
+		name[4] = i;
+		name[5] = IFDATA_GENERAL;
+
+		len = sizeof(ifmd);
+		sysctl(name, 6, &ifmd, &len, NULL, 0);
+		if (ifmd.ifmd_flags & IFF_UP)
+			counter++;
+	}
+
+	return counter;
+}
+
+/* ------------------------------ public part --------------------------- */
+
+void initNetDev(void)
+{
+	int i;
+	char monitor[1024];
+
+	updateNetDev();
+	
+	for (i = 0; i < NetDevCnt; i++) {
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/data", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevRecBytes, printNetDevRecBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/packets", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevRecBytes, printNetDevRecBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/errors", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevRecBytes, printNetDevRecBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/drops", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevRecBytes, printNetDevRecBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/multicast", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevRecBytes, printNetDevRecBytesInfo);
+
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/data", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevSentBytes, printNetDevSentBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/packets", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevSentBytes, printNetDevSentBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/errors", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevSentBytes, printNetDevSentBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/multicast", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevSentBytes, printNetDevSentBytesInfo);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/collisions", NetDevs[i].name);
+		registerMonitor(monitor, "integer", printNetDevSentBytes, printNetDevSentBytesInfo);
+	}
+}
+
+void exitNetDev(void)
+{
+	int i;
+	char monitor[1024];
+
+	for (i = 0; i < NetDevCnt; i++) {
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/data", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/packets", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/errors", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/drops", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/receiver/multicast", NetDevs[i].name);
+		removeMonitor(monitor);
+
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/data", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/packets", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/errors", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/multicast", NetDevs[i].name);
+		removeMonitor(monitor);
+		snprintf(monitor, sizeof(monitor), "network/interfaces/%s/transmitter/collisions", NetDevs[i].name);
+		removeMonitor(monitor);
+	}
+}
+
+void updateNetDev(void)
+{
+	int name[6];
+	int num_iface, i;
+	size_t len;
+	struct ifmibdata ifmd;
+
+	len = sizeof(num_iface);
+	sysctlbyname("net.link.generic.system.ifcount", &num_iface, &len, NULL, 0);
+
+	NetDevCnt = 0;
+	for (i = 1; i < num_iface + 1; i++) {
+		name[0] = CTL_NET;
+		name[1] = PF_LINK;
+		name[2] = NETLINK_GENERIC;
+		name[3] = IFMIB_IFDATA;
+		name[4] = i;
+		name[5] = IFDATA_GENERAL;
+
+		len = sizeof(ifmd);
+		sysctl(name, 6, &ifmd, &len, NULL, 0);
+		if (ifmd.ifmd_flags & IFF_UP) {
+			strncpy(NetDevs[NetDevCnt].name, ifmd.ifmd_name, 32);
+			NetDevs[NetDevCnt].recBytes = ifmd.ifmd_data.ifi_ibytes - NetDevs[NetDevCnt].recBytes;
+			NetDevs[NetDevCnt].recPacks = ifmd.ifmd_data.ifi_ipackets - NetDevs[NetDevCnt].recPacks;
+			NetDevs[NetDevCnt].recErrs = ifmd.ifmd_data.ifi_ierrors - NetDevs[NetDevCnt].recErrs;
+			NetDevs[NetDevCnt].recDrop = ifmd.ifmd_data.ifi_iqdrops - NetDevs[NetDevCnt].recDrop;
+			NetDevs[NetDevCnt].recMulticast = ifmd.ifmd_data.ifi_imcasts - NetDevs[NetDevCnt].recMulticast;
+			NetDevs[NetDevCnt].sentBytes = ifmd.ifmd_data.ifi_obytes - NetDevs[NetDevCnt].sentBytes;
+			NetDevs[NetDevCnt].sentPacks = ifmd.ifmd_data.ifi_opackets - NetDevs[NetDevCnt].sentPacks;
+			NetDevs[NetDevCnt].sentErrs = ifmd.ifmd_data.ifi_oerrors - NetDevs[NetDevCnt].sentErrs;
+			NetDevs[NetDevCnt].sentMulticast = ifmd.ifmd_data.ifi_omcasts - NetDevs[NetDevCnt].sentMulticast;
+			NetDevs[NetDevCnt].sentColls = ifmd.ifmd_data.ifi_collisions - NetDevs[NetDevCnt].sentColls;
+			NetDevCnt++;
+		}
+	}
+}
+
+void checkNetDev(void)
+{
+	if (numActivIfaces() != NetDevCnt) {
+		/* interface has been added or removed
+		   so we do a reset */
+		exitNetDev();
+		initNetDev();
+	}
+}
+
+void printNetDevRecBytes(const char *cmd)
+{
+	int i;
+	char **retval;
+	
+	retval = parseCommand(cmd);
+	
+	if (retval[0] == NULL || retval[1] == NULL)
+		return;
+
+	for (i = 0; i < NetDevCnt; i++) {
+		if (!strcmp(NetDevs[i].name, retval[0])) {
+			if (!strncmp(retval[1], "data", 4))
+				fprintf(CurrentClient, "%lu", NetDevs[i].recBytes);
+			if (!strncmp(retval[1], "packets", 7))
+				fprintf(CurrentClient, "%lu", NetDevs[i].recPacks);
+			if (!strncmp(retval[1], "errors", 6))
+				fprintf(CurrentClient, "%lu", NetDevs[i].recErrs);
+			if (!strncmp(retval[1], "drops", 5))
+				fprintf(CurrentClient, "%lu", NetDevs[i].recDrop);
+			if (!strncmp(retval[1], "multicast", 9))
+				fprintf(CurrentClient, "%lu", NetDevs[i].recMulticast);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printNetDevRecBytesInfo(const char *cmd)
+{
+	char **retval;
+	
+	retval = parseCommand(cmd);
+	
+	if (retval[1] == NULL)
+		return;
+
+	if (!strncmp(retval[1], "data", 4))
+		fprintf(CurrentClient, "Received Data\t0\t0\tkBytes/s\n");
+	if (!strncmp(retval[1], "packets", 7))
+		fprintf(CurrentClient, "Received Packets\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "errors", 6))
+		fprintf(CurrentClient, "Receiver Errors\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "drops", 5))
+		fprintf(CurrentClient, "Receiver Drops\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "multicast", 9))
+		fprintf(CurrentClient, "Received Multicast Packets\t0\t0\t1/s\n");
+}
+
+void printNetDevSentBytes(const char *cmd)
+{
+	int i;
+	char **retval;
+	
+	retval = parseCommand(cmd);
+	
+	if (retval[0] == NULL || retval[1] == NULL)
+		return;
+
+	for (i = 0; i < NetDevCnt; i++) {
+		if (!strcmp(NetDevs[i].name, retval[0])) {
+			if (!strncmp(retval[1], "data", 4))
+				fprintf(CurrentClient, "%lu", NetDevs[i].sentBytes);
+			if (!strncmp(retval[1], "packets", 7))
+				fprintf(CurrentClient, "%lu", NetDevs[i].sentPacks);
+			if (!strncmp(retval[1], "errors", 6))
+				fprintf(CurrentClient, "%lu", NetDevs[i].sentErrs);
+			if (!strncmp(retval[1], "multicast", 9))
+				fprintf(CurrentClient, "%lu", NetDevs[i].sentMulticast);
+			if (!strncmp(retval[1], "collisions", 10))
+				fprintf(CurrentClient, "%lu", NetDevs[i].sentColls);
+		}
+	}
+
+	fprintf(CurrentClient, "\n");
+}
+
+void printNetDevSentBytesInfo(const char *cmd)
+{
+	char **retval;
+	
+	retval = parseCommand(cmd);
+	
+	if (retval[1] == NULL)
+		return;
+
+	if (!strncmp(retval[1], "data", 4))
+		fprintf(CurrentClient, "Sent Data\t0\t0\tkBytes/s\n");
+	if (!strncmp(retval[1], "packets", 7))
+		fprintf(CurrentClient, "Sent Packets\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "errors", 6))
+		fprintf(CurrentClient, "Transmitter Errors\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "multicast", 9))
+		fprintf(CurrentClient, "Sent Multicast Packets\t0\t0\t1/s\n");
+	if (!strncmp(retval[1], "collisions", 10))
+		fprintf(CurrentClient, "Transmitter Collisions\t0\t0\t1/s\n");
+}
