# New ports collection Makefile for: amiwm-0.20pl28
# Version required: 0.20pl28
# Date created: 13 November 1997
# Whom: Douglas Carmichael <dcarmich@mcs.com>
#
# $Id: Makefile,v 1.2 1998/08/05 09:31:40 asami Exp $
#

DISTNAME=	amiwm0.20pl28
PKGNAME=	amiwm-0.20p28
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/X11/wm/amiwm/

MAINTAINER=	ports@FreeBSD.org

WRKSRC=		${WRKDIR}/amiwm
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		amiwm.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/amiwm
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/amiwm
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/amiwm
	${INSTALL_DATA} ${WRKSRC}/README.modules ${PREFIX}/share/doc/amiwm
.endif

.include <bsd.port.mk>
