PORTNAME=	bbdock
PORTVERSION=	0.2.9
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://bbdock.nethence.com/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Application launcher for Blackbox-like window manager
WWW=		https://bbdock.nethence.com/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png

USES=		xorg
USE_CXXSTD=	c++14
USE_XORG=	x11

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/bbdock
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
