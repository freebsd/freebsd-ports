# -*-mode: makefile-*-
# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.1.1
PORTREVISION=	2
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/	\
		ftp://ftp.silug.org/pub/qt/		\
		ftp://ftp.bero.org/pub/qt/		\
		ftp://ftp.planetmirror.com.au/pub/trolltech/qt/

DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS+=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes
CONFIGURE_ARGS=	-system-libpng -system-libjpeg -system-libmng	\
		-qt-imgfmt-png -qt-imgfmt-jpeg -qt-imgfmt-mng	\
		-system-zlib -no-nas-sound -sm -qt-gif -thread	\
		-no-fast ${XINERAMA} -no-g++-exceptions -no-stl	\
		${CUPS} -shared -prefix ${PREFIX}

.if defined(DEBUG)
CONFIGURE_ARGS+= -debug
.endif

.if !defined(WITHOUT_OPENGL)
USE_MESA=	yes
.else
CONFIGURE_ARGS+=-disable-opengl
.endif # WITHOUT_OPENGL

.if defined(WITH_XINERAMA)
XINERAMA=	-xinerama
PKGNAMESUFFIX=	-xinerama
.else
XINERAMA=	-no-xinerama
.endif # defined(WITH_XINERAMA)

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CUPS=	-cups -L${LOCALBASE}/lib -I${LOCALBASE}/include
.else
CUPS=
.endif

CONFIGURE_ENV=	${ECHO} yes | QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} \
		LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
ALL_TARGET=	sub-tools

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

.if ${XFREE86_VERSION} < 4
BROKEN=	"The QT ${PORTVERSION} port does not support any XFree86 < 4.x"
.endif # ${XFREE86_VERSION} < 4

.if exists(${X11BASE}/include/qt2/qapp.h)
BROKEN=	"You have QT2 headers installed!  Installing this port"
BROKEN+="will result in conflicts between QT3 and QT2!"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,-O2,${CXXFLAGS},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's,gcc,${CC},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's,g++,${CXX},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e  's,/usr/local,${LOCALBASE},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e  's,/usr/X11R6,${X11BASE},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

post-build:
.for tool in makeqpf mergetr msg2qm qembed qvfb
	cd ${WRKSRC}/tools/${tool}; ${SETENV} ${MAKE_ENV} ${MAKE}
.endfor

# Work around qmake generated dependencies
pre-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib
	${INSTALL_SCRIPT} ${WRKSRC}/bin/findtr ${PREFIX}/bin
.for tool in makeqpf mergetr msg2qm qembed qvfb
	${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool}/${tool} ${PREFIX}/bin
.endfor

.include <bsd.port.post.mk>
