PORTNAME=	nwg-dock
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
PORTREVISION=	6
CATEGORIES=	x11

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK3-based dock for sway
WWW=		https://github.com/nwg-piotr/nwg-dock

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	allan-simon:go-singleinstance:d0997106ab37:allan_simon_go_singleinstance/vendor/github.com/allan-simon/go-singleinstance \
		dlasky:gotk3-layershell:5c5115f0d774:dlasky_gotk3_layershell/vendor/github.com/dlasky/gotk3-layershell \
		golang:sync:v0.10.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		gotk3:gotk3:ff349ae13f56:gotk3_gotk3/vendor/github.com/gotk3/gotk3 \
		joshuarubin:go-sway:v1.2.0:joshuarubin_go_sway/vendor/github.com/joshuarubin/go-sway \
		joshuarubin:lifecycle:v1.1.4:joshuarubin_lifecycle/vendor/github.com/joshuarubin/lifecycle \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	images *.css

post-patch:
# Respect PREFIX for *.desktop
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	@${CP} -p ${WRKSRC}/config/*.css ${WRKSRC}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
