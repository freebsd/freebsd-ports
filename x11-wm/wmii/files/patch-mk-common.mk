--- mk/common.mk.orig	2007-11-16 13:59:15 UTC
+++ mk/common.mk
@@ -4,9 +4,9 @@ install: all
 
 MANDIRS=${MAN}/man1
 mkdirs:
-	for i in ${BIN} ${ETC} ${LIBDIR} ${MANDIRS} ${INCLUDE} ${DIRS}; do \
-		test -d $$i || echo MKDIR $$i; \
-		mkdir -pm 0755 $$i; \
+	for i in ${BIN} ${ETC} ${LIBDIR} ${MANDIRS} ${INCLUDE}; do \
+		test -d ${DESTDIR}$$i || echo MKDIR ${DESTDIR}$$i; \
+		mkdir -pm 0755 ${DESTDIR}$$i; \
 	done
 
 cleandep:
