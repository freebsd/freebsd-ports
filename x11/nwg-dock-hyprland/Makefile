PORTNAME=	nwg-dock-hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.8
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK3-based dock for Hyprland
WWW=		https://github.com/nwg-piotr/nwg-dock-hyprland

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome go:modules pkgconfig

USE_GNOME=	cairo gdkpixbuf gtk30

GO_MODULE=	github.com/nwg-piotr/nwg-dock-hyprland
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2

post-patch:
# Respect PREFIX for *.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/config/* ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} images ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
