PORTNAME=	nwg-look
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.4
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK3 settings editor for sway and other wlroots compositors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	creack:pty:v1.1.17:creack_pty/vendor/github.com/creack/pty \
		golang:mod:9b9b3d81d5e3:golang_mod/vendor/golang.org/x/mod \
		golang:sys:51cd9980dadf:golang_sys/vendor/golang.org/x/sys \
		golang:tools:v0.1.10:golang_tools/vendor/golang.org/x/tools \
		golang:xerrors:5ec99f83aff1:golang_xerrors/vendor/golang.org/x/xerrors \
		gotk3:gotk3:v0.6.1:gotk3_gotk3/vendor/github.com/gotk3/gotk3 \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		sirupsen:logrus:v1.8.1:sirupsen_logrus/vendor/github.com/sirupsen/logrus \
		visualfc:fastmod:v1.3.9:visualfc_fastmod/vendor/github.com/visualfc/fastmod \
		visualfc:gocode:v1.3.2:visualfc_gocode/vendor/github.com/visualfc/gocode \
		visualfc:gotools:v1.3.6:visualfc_gotools/vendor/github.com/visualfc/gotools \
		visualfc:goversion:v1.1.0:visualfc_goversion/vendor/github.com/visualfc/goversion \
		yuin:goldmark:v1.4.10:yuin_goldmark/vendor/github.com/yuin/goldmark
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2
PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/main.glade \
		share/applications/${PORTNAME}.desktop \
		share/pixmaps/${PORTNAME}.svg

post-patch:
# Respect PREFIX for *.glade and *.desktop
	@${REINPLACE_CMD} 's,/usr/share,${DATADIR:H},' \
		${WRKSRC}/main.go \
		${WRKSRC}/tools.go

post-install:
# Based on install from WRKSRC/Makefile
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/stuff/main.glade ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/stuff/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/stuff/*.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
