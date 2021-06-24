PORTNAME=	cage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
PORTREVISION=	3
CATEGORIES=	x11-wm

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	70ecdcb02ea0.patch:-p1 # https://github.com/Hjdskes/cage/pull/148
PATCHFILES+=	31a3571a7798.patch:-p1 # https://github.com/Hjdskes/cage/pull/209
PATCHFILES+=	1a3ab3eb3ad0.patch:-p1 # https://github.com/Hjdskes/cage/pull/198
PATCHFILES+=	ee748fec3adf.patch:-p1 # https://github.com/Hjdskes/cage/pull/197

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland kiosk

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.15.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig xorg
USE_GITHUB=	yes
USE_XORG=	pixman
GH_ACCOUNT=	Hjdskes
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES X11
OPTIONS_DEFAULT=MANPAGES X11

MANPAGES_BUILD_DEPENDS=	scdoc>=1.9.2:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

X11_MESON_TRUE=	xwayland

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
