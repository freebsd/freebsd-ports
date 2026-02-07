PORTNAME=	wayfire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.1
CATEGORIES=	x11-wm wayland

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	3D Wayland compositor
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		evdev-proto>0:devel/evdev-proto \
		glm>=0.9.8:math/glm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		wf-config>=0.10.0<0.11.0:devel/wf-config
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libinotify.so:devel/libinotify \
		libinput.so:x11/libinput \
		libpng.so:graphics/png \
		libudev.so:devel/libudev-devd \
		libwayland-server.so:graphics/wayland \
		libwf-config.so:devel/wf-config \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
		libxkbcommon.so:x11/libxkbcommon \
		libyyjson.so:devel/yyjson
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:indirect compiler:c++17-lang gl gnome jpeg meson \
		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	WayfireWM:wf-touch:093d894:wftouch/subprojects/wf-touch \
		WayfireWM:wf-utils:3ef27d1:wfutils/subprojects/wf-utils
USE_GL=		egl glesv2
USE_GNOME=	cairo pango
USE_XORG=	pixman
MESON_ARGS=	-Dtests=disabled \
		-Dwf-touch:tests=disabled \
		${NULL}

.if !exists(/usr/include/omp.h)
# LLVM openmp in base doesn't support powerpc, armv6, armv7 yet
MESON_ARGS+=	-Denable_openmp=false
.endif

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

X11_USE=		XORG=xcb
X11_MESON_ENABLED=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.ini ${STAGEDIR}${EXAMPLESDIR}

pre-test:
	@if [ ! -e ${WRKDIR}/.meson_build_tests ]; then \
		${RM} ${CONFIGURE_COOKIE} ${BUILD_COOKIE}; \
		${MAKE} -C${.CURDIR} build MESON_ARGS="${MESON_ARGS} --reconfigure \
			${MESON_ARGS:M*tests*:S/=dis/=en/}"; \
		${TOUCH} ${WRKDIR}/.meson_build_tests; \
	fi

.include <bsd.port.mk>
