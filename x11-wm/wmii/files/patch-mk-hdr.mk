--- mk/hdr.mk.orig	2007-11-16 21:59:15 +0800
+++ mk/hdr.mk
@@ -26,32 +26,32 @@ all:
 
 .O.install:
 	echo INSTALL ${BASE}$*
-	cp -f $< ${BIN}/$*
-	chmod 0755 ${BIN}/$* 
+	cp -f $< ${DESTDIR}${BIN}/$*
+	chmod 0755 ${DESTDIR}${BIN}/$* 
 .O.uninstall:
 	echo UNINSTALL ${BASE}$*
 	rm -f ${BIN}/$* 
 
 .a.install:
 	echo INSTALL ${BASE}$<
-	cp -f $< ${LIBDIR}/$<
-	chmod 0644 ${LIBDIR}/$<
+	cp -f $< ${DESTDIR}${LIBDIR}/$<
+	chmod 0644 ${DESTDIR}${LIBDIR}/$<
 .a.uninstall:
 	echo UNINSTALL ${BASE}$<
 	rm -f ${LIBDIR}/$<
 
 .h.install:
 	echo INSTALL ${BASE}$<
-	cp -f $< ${INCLUDE}/$<
-	chmod 0644 ${INCLUDE}/$<
+	cp -f $< ${DESTDIR}${INCLUDE}/$<
+	chmod 0644 ${DESTDIR}${INCLUDE}/$<
 .h.uninstall:
 	echo UNINSTALL ${BASE}$<
 	rm -f ${INCLUDE}/$<
 
 .1.install:
 	echo INSTALL man $*'(1)'
-	${FILTER} $< >${MAN}/man1/$<
-	chmod 0644 ${MAN}/man1/$<
+	${FILTER} $< >${DESTDIR}${MAN}/man1/$<
+	chmod 0644 ${DESTDIR}${MAN}/man1/$<
 .1.uninstall:
 	echo UNINSTALL man $*'(1)'
 	rm -f ${MAN}/man1/$<
@@ -69,8 +69,8 @@ install: printinstall mkdirs
 depend: cleandep
 
 FILTER = cat
-COMPILE= CC="${CC}" CFLAGS="${CFLAGS}" ${ROOT}/util/compile
-LINK= LD="${LD}" LDFLAGS="${LDFLAGS}" ${ROOT}/util/link
+COMPILE= noisycc=yes CC="${CC}" CFLAGS="${CFLAGS}" ${ROOT}/util/compile
+LINK= noisycc=yes LD="${LD}" LDFLAGS="${LDFLAGS}" ${ROOT}/util/link
 
 include ${ROOT}/config.mk
 CFLAGS += -I$$(echo ${INCPATH}|sed 's/:/ -I/g')
