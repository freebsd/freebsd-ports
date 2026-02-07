--- ./plugins/net/net.c.orig	2010-03-07 00:14:04.000000000 -0800
+++ ./plugins/net/net.c	2010-11-17 11:06:07.000000000 -0800
@@ -19,10 +19,23 @@
  * 
  */
 /*A little bug fixed by Mykola <mykola@2ka.mipt.ru>:) */
+/* FreeBSD code borrowed from patches to the lxpanel port */
 
 
 
 #include "../chart/chart.h"
+
+#ifdef __FreeBSD__
+#include <sys/types.h>
+#include <sys/param.h>
+#include <sys/socket.h>
+#include <sys/ioctl.h>
+#include <ifaddrs.h>
+#include <net/if.h>
+#include <net/if_media.h>
+#include <net/if_var.h>
+#endif
+
 #include <stdlib.h>
 #include <string.h>
 
@@ -102,6 +115,171 @@
     RET(TRUE);
 
 }
+#elif defined __FreeBSD__
+static inline	gboolean
+parse_stats(char *buf,
+	    int prx_idx,
+	    int ptx_idx,
+	    gulong * in_packets,
+	    gulong * out_packets,
+	    int brx_idx,
+	    int btx_idx,
+	    gulong * in_bytes,
+	    gulong * out_bytes)
+{
+	char           *p;
+	int		i;
+
+	p = strtok(buf, " \t\n");
+	for (i = 0; p; i++, p = strtok(NULL, " \t\n")) {
+		if (i == prx_idx)
+			*in_packets = g_ascii_strtoull(p, NULL, 10);
+		if (i == ptx_idx)
+			*out_packets = g_ascii_strtoull(p, NULL, 10);
+		if (i == brx_idx)
+			*in_bytes = g_ascii_strtoull(p, NULL, 10);
+		if (i == btx_idx)
+			*out_bytes = g_ascii_strtoull(p, NULL, 10);
+	}
+
+	if (i <= prx_idx || i <= ptx_idx || i <= brx_idx || i <= btx_idx)
+		return FALSE;
+
+	return TRUE;
+}
+
+static inline void
+parse_header(char *buf,
+	     int *prx_idx,
+	     int *ptx_idx,
+	     int *brx_idx,
+	     int *btx_idx)
+{
+	char           *p;
+	int		i;
+
+	*prx_idx = *ptx_idx = -1;
+	*brx_idx = *btx_idx = -1;
+
+	p = strtok(buf, " \n\t");
+	for (i = 0; p; i++, p = strtok(NULL, " \t\n")) {
+		if (!strcmp(p, "Ipkts")) {
+			*prx_idx = i;
+		} else if (!strcmp(p, "Ibytes")) {
+			*brx_idx = i;
+		} else if (!strcmp(p, "Opkts")) {
+			*ptx_idx = i;
+		} else if (!strcmp(p, "Obytes")) {
+			*btx_idx = i;
+		}
+	}
+}
+static int
+net_get_load(net_priv * c)
+{
+	struct net_stat	net, net_diff;
+	float		total[2];
+	GError         *error;
+	char           *command_line;
+	char          **argv;
+	char           *error_message = NULL;
+	int		pipe_out;
+	gulong		in_packets = -1;
+	gulong		out_packets = -1;
+	gulong		in_bytes = -1;
+	gulong		out_bytes = -1;
+	char		tooltip[256];
+
+	ENTER;
+	error = NULL;
+	command_line = g_strdup_printf("/usr/bin/netstat -n -I %s -b -f inet", c->iface);
+	DBG(command_line);
+	if (!g_shell_parse_argv(command_line, NULL, &argv, &error)) {
+		error_message = g_strdup_printf("Could not parse command line '%s': %s",
+						command_line,
+						error->message);
+		DBG(error_message);
+		g_error_free(error);
+		g_free(command_line);
+		RET(0);
+	}
+	g_free(command_line);
+
+	error = NULL;
+	if (g_spawn_async_with_pipes(NULL,
+				     argv,
+				     NULL,
+				     0,
+				     NULL,
+				     NULL,
+				     NULL,
+				     NULL,
+				     &pipe_out,
+				     NULL,
+				     &error)) {
+		GIOChannel     *channel;
+		char           *buf;
+		int		prx_idx   , ptx_idx;
+		int		brx_idx   , btx_idx;
+
+		channel = g_io_channel_unix_new(pipe_out);
+
+		g_io_channel_read_line(channel, &buf, NULL, NULL, NULL);
+		parse_header(buf, &prx_idx, &ptx_idx, &brx_idx, &btx_idx);
+		g_free(buf);
+
+		if (prx_idx == -1 || ptx_idx == -1 ||
+		    brx_idx == -1 || btx_idx == -1) {
+			error_message = g_strdup("Could not parse 'netstat' output. Unknown format");
+			DBG(error_message);
+			goto error_shutdown;
+		}
+		g_io_channel_read_line(channel, &buf, NULL, NULL, NULL);
+
+		if (!parse_stats(buf,
+				 prx_idx, ptx_idx, &in_packets, &out_packets,
+				 brx_idx, btx_idx, &in_bytes, &out_bytes)) {
+			error_message = g_strdup_printf("Could not parse interface statistics from '%s'. "
+							"prx_idx = %d; ptx_idx = %d; brx_idx = %d; btx_idx = %d;",
+				   buf, prx_idx, ptx_idx, brx_idx, btx_idx);
+			DBG(error_message);
+			goto error_shutdown;
+		} else if (in_packets == -1 || out_packets == -1 || in_bytes == -1 || out_bytes == -1) {
+			error_message = g_strdup_printf("Could not obtain information on interface '%s' from netstat",
+							c->iface);
+			DBG(error_message);
+			goto error_shutdown;
+		}
+		net.tx = out_bytes;
+		net.rx = in_bytes;
+
+		net_diff.tx = ((net.tx - c->net_prev.tx) >> 10) / CHECK_PERIOD;
+		net_diff.rx = ((net.rx - c->net_prev.rx) >> 10) / CHECK_PERIOD;
+
+		c->net_prev = net;
+		total[0] = (float)(net_diff.tx) / c->max;
+		total[1] = (float)(net_diff.rx) / c->max;
+		DBG("%f %ul %ul\n", total, net_diff.tx, net_diff.rx);
+		k->add_tick(&c->chart, total);
+		g_snprintf(tooltip, sizeof(tooltip), "<b>%s:</b>\nD %lu Kbs, U %lu Kbs",
+			   c->iface, net_diff.rx, net_diff.tx);
+		gtk_widget_set_tooltip_markup(((plugin_instance *) c)->pwid, tooltip);
+
+error_shutdown:
+		g_free(buf);
+		g_io_channel_unref(channel);
+		close(pipe_out);
+	} else {
+		error_message = g_strdup_printf("Error running /usr/bin/netstat for '%s': %s",
+						c->iface, error->message);
+		g_error_free(error);
+	}
+
+	g_strfreev(argv);
+
+	RET(TRUE);
+
+}
 #else
 
 static int
