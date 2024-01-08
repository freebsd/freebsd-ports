PORTNAME=	gmrun
DISTVERSION=	1.4w
CATEGORIES=	x11

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Run utiliy with a slim design and bash style auto-completion
WWW=		https://github.com/wdlkmpx/gmrun

LICENSE=	GPLv2

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gmake gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	wdlkmpx

USE_GNOME=	cairo gdkpixbuf2 gtk30
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/gmrunrc \
		${STAGEDIR}${PREFIX}/etc/gmrunrc.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
