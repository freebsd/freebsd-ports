PORTNAME=	cage
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	x11-wm wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland kiosk
WWW=		https://www.hjdskes.nl/projects/cage/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	evdev-proto>0:devel/evdev-proto \
		wayland-protocols>=1.14:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-server.so:graphics/wayland \
		libwlroots-0.18.so:x11-toolkits/wlroots018 \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 meson pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	cage-kiosk
PLIST_FILES=	bin/${PORTNAME}

CONFLICTS_INSTALL=	${PORTNAME}-devel

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc>=1.9.2:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

post-patch:
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nogit -e 's/git.found()/false/' \
		-e '/project_version/s/@0@/${DISTVERSIONFULL}/' \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
