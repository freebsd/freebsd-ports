# New ports collection makefile for:	wmx
# Version required:	4.0
# Date created:		11. Jan 1998
# Whom:			Stefan Zehl <sec@42.org>
#
# $Id: Makefile,v 1.1.1.1 1998/06/24 10:52:08 max Exp $
#

DISTNAME=	wmx-4
PKGNAME=        wmx-4.0
CATEGORIES=	x11
MASTER_SITES=   http://www.netcomuk.co.uk/~cannam/

MAINTAINER=	sec@42.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
ALL_TARGET=	depend wmx

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
.endif

.include <bsd.port.mk>
