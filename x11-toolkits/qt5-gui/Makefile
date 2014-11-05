# $FreeBSD$

PORTNAME=	gui
DISTVERSION=	${QT5_VERSION}
CATEGORIES=	x11-toolkits graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical user interface module

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libxcb.so:${PORTSDIR}/x11/libxcb \
		libxcb-image.so:${PORTSDIR}/x11/xcb-util-image \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms \
		libxcb-render-util.so:${PORTSDIR}/x11/xcb-util-renderutil \
		libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm \
		libxkbcommon.so:${PORTSDIR}/x11/libxkbcommon
RUN_DEPENDS=	xdg-open:${PORTSDIR}/devel/xdg-utils

USE_GL=		gl
USE_GNOME=	glib20
USE_QT5=	core dbus qmake_build buildtools_build
QT_DIST=	base
USE_XORG=	x11 xi xrender
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-eglfs \
		-no-evdev
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# Build and install QtPlatformSupport and default QPA plugins (XCB,
# minimal and offscreen). QtGui won't work without (one of) them, but
# they depend on QtGui itself, so they can't be added as dependencies.
# QtPlatformSupport doesn't need to be installed (it's a static
# library), but might be needed by people porting Qt on new platforms.
MORE_WRKSRCS=	src/platformsupport \
		src/plugins/platforms

# Image formats are split through different tarballs, these are the
# main ones; input contexts require no additional dependency.
MORE_WRKSRCS+=	src/plugins/imageformats \
		src/plugins/platforminputcontexts

QT_DEFINES=	ACCESSIBILITY DBUS FONTCONFIG FREETYPE GLIB \
		IMAGEFORMAT_PNG OPENGL SHAPE XCB XKB XKBCOMMON XRENDER
QT_CONFIG=	accessibility accessibility-atspi-bridge dbus \
		fontconfig glib opengl png system-freetype \
		system-jpeg system-png xcb xcb-glx xcb-render \
		xcb-xlib xinput2 xlib xrender

# Inherited from Qt 4.
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/encodings/encodings.dir:${PORTSDIR}/x11-fonts/encodings \
		${LOCALBASE}/lib/X11/fonts/TTF/luximb.ttf:${PORTSDIR}/x11-fonts/xorg-fonts-truetype
.endif

CFLAGS_powerpc64=	-mminimal-toc

post-build:
.for d in ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
.for d in ${MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.mk>
