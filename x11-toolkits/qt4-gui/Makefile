# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gui
PORTVERSION=	4.2.2
CATEGORIES?=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER?=	kde@FreeBSD.org
COMMENT?=	Qt graphical user interface library

BUILD_DEPENDS=	moc4:${PORTSDIR}/devel/qt4-moc \
		qmake-qt4:${PORTSDIR}/devel/qmake4 \
		rcc:${PORTSDIR}/devel/qt4-rcc \
		uic4:${PORTSDIR}/devel/qt4-uic
LIB_DEPENDS?=	QtCore:${PORTSDIR}/devel/qt4-corelib \
		png:${PORTSDIR}/graphics/png

CONFLICTS=	linguist-0.* qt-2.* qt-3.0.* \
		qt-3.1.* qt-3.2.* qt-designer-2.* xfmail-1.5.[0-5] \
		xfmail-1.5.5_[1-2]

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
NO_FILTER_SHLIBS=yes
USE_XLIB=	yes

CONFIGURE_ARGS=	-fast -no-exceptions ${CUPS} \
		-platform ${LOCALBASE}/share/qt4/mkspecs/freebsd-g++ \
		-qt-gif -release -system-libjpeg -system-libpng \
		-system-zlib -prefix ${PREFIX} -no-sm \
		-plugindir ${PREFIX}/lib/plugins -bindir ${PREFIX}/bin \
		-confirm-license

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH
EXTRACT_AFTER_ARGS=| ${TAR} -xf - \
	--exclude '${DISTNAME}/mkspecs' --exclude '${DISTNAME}/qmake' \
	--exclude '${DISTNAME}/demos' --exclude '${DISTNAME}/examples' \
	--exclude '${DISTNAME}/src/network' --exclude '${DISTNAME}/src/xml' \
	--exclude '${DISTNAME}/src/opengl' --exclude '${DISTNAME}/src/qt3support' \
	--exclude '${DISTNAME}/src/sql' \
	--exclude '${DISTNAME}/src/tools/moc' --exclude '${DISTNAME}/src/tools/uic' \
	--exclude '${DISTNAME}/src/tools/rcc' --exclude '${DISTNAME}/src/tools/uic3' \
	--exclude '${DISTNAME}/tools/assistant' \
	--exclude '${DISTNAME}/tools/linguist' --exclude '${DISTNAME}/tools/porting' \
	--exclude '${DISTNAME}/tools/qtconfig' --exclude '${DISTNAME}/tools/qvfb'
WRKSRC=		${WRKDIR}/${DISTNAME}/src/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../

OPTIONS=	CUPS "Enable printing support (requires CUPS)" off \
		NAS "Enable sound support (requires NAS)" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CUPS) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	cupsd:${PORTSDIR}/print/cups-base
CUPS=		-cups -L${LOCALBASE}/lib -I${LOCALBASE}/include
.elif defined(WITHOUT_CUPS)
CUPS=
.endif

.if !defined(WITHOUT_NAS)
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=-system-nas-sound
.elif defined(WITHOUT_NAS)
CONFIGURE_ARGS+=-no-nas-sound
.endif

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib|g' \
		-e 's|flat_headers.path.*|flat_headers.path=${PREFIX}/include/Qt|g' \
		-e 's|targ_headers.path.*|targ_headers.path=${PREFIX}/include/$$$$TARGET|g' \
		${WRKSRC}/${PORTNAME}.pro ${WRKSRC}/../qt_install.pri
	${REINPLACE_CMD} -e 's|target.path.*|target.path=${PREFIX}/lib/plugins/imageformats|g' \
		${WRKSRC}/../plugins/imageformats/gif/gif.pro  \
		${WRKSRC}/../plugins/imageformats/jpeg/jpeg.pro
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc
	${LN} -sf ${LOCALBASE}/bin/uic4 ${WRKSRC}/../../bin/uic

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/QtGui.pc|${PREFIX}/libdata/pkgconfig/QtGui.pc|g' \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>
