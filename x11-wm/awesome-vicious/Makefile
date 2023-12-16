PORTNAME=	awesome-vicious
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	x11-wm

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Widgets for the awesome window manager
WWW=		https://vicious.readthedocs.io/en/latest/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	awesome:x11-wm/awesome

USE_GITHUB=	yes
GH_ACCOUNT=	vicious-widgets
GH_PROJECT=	vicious

NO_ARCH=	yes
NO_BUILD=	yes
PORTDOCS=	CHANGELOG.rst CONTRIBUTING.rst README.md TODO

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious
	(cd ${WRKSRC} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious)
	@${RM} ${PORTDOCS:S,^,${STAGEDIR}${PREFIX}/share/awesome/lib/vicious/,}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
