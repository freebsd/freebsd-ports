# $FreeBSD$

PORTNAME=	j4-dmenu-desktop
DISTVERSIONPREFIX=	r
DISTVERSION=	2.17
CATEGORIES=	x11

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Fast desktop menu (i3-dmenu-desktop replacement)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	enkore

CMAKE_OFF=	WITH_TESTS

PLIST_FILES=	bin/j4-dmenu-desktop \
		man/man1/j4-dmenu-desktop.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/j4-dmenu-desktop.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
