PORTNAME=	nwg-bar
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.6
PORTREVISION=	12
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK3-based button bar for sway and other wlroots-based compositors
WWW=		https://github.com/nwg-piotr/nwg-bar

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	allan-simon:go-singleinstance:d0997106ab37:allan_simon_go_singleinstance/vendor/github.com/allan-simon/go-singleinstance \
		dlasky:gotk3-layershell:b0c42cd8474f:dlasky_gotk3_layershell/vendor/github.com/dlasky/gotk3-layershell \
		golang:sync:v0.6.0:golang_sync/vendor/golang.org/x/sync \
		gotk3:gotk3:v0.6.2:gotk3_gotk3/vendor/github.com/gotk3/gotk3 \
		joshuarubin:go-sway:v1.2.0:joshuarubin_go_sway/vendor/github.com/joshuarubin/go-sway \
		joshuarubin:lifecycle:v1.1.4:joshuarubin_lifecycle/vendor/github.com/joshuarubin/lifecycle \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	images *.css *.json

post-patch:
# Respect PREFIX for button images
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/config/*.json \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	@${CP} -p ${WRKSRC}/config/* ${WRKSRC}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
