# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awesome-vicious
PORTVERSION=	2.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://git.sysphere.org/vicious/snapshot/ \
		LOCAL/wg
DISTNAME=	vicious-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Widgets for the awesome window manager

LICENSE=	GPLv2

RUN_DEPENDS=	awesome:${PORTSDIR}/x11-wm/awesome

USE_XZ=		yes
NO_BUILD=	yes
NO_INSTALL=	yes
PORTDOCS=	README TODO CHANGES LICENSE

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	@${CP} -fr ${WRKSRC}/ ${STAGEDIR}${PREFIX}/share/awesome/lib/vicious
	@${RM} ${PORTDOCS:S,^,${STAGEDIR}${PREFIX}/share/awesome/lib/vicious/,}

.include <bsd.port.mk>
