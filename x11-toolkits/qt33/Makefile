# -*-mode: makefile-*-
# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME=	qt
PORTVERSION=	3.1.2
PORTREVISION?=	1
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/	\
		ftp://ftp.silug.org/pub/qt/		\
		ftp://ftp.bero.org/pub/qt/		\
		ftp://ftp.planetmirror.com.au/pub/trolltech/qt/
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT=	A C++ X GUI toolkit

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
		-no-fast -xinerama -no-g++-exceptions -no-stl	\
		${CUPS} -shared -prefix ${PREFIX} -datadir ${DATADIR} \
		-docdir ${DOCSDIR} -plugindir ${PREFIX}/lib/plugins

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/Xft
.else
CONFIGURE_ARGS+=-no-xft
.endif

.if defined(DEBUG)
CONFIGURE_ARGS+= -debug
.endif

.if !defined(BUILD_PLUGIN_ONLY)
.if !defined(WITHOUT_OPENGL)
USE_MESA=	yes
.else
CONFIGURE_ARGS+=-disable-opengl
.endif # WITHOUT_OPENGL

.if !defined(WITHOUT_CUPS)
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
CUPS=	-cups -L${LOCALBASE}/lib -I${LOCALBASE}/include
.else
CUPS=
.endif
.endif

.if !defined(BUILD_PLUGIN_ONLY)
CONFIGURE_ENV=	${ECHO} yes | QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} \
		LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
ALL_TARGET=	sub-tools
.endif

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

.if !defined(BUILD_PLUGIN_ONLY)
.if !defined(WITHOUT_OPENGL)
# Display WITH_OPENGL advisory.
pre-everything::
	@${ECHO_MSG} '===> **************************************************'
	@${ECHO_MSG} '===> NOTE: Use of WITH_OPENGL is not recommended with'
	@${ECHO_MSG} '===> the NVidia drivers provided by the x11/nvidia port'
	@${ECHO_MSG} '===> If you use these drivers, we recommend you press'
	@${ECHO_MSG} '===> Ctrl-C now and set WITHOUT_OPENGL'
	@${ECHO_MSG} '===> **************************************************'
.endif
.if !defined(WITHOUT_XFT)
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} '===> **************************************************'
	@${ECHO_MSG} '===> If you do not want to build QT with XFT support '
	@${ECHO_MSG} '===> press Ctrl-C and set WITHOUT_XFT'
	@${ECHO_MSG} '===> **************************************************'
.endif

.if ${XFREE86_VERSION} < 4
BROKEN=	"The QT ${PORTVERSION} port does not support any XFree86 < 4.x"
.endif # ${XFREE86_VERSION} < 4

.if exists(${X11BASE}/include/qt2/qapp.h)
BROKEN=	"You have QT2 headers installed!  Installing this port"
BROKEN+="will result in conflicts between QT3 and QT2!"
.endif
.endif

post-patch:
.if !defined(BUILD_PLUGIN_ONLY)
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -fr
	@${RM} -fr ${WRKSRC}/examples ${WRKSRC}/tutorial
	@cd ${WRKSRC}/include; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h
	@cd ${WRKSRC}/extensions/nsplugin/src; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h \
		npunix.c npwin.cpp
.endif
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
	@${REINPLACE_CMD} -e 's,release,release thread,' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${RM} ${WRKSRC}/mkspecs/freebsd-g++/qmake.conf.bak

.if !defined(BUILD_PLUGIN_ONLY)
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
.endif

.include <bsd.port.post.mk>
