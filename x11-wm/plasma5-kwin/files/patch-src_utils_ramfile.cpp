FreeBSD < 13 lacks https://cgit.freebsd.org/src/commit/?id=af755d3e4859

src/utils/ramfile.cpp:57:117: error: use of undeclared identifier 'errno'
        qCWarning(KWIN_CORE).nospace() << name << ": Failed to remove temporary file from filesystem: " << strerror(errno);
                                                                                                                    ^
src/utils/ramfile.cpp:80:17: error: use of undeclared identifier 'F_SEAL_SHRINK'
    int seals = F_SEAL_SHRINK | F_SEAL_GROW | F_SEAL_SEAL;
                ^
src/utils/ramfile.cpp:80:33: error: use of undeclared identifier 'F_SEAL_GROW'
    int seals = F_SEAL_SHRINK | F_SEAL_GROW | F_SEAL_SEAL;
                                ^
src/utils/ramfile.cpp:80:47: error: use of undeclared identifier 'F_SEAL_SEAL'
    int seals = F_SEAL_SHRINK | F_SEAL_GROW | F_SEAL_SEAL;
                                              ^
src/utils/ramfile.cpp:82:18: error: use of undeclared identifier 'F_SEAL_WRITE'
        seals |= F_SEAL_WRITE;
                 ^
src/utils/ramfile.cpp:85:21: error: use of undeclared identifier 'F_ADD_SEALS'
    if (fcntl(fd(), F_ADD_SEALS, seals) != 0) {
                    ^
src/utils/ramfile.cpp:139:35: error: use of undeclared identifier 'F_GET_SEALS'
    const int seals = fcntl(fd(), F_GET_SEALS);
                                  ^
src/utils/ramfile.cpp:141:21: error: use of undeclared identifier 'F_SEAL_WRITE'
        if (seals & F_SEAL_WRITE) {
                    ^

--- src/utils/ramfile.cpp.orig	2023-01-03 18:08:37 UTC
+++ src/utils/ramfile.cpp
@@ -16,6 +16,7 @@
 #include <fcntl.h>
 #include <sys/mman.h>
 #include <unistd.h>
+#include <cerrno>
 #include <utility>
 
 namespace KWin
@@ -77,6 +78,7 @@ RamFile::RamFile(const char *name, const void *inData,
     m_tmp->unmap(data);
 #endif
 
+#ifdef F_SEAL_SEAL
     int seals = F_SEAL_SHRINK | F_SEAL_GROW | F_SEAL_SEAL;
     if (flags.testFlag(RamFile::Flag::SealWrite)) {
         seals |= F_SEAL_WRITE;
@@ -85,6 +87,7 @@ RamFile::RamFile(const char *name, const void *inData,
     if (fcntl(fd(), F_ADD_SEALS, seals) != 0) {
         qCDebug(KWIN_CORE).nospace() << name << ": Failed to seal RamFile: " << strerror(errno);
     }
+#endif
 
     guard.dismiss();
 }
@@ -136,12 +139,14 @@ RamFile::Flags RamFile::effectiveFlags() const
 {
     Flags flags = {};
 
+#ifdef F_SEAL_SEAL
     const int seals = fcntl(fd(), F_GET_SEALS);
     if (seals > 0) {
         if (seals & F_SEAL_WRITE) {
             flags.setFlag(Flag::SealWrite);
         }
     }
+#endif
 
     return flags;
 }
