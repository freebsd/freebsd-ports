# -*-mode: makefile-*-
# New ports collection makefile for:	qt40
# Date created:				Wed Jun 29 11:49:42 CEST 2005
# Whom:					lofi@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gui
PORTVERSION=	${QT4_VERSION}
PORTREVISION=	0
CATEGORIES?=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_QT}
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-x11-opensource-src-${PORTVERSION}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical user interface library

LIB_DEPENDS?=	png:${PORTSDIR}/graphics/png

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build corelib
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_XLIB=	yes

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
PATCH_WRKSRC=${CONFIGURE_WRKSRC}

OPTIONS=	CUPS "Enable printing support (requires CUPS)" off \
		NAS "Enable sound support (requires NAS)" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CUPS) || defined(PACKAGE_BUILDING)
BUILD_DEPENDS+=	cupsd:${PORTSDIR}/print/cups-base
CUPS=		-cups -L${LOCALBASE}/lib -I. -I${LOCALBASE}/include
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
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../../bin/uic

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
		${WRKSRC}/../../lib/pkgconfig/*Qt*

.include <bsd.port.post.mk>
