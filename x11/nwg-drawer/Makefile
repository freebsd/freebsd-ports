PORTNAME=	nwg-drawer
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
PORTREVISION=	6
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Application drawer for sway and other wlroots compositors
WWW=		https://github.com/nwg-piotr/nwg-drawer

LICENSE=	AGPLv3 MIT
LICENSE_COMB=	multi
LICENSE_FILE_AGPLv3=	${WRKSRC_diamondburned_gotk4_pkg}/LICENSE.md
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	KarpelesLab:weak:v0.1.1:karpeleslab_weak/vendor/github.com/KarpelesLab/weak \
		allan-simon:go-singleinstance:d0997106ab37:allan_simon_go_singleinstance/vendor/github.com/allan-simon/go-singleinstance \
		diamondburned:gotk4-layer-shell:6efa9f6dc438:diamondburned_gotk4_layer_shell_pkg/vendor/github.com/diamondburned/gotk4-layer-shell \
		diamondburned:gotk4:v0.3.1:diamondburned_gotk4_pkg/vendor/github.com/diamondburned/gotk4 \
		expr-lang:expr:v1.16.9:expr_lang_expr/vendor/github.com/expr-lang/expr \
		fsnotify:fsnotify:v1.8.0:fsnotify_fsnotify/vendor/github.com/fsnotify/fsnotify \
		go4org:unsafe-assume-no-moving-gc:b99613f794b6:go4org_unsafe_assume_no_moving_gc/vendor/go4.org/unsafe/assume-no-moving-gc \
		golang:sync:v0.10.0:golang_sync/vendor/golang.org/x/sync \
		golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		joshuarubin:go-sway:v1.2.0:joshuarubin_go_sway/vendor/github.com/joshuarubin/go-sway \
		joshuarubin:lifecycle:v1.1.4:joshuarubin_lifecycle/vendor/github.com/joshuarubin/lifecycle \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		uber-go:multierr:v1.11.0:uber_go_multierr/vendor/go.uber.org/multierr
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	desktop-directories img *.css

post-patch:
# Respect PREFIX for *.desktop
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/main.go \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDATA}" \
		${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
