# New ports collection makefile for:   xmove
# Version required:    2.0
# Date created:        16 Jan 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $Id$
#

DISTNAME=	xmove.2.0beta2
PKGNAME=	xmove-2.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/xmove/

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/xmove
USE_X11=	yes

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	${CP} ${WRKSRC}/man/man1/xmove.1 ${WRKSRC}/man/man1/xmovectrl.1 ${X11BASE}/man/man1

MAN1=		xmove.1 xmovectrl.1

.include <bsd.port.mk>
