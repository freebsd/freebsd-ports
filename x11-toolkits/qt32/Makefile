# -*-mode: makefile-*-
# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.1.1
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
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		cups.2:${PORTSDIR}/print/cups-base

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=yes
CONFIGURE_ARGS=	-system-libpng -system-libjpeg -system-libmng	\
		-qt-imgfmt-png -qt-imgfmt-jpeg -qt-imgfmt-mng	\
		-system-zlib -sm -qt-gif -thread -no-fast	\
		${XINERAMA} -no-g++-exceptions -no-stl ${CUPS}	\
		-shared -prefix ${PREFIX}

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

CUPS=	-cups -L/usr/local/lib -I/usr/local/include

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
