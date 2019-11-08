# $FreeBSD$

PORTNAME=	widgets
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt C++ widgets module

USES=		compiler:c++11-lang qmake:no_env qt-dist:5,base xorg
USE_QT=		core gui qmake_build buildtools_build
USE_XORG=	x11
HAS_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

MORE_WRKSRCS=	src/tools/uic

QT_DEFINES=	ACCESSIBILITY WIDGETS XSYNC
QT_CONFIG=	accessibility accessibility-atspi-bridge xlib

OPTIONS_DEFINE=	GTK3
OPTIONS_SUB=	YES

GTK3_DESC=	GTK+-based Qt theme
GTK3_USES=	gnome
GTK3_USE=	GNOME=gtk30 QT=dbus
GTK3_CONFIGURE_ON=	-gtk
GTK3_CONFIGURE_OFF=	-no-gtk

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK3}
QT_DEFINES+=	STYLE_GTK
QT_CONFIG+=	gtk
MORE_WRKSRCS+=	src/plugins/platformthemes
.else
QT_DEFINES+=	-STYLE_GTK
QT_CONFIG+=	-gtk
.endif

post-configure:
.for d in src/tools/uic src/widgets ${MORE_WRKSRCS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

pre-build:
	cd ${WRKSRC}/src/tools/uic && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}

post-build:
.for d in ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
.for d in src/tools/uic ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endfor
	${INSTALL_DATA} ${BUILD_WRKSRC}/dialogs/images/qtlogo-64.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/qt5logo.png

.include <bsd.port.mk>
