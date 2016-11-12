# $FreeBSD$

PORTNAME=	gui
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	x11-toolkits graphics
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt graphical user interface module

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libharfbuzz.so:print/harfbuzz \
		libpng.so:graphics/png \
		libxcb.so:x11/libxcb \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-icccm.so:x11/xcb-util-wm \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		compiler:features jpeg
USE_GL=		gl egl
USE_GNOME=	glib20
USE_QT5=	core dbus network qmake_build buildtools_build
QT_DIST=	base
USE_XORG=	ice sm x11 xi xrender
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-no-eglfs \
		-no-evdev \
		-system-harfbuzz
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

BUILD_WRKSRC=	${WRKSRC}/src/${PORTNAME}
INSTALL_WRKSRC=	${BUILD_WRKSRC}

# Build and install QtPlatformSupport and default QPA plugins (XCB,
# minimal and offscreen). QtGui won't work without (one of) them, but
# they depend on QtGui itself, so they can't be added as dependencies.
# QtPlatformSupport doesn't need to be installed (it's a static
# library), but might be needed by people porting Qt on new platforms.
MORE_WRKSRCS=	src/platformheaders \
		src/platformsupport \
		src/plugins/platforms \
		src/plugins/generic

# Image formats are split through different tarballs, these are the
# main ones; input contexts require no additional dependency.
MORE_WRKSRCS+=	src/plugins/imageformats \
		src/plugins/platforminputcontexts

# openglextensions is the static library to use for further things like qtcanvas3d
MORE_WRKSRCS+=	src/openglextensions

QT_DEFINES=	ACCESSIBILITY DBUS FONTCONFIG FREETYPE GLIB \
		IMAGEFORMAT_PNG OPENGL SHAPE XCB XKB XKBCOMMON XRENDER
QT_CONFIG=	accessibility accessibility-atspi-bridge dbus \
		fontconfig glib opengl png system-freetype \
		system-jpeg system-png xcb xcb-glx xcb-render \
		xcb-xlib xinput2 xlib xrender

# Inherited from Qt 4.
.if defined(PACKAGE_BUILDING)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/encodings/encodings.dir:x11-fonts/encodings \
		xorg-fonts-truetype>0:x11-fonts/xorg-fonts-truetype
.endif

CFLAGS_powerpc64=	-mminimal-toc

.include <bsd.port.pre.mk>

# Base GCC fails to build qdrawhelper.cpp:
# painting/qdrawhelper.cpp: In function 'void qConvertARGB64PMToA2RGB30PM_sse2(uint*, const QRgba64*, int)':
# painting/qdrawhelper.cpp:1276: note: use -flax-vector-conversions to permit conversions between vectors with differing element types or numbers of subparts
# painting/qdrawhelper.cpp:1276: error: cannot convert 'int __vector__' to 'long long int __vector__' for argument '1' to 'long long int __vector__ __builtin_ia32_psrlqi128(long long int __vector__, int)'
# painting/qdrawhelper.cpp:1277: error: cannot convert 'int __vector__' to 'long long int __vector__' for argument '1' to 'long long int __vector__ __builtin_ia32_psrlqi128(long long int __vector__, int)'
# painting/qdrawhelper.cpp:1278: error: cannot convert 'int __vector__' to 'long long int __vector__' for argument '1' to 'long long int __vector__ __builtin_ia32_psrlqi128(long long int __vector__, int)'
# painting/qdrawhelper.cpp:1282: error: cannot convert 'int __vector__' to 'long long int __vector__' for argument '1' to 'long long int __vector__ __builtin_ia32_psrlqi128(long long int __vector__, int)'
.if ${COMPILER_TYPE} == gcc && ${COMPILER_VERSION} <= 42
CXXFLAGS+=	-flax-vector-conversions
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
EXTRA_PATCHES+=  ${FILESDIR}/extrapatch-src_gui_painting_qcolor.cpp
.endif

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

.include <bsd.port.post.mk>
