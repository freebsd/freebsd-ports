--- kdesu/process.cpp.orig	Sat Feb 17 21:03:18 2001
+++ kdesu/process.cpp	Fri Jan 11 21:23:41 2002
@@ -120,13 +120,16 @@
 	kdError(900) << k_lineinfo << "fcntl(F_GETFL): " << perror << "\n";
 	return ret;
     }
+    int oflags = flags;
     if (block)
 	flags &= ~O_NONBLOCK;
     else
 	flags |= O_NONBLOCK;
-    if (fcntl(m_Fd, F_SETFL, flags) < 0) 
+
+    if ((flags != oflags) && (fcntl(m_Fd, F_SETFL, flags) < 0))
     {
-	kdError(900) << k_lineinfo << "fcntl(F_SETFL): " << perror << "\n";
+        // We get an error here when the child process has closed
+        // the file descriptor already.
 	return ret;
     }
 
@@ -231,12 +234,12 @@
 	path = QFile::encodeName(file);
     }
 
-    int i;
-    const char * argp[32];
-    argp[0] = path;
-    QCStringList::Iterator it;
-    for (i=1, it=args.begin(); it!=args.end() && i<31; it++)
+    const char **argp = (const char **)malloc((args.count()+2)*sizeof(char *));
+    int i = 0;
+    argp[i++] = path;
+    for (QCStringList::ConstIterator it=args.begin(); it!=args.end(); it++)
 	argp[i++] = *it;
+
     argp[i] = 0L;
 	
     execv(path, (char * const *)argp);
