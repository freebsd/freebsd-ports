# New ports collection makefile for:   qt22
# Date created:		17 Jul 1999
# Whom:			imura@kml.cs.titech.ac.jp
#
# $FreeBSD$
#

PORTNAME?=	qt
PORTVERSION?=	2.3.1
PORTREVISION=	1
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/ \
		ftp://ftp.chg.ru/pub/X11/qt/source/
DISTNAME=	qt-x11-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	objprelink:${PORTSDIR}/devel/objprelink

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_MESA=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
# YES, THIS PORT HAS ANTIALIASING SUPPORT IF YOUR XFREE86 SUPPORTS IT!
# JUST BECAUSE -xft IS NOT LISTED BELOW DOESN'T MEAN IT'S NOT THERE!
CONFIGURE_ARGS=	-system-zlib -system-libpng -system-jpeg -sm -gif \
		-system-libmng -thread -no-opengl -no-g++-exceptions \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib

.if defined(QT_DEBUG)
CONFIGURE_ARGS+= -debug
.endif

CONFIGURE_ENV=	${ECHO} yes | QTDIR=${WRKSRC}
.if defined(MAKE_JOBS)
MAKE_ARGS+=	MAKE="${GMAKE} -j${MAKE_JOBS}"
.endif
MAKE_ENV+=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib

CONFIG=		${WRKSRC}/configs/freebsd-g++-${STATIC}

.if !defined(NOPORTDOCS)
.if (${PORTNAME} == "qt")
.include "files/manpages"
.endif
.endif

.if defined(WANT_STATIC)
STATIC=static
CONFIGURE_ARGS+=-static
PLIST_SUB+=	SHARED="@comment " STATIC=""
.else
STATIC=shared
INSTALLS_SHLIB=yes
PLIST_SUB+=	SHARED="" STATIC="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

pre-fetch:
.if exists(${X11BASE}/lib/libqt2.so.3)
.if !defined(WANT_STATIC)
	@${ECHO} "An older version of QT2 is installed.  To avoid clobbering"
	@${ECHO} "that installation, deinstall it and then install this port."
	@${ECHO} "Note that this port contains beta-quality source code and"
	@${ECHO} "must be used only wherever absolutely needed, such as for"
	@${ECHO} "KDE 2.0 and later."
	@${FALSE}
.endif
.endif

qt-pre-configure:
	@true

pre-configure: qt-pre-configure
	${PERL} -pi -e "s,gcc,${CC},g; s,g\+\+,${CXX},g; \
			s,/usr/X11R6,${X11BASE},g; \
			s,-fno-exceptions,-fno-exceptions ${CXXFLAGS} -I/usr/include -D_PTH_H_ -D_PTH_PTHREAD_H_ -frerun-cse-after-loop,g" ${CONFIG}
	${PERL} -pi -e "s,VER_MAJ = 2,VER_MAJ = 4,g; \
			s,TARGET	= qt,TARGET = qt2,g" ${WRKSRC}/src/Makefile.in
	${PERL} -pi -e "s@TARGET\t= moc@TARGET = moc2@g" ${WRKSRC}/src/moc/Makefile.in
	${PERL} -pi -e "s,rm -f bin/moc,rm -f  bin/moc2,g; \
			s,cp src/moc/moc bin/moc,cp src/moc/moc2 bin/moc2,g; \
			s,symlinks  src-moc src-mt sub-src sub-tools sub-tutorial sub-examples,symlinks src-moc src-mt sub-src sub-tools,g" \
		${WRKSRC}/Makefile
.if (${PORTNAME} == "qt")
	${PERL} -pi -e "s@\$$(MAKE) designer@@g; s@uic \\\@uic@g; \
			s@\t\tdesigner@@g" ${WRKSRC}/tools/designer/Makefile.in
.endif

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} symlinks)

# Add hack to bring in support for GL.  The last line is necessary to ensure that
# one can rebuild with the same tree and get the same results.
do-build:
	(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})
.if !defined(WANT_STATIC)
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} opengl/qgl.o opengl/qgl_x11.o opengl/moc_qgl.o)
	${MV} ${WRKSRC}/lib/libqt2.so.4 ${WRKSRC}/lib/libqt2-real.so.4
	${PERL} -pi.orig -e "s@		xml/qdom.o@xml/qdom.o opengl/qgl.o opengl/qgl_x11.o opengl/moc_qgl.o@g; \
			     s@SYSCONF_LIBS_OPENGL =@SYSCONF_LIBS_OPENGL= ${PTHREAD_LIBS} -lGL -lGLU -lXmu@g" ${WRKSRC}/src/Makefile
	(cd ${WRKSRC}/src && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} all)
	${CP} ${WRKSRC}/lib/libqt2.so.4 ${WRKSRC}/lib/libqtgl.so.4
	${CP} ${WRKSRC}/lib/libqt2-real.so.4 ${WRKSRC}/lib/libqt2.so.4
	${CP} ${WRKSRC}/src/Makefile.orig ${WRKSRC}/src/Makefile
.endif

# XXX: This target looks like crap now.
do-install:
.if (${PORTNAME} == "qt")
	${MKDIR} ${PREFIX}/include/qt2
.for BIN in moc2 uic
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${BIN} ${PREFIX}/bin
.endfor
.for SCRIPT in findtr qt20fix qtrename140
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${SCRIPT} ${PREFIX}/bin
.endfor
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/qt2
.if !defined(WANT_STATIC)
.for LIB in qt2 qt2-mt qtgl
	${INSTALL_PROGRAM} ${WRKSRC}/lib/lib${LIB}.so.4 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/lib${LIB}.so.4 ${PREFIX}/lib/lib${LIB}.so
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/lib/libqutil.so.1 ${PREFIX}/lib
	${LN} -sf ${PREFIX}/lib/libqutil.so.1 ${PREFIX}/lib/libqutil.so
.else
.for LIB in qt2 qutil
	${INSTALL_DATA} ${WRKSRC}/lib/lib${LIB}.a ${PREFIX}/lib
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/qt2/html
.for FILE in ANNOUNCE FAQ PORTING README README.QT
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${PREFIX}/share/doc/qt2
.endfor
.for SUFFIX in g1n html png
	(for FILE in ${WRKSRC}/doc/html/*.${SUFFIX}; do \
		${INSTALL_DATA} $$FILE ${PREFIX}/share/doc/qt2/html; done)
.endfor
.for FILE in index titleindex propertyindex whatsthis
	${INSTALL_DATA} ${WRKSRC}/doc/html/${FILE} ${PREFIX}/share/doc/qt2/html
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/man3/q* ${PREFIX}/man/man3
.endif
.endif

.include <bsd.port.post.mk>
