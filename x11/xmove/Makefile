# New ports collection makefile for:   xmove
# Version required:    2.0
# Date created:        16 Jan 1997
# Whom:                Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

DISTNAME=	xmove.2.0beta2
PKGNAME=	xmove-2.0b2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.cs.columbia.edu/pub/xmove/

MAINTAINER=	sec@42.org

WRKSRC=		${WRKDIR}/xmove
USE_X_PREFIX=	yes
MAN1=		xmove.1 xmovectrl.1

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
.for man in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/man/man1/${man} ${X11BASE}/man/man1
.endfor

.include <bsd.port.mk>
