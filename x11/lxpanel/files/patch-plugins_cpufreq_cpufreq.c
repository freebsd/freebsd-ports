--- plugins/cpufreq/cpufreq.c.orig	2015-05-06 19:44:51 UTC
+++ plugins/cpufreq/cpufreq.c
@@ -22,6 +22,9 @@
 #include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
+#if defined(__DragonFly__) || defined(__FreeBSD__)
+#include <sys/sysctl.h>
+#endif
 #include <glib.h>
 #include <glib/gi18n.h>
 
@@ -33,6 +36,7 @@
 #include "dbg.h"
 
 #define PROC_ICON           "cpufreq-icon"
+#if defined(__linux__)
 #define SYSFS_CPU_DIRECTORY "/sys/devices/system/cpu"
 #define SCALING_GOV         "scaling_governor"
 #define SCALING_AGOV        "scaling_available_governors"
@@ -41,15 +45,19 @@
 #define SCALING_SETFREQ     "scaling_setspeed"
 #define SCALING_MAX         "scaling_max_freq"
 #define SCALING_MIN         "scaling_min_freq"
-
+#endif
 
 typedef struct {
     GtkWidget *main;
     config_setting_t *settings;
+#if defined(__linux__)
     GList *governors;
     GList *cpus;
-    int has_cpufreq;
     char* cur_governor;
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    int cpus;
+#endif
+    int has_cpufreq;
     int   cur_freq;
     unsigned int timer;
     //gboolean remember;
@@ -62,6 +70,7 @@ typedef struct {
 
 static void cpufreq_destructor(gpointer user_data);
 
+#if defined(__linux__)
 static void
 get_cur_governor(cpufreq *cf){
     FILE *fp;
@@ -99,98 +108,6 @@ get_cur_freq(cpufreq *cf){
     }
 }
 
-/*static void
-get_governors(cpufreq *cf){
-    FILE *fp;
-    GList *l;
-    char buf[ 100 ], sstmp [ 256 ], c, bufl = 0;
-
-    g_list_free(cf->governors);
-    cf->governors = NULL;
-
-    get_cur_governor(cf);
-
-    if(cf->cpus == NULL){
-        cf->governors = NULL;
-        return;
-    }
-    sprintf(sstmp,"%s/%s",cf->cpus->data, SCALING_AGOV);
-
-    if (!(fp = fopen( sstmp, "r"))) {
-        printf("cpufreq: cannot open %s\n",sstmp);
-        return;
-    }
-
-    while((c = fgetc(fp)) != EOF){
-        if(c == ' '){
-            if(bufl > 1){
-                buf[bufl] = '\0';
-                cf->governors = g_list_append(cf->governors, strdup(buf));
-            }
-            bufl = 0;
-            buf[0] = '\0';
-        }else{
-            buf[bufl++] = c;
-        }
-    }
-
-    fclose(fp);
-}
-
-static void
-cpufreq_set_freq(GtkWidget *widget, Param* p){
-    FILE *fp;
-    char buf[ 100 ], sstmp [ 256 ];
-
-    if(strcmp(p->cf->cur_governor, "userspace")) return;
-
-    sprintf(sstmp,"%s/%s",p->cf->cpus->data, SCALING_SETFREQ);
-    if ((fp = fopen( sstmp, "w")) != NULL) {
-        fprintf(fp,"%s",p->data);
-        fclose(fp);
-    }
-}
-
-static GtkWidget *
-frequency_menu(cpufreq *cf){
-    FILE *fp;
-    Param* param;
-    char buf[ 100 ], sstmp [ 256 ], c, bufl = 0;
-
-    sprintf(sstmp,"%s/%s",cf->cpus->data, SCALING_AFREQ);
-
-    if (!(fp = fopen( sstmp, "r"))) {
-        printf("cpufreq: cannot open %s\n",sstmp);
-        return 0;
-    }
-
-    GtkMenu* menu = GTK_MENU(gtk_menu_new());
-    GtkWidget* menuitem;
-
-    while((c = fgetc(fp)) != EOF){
-        if(c == ' '){
-            if(bufl > 1){
-                buf[bufl] = '\0';
-                menuitem = gtk_menu_item_new_with_label(strdup(buf));
-                gtk_menu_append (GTK_MENU_SHELL (menu), menuitem);
-                gtk_widget_show (menuitem);
-                param = g_new0(Param, 1);
-                param->data = strdup(buf);
-                param->cf = cf;
-                g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(cpufreq_set_freq), param);
-                g_object_weak_ref(G_OBJECT(menuitem), (GWeakNotify)g_free, param);
-            }
-            bufl = 0;
-            buf[0] = '\0';
-        }else{
-            buf[bufl++] = c;
-        }
-    }
-
-    fclose(fp);
-    return GTK_WIDGET(menu);
-}*/
-
 static void
 get_cpus(cpufreq *cf)
 {
@@ -227,72 +144,49 @@ get_cpus(cpufreq *cf)
     }
     g_dir_close(cpuDirectory);
 }
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+static void
+get_cur_freq(cpufreq *cf)
+{
+    int buf;
+    size_t length_buf = sizeof(int);
 
-/*static void
-cpufreq_set_governor(GtkWidget *widget, Param* p){
-    FILE *fp;
-    char buf[ 100 ], sstmp [ 256 ];
-
-    sprintf(sstmp, "%s/%s", p->cf->cpus->data, SCALING_GOV);
-    if ((fp = fopen( sstmp, "w")) != NULL) {
-        fprintf(fp,"%s",p->data);
-        fclose(fp);
-    }
+    if (sysctlbyname("dev.cpu.0.freq", &buf, &length_buf, NULL, 0) < 0)
+        cf->cur_freq = 0;
+    else
+        cf->cur_freq = buf;
 }
 
-static GtkWidget *
-cpufreq_menu(cpufreq *cf){
-    GList *l;
-    GSList *group;
-    char buff[100];
-    GtkMenuItem* menuitem;
-    Param* param;
-
-    GtkMenu* menu = GTK_MENU(gtk_menu_new());
-    g_signal_connect(menu, "selection-done", G_CALLBACK(gtk_widget_destroy), NULL);
-
-    get_governors(cf);
-    group = NULL;
+int
+detect_cpus_number(void)
+{
+    static int mib[] = {CTL_HW, HW_NCPU};
+    int buf;
+    size_t length_buf = sizeof(int);
 
-    if((cf->governors == NULL) || (!cf->has_cpufreq) || (cf->cur_governor == NULL)){
-        menuitem = GTK_MENU_ITEM(gtk_menu_item_new_with_label("CPUFreq not supported"));
-        gtk_menu_append (GTK_MENU_SHELL (menu), GTK_WIDGET (menuitem));
-        gtk_widget_show (GTK_WIDGET (menuitem));
-        return GTK_WIDGET(menu);
-    }
+    if (sysctl(mib, 2, &buf, &length_buf, NULL, 0) < 0)
+        return 0;
+    else
+        return buf;
+}
 
-    if(strcmp(cf->cur_governor, "userspace") == 0){
-        menuitem = GTK_MENU_ITEM(gtk_menu_item_new_with_label("  Frequency"));
-        gtk_menu_append (GTK_MENU_SHELL (menu), GTK_WIDGET (menuitem));
-        gtk_widget_show (GTK_WIDGET (menuitem));
-        gtk_menu_item_set_submenu(menuitem, frequency_menu(cf));
-        menuitem = GTK_MENU_ITEM(gtk_separator_menu_item_new());
-        gtk_menu_append (GTK_MENU_SHELL (menu), GTK_WIDGET (menuitem));
-        gtk_widget_show (GTK_WIDGET(menuitem));
-    }
+static void
+get_cpus(cpufreq *cf)
+{
+    int ncpus, buf;
+    size_t lenght_buf = sizeof(int);
 
-    for( l = cf->governors; l; l = l->next )
+    ncpus = detect_cpus_number();
+    cf->cpus = ncpus;
+    if (cf->cpus > 0)
+        cf->has_cpufreq = 1;
+    else
     {
-      if(strcmp((char*)l->data, cf->cur_governor) == 0){
-        sprintf(buff,"> %s", l->data);
-        menuitem = GTK_MENU_ITEM(gtk_menu_item_new_with_label(strdup(buff)));
-      }else{
-        sprintf(buff,"   %s", l->data);
-        menuitem = GTK_MENU_ITEM(gtk_menu_item_new_with_label(strdup(buff)));
-      }
-
-      gtk_menu_shell_append (GTK_MENU_SHELL (menu), GTK_WIDGET (menuitem));
-      gtk_widget_show (GTK_WIDGET (menuitem));
-      param = g_new0(Param, 1);
-      param->data = l->data;
-      param->cf = cf;
-      g_signal_connect(G_OBJECT(menuitem), "activate", G_CALLBACK(cpufreq_set_governor), param);
-      g_object_weak_ref(G_OBJECT(menuitem), (GWeakNotify) g_free, param);
+        cf->has_cpufreq = 0;
+        printf("cpufreq: no cpu found\n");
     }
-
-    return GTK_WIDGET (menu);
-}*/
-
+}
+#endif
 
 
 static  gboolean
@@ -318,12 +212,18 @@ _update_tooltip(cpufreq *cf)
     char *tooltip;
 
     get_cur_freq(cf);
+#if defined(__linux__)
     get_cur_governor(cf);
+#endif
 
     ENTER;
 
+#if defined(__linux__)
     tooltip = g_strdup_printf(_("Frequency: %d MHz\nGovernor: %s"),
                               cf->cur_freq / 1000, cf->cur_governor);
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    tooltip = g_strdup_printf("Frequency: %d MHz", cf->cur_freq);
+#endif
     gtk_widget_set_tooltip_text(cf->main, tooltip);
     g_free(tooltip);
     RET(TRUE);
@@ -344,8 +244,12 @@ static GtkWidget *cpufreq_constructor(LX
     ENTER;
     cf = g_new0(cpufreq, 1);
     g_return_val_if_fail(cf != NULL, NULL);
+#if defined(__linux__)
     cf->governors = NULL;
     cf->cpus = NULL;
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    cf->cpus = 0;
+#endif
     cf->settings = settings;
 
     cf->main = lxpanel_button_new_for_icon(panel, PROC_ICON, NULL, NULL);
@@ -365,30 +269,14 @@ static GtkWidget *cpufreq_constructor(LX
     RET(cf->main);
 }
 
-/*
-static gboolean applyConfig(gpointer user_data)
-{
-    cpufreq *cf = lxpanel_plugin_get_data(user_data);
-
-    config_group_set_int(cf->settings, "Remember", cf->remember);
-    return FALSE;
-}
-
-static GtkWidget *config(LXPanel *panel, GtkWidget *p, GtkWindow *parent)
-{
-    cpufreq *cf = lxpanel_plugin_get_data(p);
-    return lxpanel_generic_config_dlg(_("CPUFreq frontend"), panel, applyConfig, p,
-            _("Remember governor and frequency"), &cf->remember, CONF_TYPE_BOOL,
-            NULL);
-}
-*/
-
 static void
 cpufreq_destructor(gpointer user_data)
 {
     cpufreq *cf = (cpufreq *)user_data;
+#if defined(__linux__)
     g_list_free ( cf->cpus );
     g_list_free ( cf->governors );
+#endif
     g_source_remove(cf->timer);
     g_free(cf);
 }
@@ -399,7 +287,11 @@ FM_DEFINE_MODULE(lxpanel_gtk, cpufreq)
 /* Plugin descriptor. */
 LXPanelPluginInit fm_module_init_lxpanel_gtk = {
     .name = N_("CPUFreq frontend"),
+#if defined(__linux__)
     .description = N_("Display CPU frequency and allow to change governors and frequency"),
+#elif defined(__DragonFly__) || defined(__FreeBSD__)
+    .description = "Display CPU frequency",
+#endif
 
     .new_instance = cpufreq_constructor,
     //.config      = config,
