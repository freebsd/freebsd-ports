# $FreeBSD$

PORTNAME=	wofi
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.2
CATEGORIES=	x11
#MASTER_SITES=	https://hg.sr.ht/~scoopta/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
MASTER_SITES+=	LOCAL/jbeich # https://todo.sr.ht/~sircmpwn/hg.sr.ht/33

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Launcher/menu program for wlroots-based compositors

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.md

LIB_DEPENDS=	libwayland-client.so:graphics/wayland

USES=		gnome meson pkgconfig
USE_CSTD=	gnu99 # https://lists.sr.ht/~scoopta/wofi/patches/10055
USE_GNOME=	gdkpixbuf2 gtk30

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/man/${PORTNAME}.7 \
		${WRKSRC}/modes/drun.c
# Extract (snapshot) version from the port instead of meson.build
	@${REINPLACE_CMD} -i .nohg -e 's/hg.found()/false/' \
		-e "s/' + version + '/${DISTVERSIONFULL}/" \
		${WRKSRC}/meson.build

.include <bsd.port.mk>
