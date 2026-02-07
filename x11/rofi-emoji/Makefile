PORTNAME=	rofi-emoji
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.0
CATEGORIES=	x11

MAINTAINER=	maja.reberc@freedommail.ch
COMMENT=	Emoji selector plugin for rofi
WWW=		https://github.com/Mange/rofi-emoji

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rofi:x11/rofi
RUN_DEPENDS=	rofi:x11/rofi \
		xclip:x11/xclip \
		xdotool:x11/xdotool \
		xsel:x11/xsel-conrad

USES=		autoreconf gettext-runtime gnome libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	Mange
USE_GNOME=	cairo glib20

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/^dist_pkgdata_DATA/s/README.md LICENSE//' ${WRKSRC}/Makefile.am

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
