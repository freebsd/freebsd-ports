PORTNAME=	nwg-look
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK settings editor adapted to work in the wlroots environment
WWW=		https://github.com/nwg-piotr/nwg-look

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xcur2png:x11/xcur2png

USES=		gnome go:modules pkgconfig

USE_GNOME=	cairo gdkpixbuf gtk30

GO_MODULE=	github.com/nwg-piotr/nwg-look
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2

post-patch:
# Respect PREFIX for *.glade and *.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	@${MKDIR} ${STAGEDIR}${DATADIR}/langs
	${INSTALL_DATA} ${WRKSRC}/langs/* ${STAGEDIR}${DATADIR}/langs
	${INSTALL_DATA} ${WRKSRC}/stuff/main.glade ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/stuff/*.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${WRKSRC}/stuff/*.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
