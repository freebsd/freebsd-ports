# Created by: William Grzybowski <wg@FreeBSD.org>

PORTNAME=	awesome-vicious
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.0
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Widgets for the awesome window manager

LICENSE=	GPLv2

RUN_DEPENDS=	awesome:x11-wm/awesome

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	vicious-widgets
GH_PROJECT=	vicious

NO_ARCH=	yes
NO_BUILD=	yes
PORTDOCS=	CHANGELOG.rst CONTRIBUTING.rst LICENSE README.md TODO

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
