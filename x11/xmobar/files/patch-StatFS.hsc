--- ./StatFS.hsc.orig	2010-05-15 14:07:17.000000000 +0200
+++ ./StatFS.hsc	2010-05-16 16:27:52.000000000 +0200
@@ -23,7 +23,12 @@
 import Data.ByteString (useAsCString)
 import Data.ByteString.Char8 (pack)
 
+#if defined (__FreeBSD__)
+# include <sys/param.h>
+# include <sys/mount.h>
+#else
 #include <sys/vfs.h>
+#endif
 
 data FileSystemStats = FileSystemStats {
   fsStatBlockSize :: Integer
@@ -42,7 +47,11 @@
 
 data CStatfs
 
+#if defined(__FreeBSD__)
+foreign import ccall unsafe "sys/mount.h statfs"
+#else
 foreign import ccall unsafe "sys/vfs.h statfs64"
+#endif
   c_statfs :: CString -> Ptr CStatfs -> IO CInt
 
 toI :: CLong -> Integer
