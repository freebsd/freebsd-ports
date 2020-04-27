# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awesome-vicious
PORTVERSION=	2.4.0
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-wm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Widgets for the awesome window manager

LICENSE=	GPLv2

RUN_DEPENDS=	awesome:x11-wm/awesome

USES=		tar:xz

USE_GITHUB=	yes
GH_ACCOUNT=	vicious-widgets
GH_PROJECT=	vicious

NO_BUILD=	yes
PORTDOCS=	README.md TODO Changes.md LICENSE

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${CP} -fr ${WRKSRC}/ ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious
	@${RM} ${PORTDOCS:S,^,${STAGEDIR}${PREFIX}/share/awesome/lib/vicious/,}

.include <bsd.port.mk>
