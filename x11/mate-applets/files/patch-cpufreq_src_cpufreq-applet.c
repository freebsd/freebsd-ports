--- cpufreq/src/cpufreq-applet.c.orig	2021-08-07 11:25:17 UTC
+++ cpufreq/src/cpufreq-applet.c
@@ -17,6 +17,7 @@
  *  Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
  *
  * Authors : Carlos García Campos <carlosgc@gnome.org>
+ *           Joe Marcus Clarke <marcus@FreeBSD.org>
  */
 
 #ifdef HAVE_CONFIG_H
@@ -455,6 +456,7 @@ cpufreq_applet_about_cb (GtkAction     *action,
 {
     static const gchar *const authors[] = {
         "Carlos Garcia Campos <carlosgc@gnome.org>",
+        "Joe Marcus Clarke <marcus@FreeBSD.org> (FreeBSD support)",
         NULL
     };
     static const gchar* documenters[] = {
