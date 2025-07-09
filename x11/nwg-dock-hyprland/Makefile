PORTNAME=	nwg-dock-hyprland
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
PORTREVISION=	5
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK3-based dock for Hyprland
WWW=		https://github.com/nwg-piotr/nwg-dock-hyprland

LICENSE=	AGPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_AGPLv3=	${WRKSRC_diamondburned_gotk4_pkg}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	KarpelesLab:weak:v0.1.1:karpeleslab_weak/vendor/github.com/KarpelesLab/weak \
		allan-simon:go-singleinstance:d0997106ab37:allan_simon_go_singleinstance/vendor/github.com/allan-simon/go-singleinstance \
		diamondburned:gotk4-layer-shell:6efa9f6dc438:diamondburned_gotk4_layer_shell_pkg/vendor/github.com/diamondburned/gotk4-layer-shell \
		diamondburned:gotk4:v0.3.1:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		go4org:unsafe-assume-no-moving-gc:b99613f794b6:go4org_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		golang:sync:v0.10.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus
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
