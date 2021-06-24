PORTNAME=	wayfire
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.2
PORTREVISION=	2
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	7b664f055249.patch:-p1 # https://github.com/WayfireWM/wayfire/pull/1230
PATCHFILES+=	8096b2f6d190.patch:-p1 # wlroots 0.15
PATCHFILES+=	394fc3a86db4.patch:-p1 # wlroots 0.15
PATCHFILES+=	839c11ec4d39.patch:-p1 # wlroots 0.15
PATCHFILES+=	be3113dda0c9.patch:-p1 # wlroots 0.15
PATCHFILES+=	2d212482870a.patch:-p1 # wlroots 0.15
PATCHFILES+=	e6f403af09cc.patch:-p1 # wlroots 0.15
PATCHFILES+=	7355cf0f1f64.patch:-p1 # wlroots 0.15
PATCHFILES+=	f9446a5d7496.patch:-p1 # wlroots 0.15
PATCHFILES+=	a4e83480ad60.patch:-p1 # wlroots 0.15
PATCHFILES+=	292b0d28aab5.patch:-p1 # wlroots 0.15
PATCHFILES+=	6603ba65e1c4.patch:-p1 # wlroots 0.15

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	3D Wayland compositor

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wf-config>=0.7.0<0.8.0:devel/wf-config \
		${LOCALBASE}/include/xf86drmMode.h:graphics/libdrm \
		wayland-protocols>=1.12:graphics/wayland-protocols \
		glm>=0.9.8:math/glm \
		wlroots>=0.15.0<0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libinotify.so:devel/libinotify \
		libwf-config.so:devel/wf-config \
		libpng.so:graphics/png \
		libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libinput.so:x11/libinput \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c++17-lang gl gnome jpeg meson pkgconfig xorg
USE_GITHUB=	yes
USE_GL=		egl glesv2
USE_GNOME=	cairo
USE_XORG=	pixman
GH_ACCOUNT=	WayfireWM
GH_TUPLE=	WayfireWM:wf-touch:8974eb0:wftouch/subprojects/wf-touch \
		WayfireWM:wf-utils:889fdaf:wfutils/subprojects/wf-utils

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

.include <bsd.port.mk>
