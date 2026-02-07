PORTNAME=	sakura
DISTVERSION=	3.8.9
CATEGORIES=	x11 gnome
MASTER_SITES=	https://launchpad.net/${PORTNAME}/trunk/${DISTVERSION}/+download/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE
WWW=		https://launchpad.net/sakura

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		cmake gettext gnome perl5 pkgconfig tar:bz2 xorg
USE_GNOME=	gtk30 vte3
USE_PERL5=	build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/-O2/d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
