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

LIB_DEPENDS?=	png:${PORTSDIR}/graphics/png \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig

MAKE_JOBS_SAFE=	yes

USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build corelib
QT_NONSTANDARD=	yes
QT_DIST=	yes

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/qt4
USE_XORG=	xrender xrandr xinerama inputproto xfixes \
		sm xcursor xext x11 ice xi xt

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH 
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/dbus src/network src/opengl src/phonon \
		src/qt3support src/script src/sql src/svg src/testlib \
		src/tools src/xml src/xmlpatterns src/3rdparty/clucene \
		src/3rdparty/kdebase src/3rdparty/kdelibs src/3rdparty/webkit
EXTRACT_AFTER_ARGS=	| ${TAR} -xf -
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

WRKSRC=		${WRKDIR}/${DISTNAME}/src/${PORTNAME}
CONFIGURE_WRKSRC=${WRKSRC}/../../
PATCH_WRKSRC=${CONFIGURE_WRKSRC}

CONFIGURE_ARGS+=	-I../../include/Qt -I../../include

.include "${.CURDIR}/../../devel/qt4/files/Makefile.options"

.if ${QT4_OPTIONS:MCUPS}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcups.a:${PORTSDIR}/print/cups-client
CONFIGURE_ARGS+=-cups -L${LOCALBASE}/lib -I. -I${LOCALBASE}/include
.endif

.if ${QT4_OPTIONS:MQGTKSTYLE}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=-gtkstyle
.else
CONFIGURE_ARGS+=-no-gtkstyle
.endif

.if ${QT4_OPTIONS:MNAS}
LIB_DEPENDS+=	audio:${PORTSDIR}/audio/nas
CONFIGURE_ARGS+=-system-nas-sound
.else
CONFIGURE_ARGS+=-no-nas-sound
.endif

pre-configure:
	${CP} ${.CURDIR}/../../devel/qt4/files/configure ${CONFIGURE_WRKSRC}
	${MKDIR} ${WRKSRC}/../../mkspecs
	${LN} -sf ${LOCALBASE}/bin/qmake-qt4 ${WRKSRC}/../../bin/qmake
	${LN} -sf ${LOCALBASE}/bin/moc-qt4 ${WRKSRC}/../../bin/moc
	${LN} -sf ${LOCALBASE}/bin/rcc ${WRKSRC}/../../bin/rcc
	${LN} -sf ${LOCALBASE}/bin/uic-qt4 ${WRKSRC}/../../bin/uic

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/lib/qt4/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
			-E -e 's|(.*location=).*moc|\1${PREFIX}/bin/moc-qt4|g' \
			-E -e 's|(.*location=).*uic|\1${PREFIX}/bin/uic-qt4|g' \
		${WRKSRC}/../../lib/pkgconfig/QtGui.pc

.include <bsd.port.mk>
