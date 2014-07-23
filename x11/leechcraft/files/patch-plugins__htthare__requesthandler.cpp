--- ./plugins/htthare/requesthandler.cpp.orig	2014-07-03 17:34:52.000000000 +0400
+++ ./plugins/htthare/requesthandler.cpp	2014-07-16 15:51:51.242851048 +0400
@@ -309,14 +309,12 @@
 					const auto transferred = rc > 0 ? rc : 0;
 					const auto errCode = rc > 0 ? 0 : errno;
 #elif defined (Q_OS_FREEBSD)
-					auto transferred = toTransfer;
+					off_t transferred = toTransfer;
 					const auto rc = sendfile (File_->handle (), Sock_.native_handle (),
 							offset, toTransfer, nullptr, &transferred, 0);
 					if (rc == -1)
-					{
 						transferred = 0;
-						errCode = errno;
-					}
+					const auto errCode = rc == -1 ? errno : 0;
 #elif defined (Q_OS_MAC)
 					auto transferred = toTransfer;
 					auto errCode = sendfile (File_->handle (),
