PORTNAME=	nwg-menu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.9
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	MenuStart plugin to nwg-panel, also capable of working standalone
WWW=		https://github.com/nwg-piotr/nwg-menu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome go:modules pkgconfig

USE_GNOME=	cairo gdkpixbuf gtk30

GO_MODULE=	github.com/nwg-piotr/nwg-menu
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	desktop-directories *.css

post-patch:
# Respect PREFIX for *.desktop and system configs
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/main.go \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
