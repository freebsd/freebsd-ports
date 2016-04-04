# Created by: lofi@FreeBSD.org
# $FreeBSD$

PORTNAME=	gui
DISTVERSION=	${QT4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt4-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical user interface module

LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USE_QT4=	qmake_build moc_build rcc_build uic_build corelib
QT_DIST=	yes
USES=		pkgconfig

HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}
USE_XORG=	xrender xrandr xinerama inputproto xfixes \
		sm xcursor xext x11 ice xi xt

ALL_TARGET=	first
CONFIGURE_ENV?=	QTDIR=${WRKSRC} PATH=${WRKSRC}/bin:$$PATH
MAKE_ENV?=	QTDIR=${WRKSRC} LD_LIBRARY_PATH=${WRKSRC}/lib:$$LD_LIBRARY_PATH \
		PATH=${WRKSRC}/bin:$$PATH

DO_NOT_EXTRACT=	demos doc examples mkspecs qmake tools translations \
		src/activeqt src/dbus src/multimedia src/network src/opengl \
		src/openvg src/phonon src/qt3support src/s60installs \
		src/s60main src/script src/scripttools src/sql src/svg \
		src/testlib src/tools src/winmain src/xml src/xmlpatterns \
		src/3rdparty/clucene src/3rdparty/freetype \
		src/3rdparty/libjpeg src/3rdparty/libmng src/3rdparty/libpng \
		src/3rdparty/libtiff src/3rdparty/phonon src/3rdparty/webkit
.for dne in ${DO_NOT_EXTRACT}
EXTRACT_AFTER_ARGS+=	--exclude '${DISTNAME}/${dne}'
.endfor

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

CONFIGURE_ARGS+=	-I../../include/QtCore -I../../include/QtGui \
			-I../../include/Qt -I../../include

FONTSCALE=	${LOCALBASE}/share/fonts/TTF/luximb.ttf
FONTENCOD=	${LOCALBASE}/share/fonts/encodings/encodings.dir

.include "${.CURDIR}/../../devel/qt4/files/Makefile.options"

.if ${QT4_OPTIONS:MCUPS}
LIB_DEPENDS+=	libcups.so:print/cups
CONFIGURE_ARGS+=-cups -L${LOCALBASE}/lib -I. -I${LOCALBASE}/include
.endif

.if ${QT4_OPTIONS:MNAS}
LIB_DEPENDS+=	libaudio.so:audio/nas
CONFIGURE_ARGS+=-system-nas-sound
.else
CONFIGURE_ARGS+=-no-nas-sound
.endif

.if ${QT4_OPTIONS:MQGTKSTYLE}
USE_GNOME=	gtk20
CONFIGURE_ARGS+=-gtkstyle
.else
CONFIGURE_ARGS+=-no-gtkstyle
.endif

.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype \
		${FONTENCOD}:x11-fonts/encodings
.endif

CFLAGS_powerpc64=	-mminimal-toc

pre-configure:
	${MKDIR} ${WRKSRC}/mkspecs
	${LN} -sf ${QMAKE} ${WRKSRC}/bin/qmake
	${LN} -sf ${MOC} ${WRKSRC}/bin/moc
	${LN} -sf ${RCC} ${WRKSRC}/bin/rcc
	${LN} -sf ${UIC} ${WRKSRC}/bin/uic

post-configure:
	${REINPLACE_CMD} -e 's|${PREFIX}/${QT_LIBDIR_REL}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' \
		-e 's|.*$$(QMAKE).*||g' ${BUILD_WRKSRC}/Makefile
	${REINPLACE_CMD} -E -e 's|-L.[^[:space:]]*qt-x11-opensource.[^[:space:]]*lib||g' \
		-E -e 's|(.*location=).*moc|\1${PREFIX}/${QT_BINDIR_REL}/${MOC:T}|g' \
		-E -e 's|(.*location=).*uic|\1${PREFIX}/${QT_BINDIR_REL}/${UIC:T}|g' \
		${WRKSRC}/lib/pkgconfig/QtGui.pc

post-install:
	${INSTALL_DATA} ${BUILD_WRKSRC}/dialogs/images/qtlogo-64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qtlogo.png

.include <bsd.port.mk>
