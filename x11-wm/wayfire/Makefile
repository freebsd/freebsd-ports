PORTNAME=	wayfire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	x11-wm wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D Wayland compositor
WWW=		https://wayfire.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wf-config>=0.10.0<0.11.0:devel/wf-config \
		${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		glm>=0.9.8:math/glm
LIB_DEPENDS=	libevdev.so:devel/libevdev \
		libinotify.so:devel/libinotify \
		libudev.so:devel/libudev-devd \
		libwf-config.so:devel/wf-config \
		libyyjson.so:devel/yyjson \
		libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots-0.19.so:x11-toolkits/wlroots019 \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon
TEST_DEPENDS=	doctest>0:devel/doctest

USES=		cmake:indirect compiler:c++17-lang gl gnome jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl glesv2
USE_GNOME=	cairo pango
USE_XORG=	pixman
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	WayfireWM:wf-touch:093d894:wftouch/subprojects/wf-touch \
		WayfireWM:wf-utils:3ef27d1:wfutils/subprojects/wf-utils
MESON_ARGS=	-Dtests=disabled \
		-Dwf-touch:tests=disabled \
		${NULL}

# XXX https://github.com/WayfireWM/wayfire/issues/2800
USES+=		localbase

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
