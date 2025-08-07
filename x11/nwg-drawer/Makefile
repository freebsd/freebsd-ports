PORTNAME=	nwg-drawer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.4
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Application drawer for wlroots-based Wayland compositors
WWW=		https://github.com/nwg-piotr/nwg-drawer

LICENSE=	MIT MPL20
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE
LICENSE_FILE_MPL20=	${WRKSRC}/LICENSE-gotk4

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gnome go:modules pkgconfig

USE_GNOME=	cairo gdkpixbuf gtk30

GO_MODULE=	github.com/nwg-piotr/nwg-drawer
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	desktop-directories img *.css

post-patch:
# Respect PREFIX for *.desktop
	@${REINPLACE_CMD} -e 's|/usr/share|${DATADIR:H}|' \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
