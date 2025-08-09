PORTNAME=	wofi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.1
CATEGORIES=	x11 wayland
MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Launcher/menu program for wlroots-based compositors
WWW=		https://sr.ht/~scoopta/wofi

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		gnome meson pkgconfig
USE_GNOME=	cairo gdkpixbuf gtk30

post-patch:
	@${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' \
		${WRKSRC}/man/${PORTNAME}.7 \
		${WRKSRC}/modes/drun.c
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nohg -e 's/hg.found()/false/' \
		-e "s/' + version + '/${DISTVERSIONFULL}/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
