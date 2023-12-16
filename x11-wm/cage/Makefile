PORTNAME=	cage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.5
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	638d4fb71555.patch:-p1 # https://github.com/cage-kiosk/cage/pull/148

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland kiosk
WWW=		https://www.hjdskes.nl/projects/cage/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols \
		wlroots>=0.16.0:x11-toolkits/wlroots
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots.so:x11-toolkits/wlroots \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	cage-kiosk
PLIST_FILES=	bin/${PORTNAME}

CONFLICTS_INSTALL=	${PORTNAME}-devel

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

.include "${.CURDIR:H:H}/x11-toolkits/wlroots016/override.mk"
.include <bsd.port.mk>
