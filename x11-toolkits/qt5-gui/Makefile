# $FreeBSD$

PORTNAME=	gui
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	3
CATEGORIES=	x11-toolkits graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical user interface module

BUILD_DEPENDS=	${LOCALBASE}/include/linux/input.h:devel/evdev-proto \
		${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/include/xf86drm.h:graphics/libdrm \
		at-spi2-core>=0:accessibility/at-spi2-core
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libevdev.so:devel/libevdev \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libinput.so:x11/libinput \
		libpng.so:graphics/png \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb.so:x11/libxcb \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	${LOCALBASE}/include/vulkan/vulkan.h:graphics/vulkan-headers \
		${LOCALBASE}/libdata/pkgconfig/dri.pc:graphics/mesa-dri \
		xdg-open:devel/xdg-utils

USES=			compiler:c++11-lang gl gnome jpeg localbase \
			qmake:no_env qt-dist:5,base
USE_GL=			egl gl
USE_GNOME=		glib20
USE_QT=			core dbus network buildtools_build qmake_build
QT_BINARIES=		yes
QT_CONFIG=		accessibility accessibility-atspi-bridge dbus \
			fontconfig glib opengl png system-freetype system-jpeg \
			system-png xcb xcb-glx xcb-render xcb-xlib xinput2 xlib \
			xrender
QT_DEFINES=		ACCESSIBILITY DBUS FONTCONFIG FREETYPE GLIB \
			IMAGEFORMAT_PNG OPENGL SHAPE XCB XKB XKBCOMMON XRENDER
USE_XORG=		ice sm xi xrender
HAS_CONFIGURE=		yes
CONFIGURE_ARGS=		-no-eglfs \
			-no-libudev \
			-system-harfbuzz
# Explicitly set to c++14 to avoid c++17/c++1z, since libX11's headers
# are using the obsolete 'register' keyword.
CONFIGURE_ARGS+=	-c++std \
			c++14

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

OPTIONS_DEFINE=		X11
OPTIONS_DEFAULT=	X11
OPTIONS_SUB=		yes

X11_USES=	xorg
X11_USE=	xorg=x11

# Build and install QtPlatformSupport and default QPA plugins (XCB,
# minimal and offscreen). QtGui won't work without (one of) them, but
# they depend on QtGui itself, so they can't be added as dependencies.
# QtPlatformSupport doesn't need to be installed (it's a static
# library), but might be needed by people porting Qt on new platforms.
_MORE_WRKSRCS=	src/platformheaders src/platformsupport src/plugins/platforms \
		src/plugins/generic

# Image formats are split through different tarballs, these are the
# main ones; input contexts require no additional dependency.
_MORE_WRKSRCS+=	src/plugins/imageformats src/plugins/platforminputcontexts

# openglextensions is the static library to use for further things like qtcanvas3d
_MORE_WRKSRCS+=	src/openglextensions

# Inherited from Qt 4.
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/encodings/encodings.dir:x11-fonts/encodings \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype
.endif

post-configure:
.for d in src/tools/qvkgen src/gui ${_MORE_WRKSRCS}
	${MKDIR} ${WRKSRC}/${d}
	cd ${WRKSRC}/${d} && ${SETENV} ${QMAKE_ENV} ${_QMAKE} ${QMAKE_ARGS} ${WRKSRC}/${d}
.endfor

pre-build:
.for d in src/tools/qvkgen
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-build:
.for d in ${_MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${_MAKE_JOBS} ${MAKE_ARGS} ${ALL_TARGET}
.endfor

post-install:
.for d in src/tools/qvkgen ${_MORE_WRKSRCS}
	@cd ${WRKSRC}/${d} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} \
		${MAKE_ARGS} ${INSTALL_TARGET}
.endfor

.include <bsd.port.mk>
