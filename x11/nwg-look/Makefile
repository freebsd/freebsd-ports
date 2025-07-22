PORTNAME=	nwg-look
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	x11 wayland

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	GTK settings editor adapted to work in the wlroots environment
WWW=		https://github.com/nwg-piotr/nwg-look

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig
RUN_DEPENDS=	xcur2png:x11/xcur2png

USES=		gnome go:modules pkgconfig
USE_GITHUB=	yes
USE_GNOME=	cairo gdkpixbuf gtk30
GH_ACCOUNT=	nwg-piotr
GH_TUPLE=	golang:sys:v0.29.0:golang_sys/vendor/golang.org/x/sys \
		gotk3:gotk3:ff349ae13f56:gotk3_gotk3/vendor/github.com/gotk3/gotk3 \
		sirupsen:logrus:v1.9.3:sirupsen_logrus/vendor/github.com/sirupsen/logrus
CGO_LDFLAGS+=	-Wl,--as-needed # harfbuzz, freetype2
PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR}/langs/en_US.json \
		${DATADIR}/langs/ja_JP.json \
		${DATADIR}/langs/pl_PL.json \
		${DATADIR}/langs/ru_RU.json \
		${DATADIR}/langs/zh_CN.json \
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
	${MKDIR} ${STAGEDIR}${DATADIR}/langs
	${INSTALL_DATA} ${WRKSRC}/langs/* ${STAGEDIR}${DATADIR}/langs
	${INSTALL_DATA} ${WRKSRC}/stuff/main.glade ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/stuff/*.desktop \
		${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/stuff/*.svg \
		${STAGEDIR}${PREFIX}/share/pixmaps

.include <bsd.port.mk>
