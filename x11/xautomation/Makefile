PORTNAME=	xautomation
PORTVERSION=	1.09
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://hoopajoo.net/static/projects/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Control X from the command line for scripts
WWW=		https://hoopajoo.net/projects/xautomation.html

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png

USES=		localbase:ldflags xorg
USE_XORG=	xtst

GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
