# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME?=	qt
PORTVERSION?=	3.0.5
PORTREVISION?=  4
CATEGORIES?=	x11-toolkits
MASTER_SITES=	ftp://ftp.trolltech.com/qt/source/ \
		ftp://ftp.chg.ru/pub/X11/qt/source/
DISTNAME=	qt-x11-free-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org

LIB_DEPENDS=	mng.1:${PORTSDIR}/graphics/libmng \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

.if defined(WITH_IMAGE_PLUGINS)
IMAGELIB_TYPE=	plugin
PLIST_SUB+=	IMAGE_PLUGINS=""
.else # WITHOUT_IMAGE_PLUGINS [default]
IMAGELIB_TYPE=	qt
PLIST_SUB+=	IMAGE_PLUGINS="@comment "
.endif # WITHOUT_IMAGE_PLUGINS [default]

QT_PREFIX?=		${PREFIX}
USE_BZIP2=		yes
USE_GMAKE=		yes
USE_REINPLACE=		yes
REINPLACE_ARGS=		-i ""
USE_X_PREFIX=		yes
NO_FILTER_SHLIBS=	yes
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=	-prefix ${QT_PREFIX} \
		-shared -qt-gif -system-zlib \
		-no-g++-exceptions -thread -no-stl \
		-${IMAGELIB_TYPE}-imgfmt-png \
		-${IMAGELIB_TYPE}-imgfmt-jpeg \
		-${IMAGELIB_TYPE}-imgfmt-mng \
		-system-libpng -system-libjpeg 	-system-libmng \
		-no-nas-sound -sm \
		-docdir ${QT_PREFIX}/share/doc/qt \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=-debug
.endif # defined(WITH_DEBUG)

# backward compatibility
.if defined(WITH_OPENGL)
.undef WITHOUT_OPENFL
.endif # defined(WITH_OPENGL)

.if !defined(WITHOUT_OPENGL)
USE_MESA=	yes
PLIST_SUB+=	OPENGL=""
.else # WITHOUT_OPENGL
PLIST_SUB+=	OPENGL="@comment "
CONFIGURE_ARGS+=-disable-opengl
.endif # WITHOUT_OPENGL

CONFIGURE_ENV=	${ECHO} yes | QTDIR="${WRKSRC}" \
		CFLAGS="${CXXFLAGS}"
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib
ALL_TARGET=	symlinks sub-src sub-tools

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif # ${MACHINE_ARCH} == "alpha"

.if ${XFREE86_VERSION} < 4
BROKEN=		"The QT 3.x port does not support any XFree86 < 4.x"
.endif # ${XFREE86_VERSION} < 4

pre-fetch:
.if exists(${X11BASE}/include/qt2/qapp.h)
	@${ECHO}
	@${ECHO} "			NOTICE"
	@${ECHO}
	@${ECHO} "You have QT2 headers installed!  Installing this port"
	@${ECHO} "will result in conflicts between QT3 and QT2!"
	@${FALSE}
.endif

# Remove unneeded dirs (speedup) and netscape files (build barfs).
post-patch:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -fr
	@${RM} -fr ${WRKSRC}/examples ${WRKSRC}/tutorial
	@cd ${WRKSRC}/include; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h
	@cd ${WRKSRC}/extensions/nsplugin/src; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h \
			npunix.c npwin.cpp
	${REINPLACE_CMD} -e 's,-O2,${CXXFLAGS},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's,gcc,${CC},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e 's,g++,${CXX},' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf
	@${REINPLACE_CMD} -e  's,release,release thread,' \
		${WRKSRC}/mkspecs/freebsd-g++/qmake.conf

post-build:
	cd ${WRKSRC}/tools/makeqpf/; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/tools/mergetr/; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/tools/msg2qm/; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/tools/qembed/; ${SETENV} ${MAKE_ENV} ${MAKE}
	cd ${WRKSRC}/tools/qvfb/; ${SETENV} ${MAKE_ENV} ${MAKE}

# Work around qmake generated dependencies
pre-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib
	${INSTALL_PROGRAM} ${WRKSRC}/tools/makeqpf/makeqpf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mergetr/mergetr ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/msg2qm/msg2qm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qembed/qembed ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/qvfb/qvfb ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/findtr ${PREFIX}/bin

.include <bsd.port.post.mk>
