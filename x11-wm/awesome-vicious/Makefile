# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	awesome-vicious
PORTVERSION=	2.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://git.sysphere.org/vicious/snapshot/
DISTNAME=	vicious-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Widgets for the awesome window manager

LICENSE=	GPLv2

RUN_DEPENDS=	awesome:${PORTSDIR}/x11-wm/awesome

USE_XZ=		yes
NO_BUILD=	yes
NO_INSTALL=	yes
PORTDOCS=	README TODO CHANGES LICENSE

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	@${MKDIR} ${PREFIX}/share/awesome/lib/vicious
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${CP} -fr ${WRKSRC}/ ${PREFIX}/share/awesome/lib/vicious
.for i in ${PORTDOCS}
	@${RM} ${PREFIX}/share/awesome/lib/vicious/${i}
.endfor

.include <bsd.port.mk>
