Index: kstandarddirs.cpp
===================================================================
RCS file: /home/kde/kdelibs/kdecore/kstandarddirs.cpp,v
retrieving revision 1.168.2.3
retrieving revision 1.168.2.4
diff -u -p -r1.168.2.3 -r1.168.2.4
--- kdecore/kstandarddirs.cpp	8 Jun 2004 09:27:57 -0000	1.168.2.3
+++ kdecore/kstandarddirs.cpp	26 Jun 2004 14:42:16 -0000	1.168.2.4
@@ -651,7 +651,28 @@ void KStandardDirs::createSpecialResourc
    char link[1024];
    link[1023] = 0;
    int result = readlink(QFile::encodeName(dir).data(), link, 1023);
-   if ((result == -1) && (errno == ENOENT))
+   bool relink = (result == -1) && (errno == ENOENT);
+   if ((result > 0) && (link[0] == '/'))
+   {
+      link[result] = 0;
+      struct stat stat_buf;
+      int res = lstat(link, &stat_buf);
+      if ((res == -1) && (errno == ENOENT))
+      {
+         relink = true;
+      }
+      else if ((res == -1) || (!S_ISDIR(stat_buf.st_mode)))
+      {
+         fprintf(stderr, "Error: \"%s\" is not a directory.\n", link);
+         relink = true;
+      }
+      else if (stat_buf.st_uid != getuid())
+      {
+         fprintf(stderr, "Error: \"%s\" is owned by uid %d instead of uid %d.\n", link, stat_buf.st_uid, getuid());
+         relink = true;
+      }
+   }
+   if (relink)
    {
       QString srv = findExe(QString::fromLatin1("lnusertemp"), KDEDIR+QString::fromLatin1("/bin"));
       if (srv.isEmpty())
