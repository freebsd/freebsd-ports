--- ../kinit/klauncher.h	(revision 918653)
+++ ../kinit/klauncher.h	(revision 918654)
@@ -87,6 +87,7 @@
    QString name;
    QStringList arg_list;
    QString dbus_name;
+   QString tolerant_dbus_name;
    enum status_t { Init = 0, Launching, Running, Error, Done };
    pid_t pid;
    status_t status;
