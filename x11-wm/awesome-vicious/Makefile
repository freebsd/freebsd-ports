# New ports collection makefile for:	awesome-vicious
# Date created:				07 May 2012
# Whom:					William Grzybowski
#
# $FreeBSD$
#

PORTNAME=	awesome-vicious
PORTVERSION=	2.1.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://git.sysphere.org/vicious/snapshot/
DISTNAME=	vicious-${PORTVERSION}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Widgets for the awesome window manager

RUN_DEPENDS=	awesome:${PORTSDIR}/x11-wm/awesome

USE_XZ=		yes
NO_BUILD=	yes
NO_INSTALL=	yes
PORTDOCS=	README TODO CHANGES LICENSE

do-install:
	@${MKDIR} ${PREFIX}/share/awesome/lib/vicious
.if !defined(NOPORTDOCS)
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
