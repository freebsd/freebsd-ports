# New ports collection makefile for:	qt-copy
# Date created:				2 November 2001
# Whom:					will@cvs.kde.org
#
# $FreeBSD$
#

PORTNAME?=	qt
PORTVERSION?=	3.0.3
PORTREVISION=	5
CATEGORIES?=	x11-toolkits
MASTER_SITES=   ftp://ftp.trolltech.com/qt/source/ \
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
.else
IMAGELIB_TYPE=	qt
PLIST_SUB+=	IMAGE_PLUGINS="@comment "
.endif

QT_PREFIX?=	${PREFIX}
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_NEWGCC=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${QT_PREFIX} \
		-shared -qt-gif -system-zlib \
		-no-g++-exceptions -thread -no-stl \
		-${IMAGELIB_TYPE}-imgfmt-png \
		-${IMAGELIB_TYPE}-imgfmt-jpeg \
		-${IMAGELIB_TYPE}-imgfmt-mng \
		-system-libpng -system-libjpeg 	-system-libmng \
		-no-nas-sound -sm -remote \
		-docdir ${QT_PREFIX}/share/doc/qt \
		-I${LOCALBASE}/include -L${LOCALBASE}/lib
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+= -debug
.endif
.if defined(WITH_OPENGL)
USE_MESA=	yes
PLIST_SUB+=	OPENGL=""
PKGNAMESUFFIX=	-opengl
BROKEN=	"Using WITH_OPENGL causes DRI to fail in mysterious ways"
.else
PKGMESSAGE=${NONEXISTENT}
PLIST_SUB+=	OPENGL="@comment "
CONFIGURE_ARGS+=-disable-opengl
.endif
CONFIGURE_ENV=	${ECHO} yes | QTDIR=${WRKSRC}
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib
ALL_TARGET=	symlinks sub-src sub-tools

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

.if defined(WITH_OPENGL)
# Display WITH_OPENGL advisory.
pre-everything:
	@${ECHO_MSG} '===> **************************************************'
	@${ECHO_MSG} '===> NOTE: Use of WITH_OPENGL is not recommended with'
	@${ECHO_MSG} '===> versions of XFree86 < 4.2.0.' 
	@${ECHO_MSG} '===> **************************************************'
.endif

# Remove unneeded dirs (speedup) and fake netscape files.
post-patch:
	@${FIND} ${WRKSRC} -name CVS | ${XARGS} ${RM} -fr
	@${RM} -fr ${WRKSRC}/examples ${WRKSRC}/tutorial
	@cd ${WRKSRC}/include; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h
	@cd ${WRKSRC}/extensions/nsplugin/src; \
		${RM} -f jri.h jri_md.h jritypes.h npapi.h npupp.h \
			npunix.c npwin.cpp

# Work around qmake generated dependencies
pre-install:
	@${INSTALL_DATA} ${WRKSRC}/lib/*.prl ${PREFIX}/lib

.if exists(${PKGMESSAGE})
# Display another GL advisory. This one goes in the package, too.
post-install:
	@cat ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
