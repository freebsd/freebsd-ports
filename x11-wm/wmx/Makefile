# New ports collection makefile for:	wmx
# Date created:		11. Jan 1998
# Whom:			Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	wmx
PORTVERSION=	6.p1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.all-day-breakfast.com/wmx/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/pl/}

MAINTAINER=	sec@42.org
COMMENT=	Extended version of wm2 - A simple window manager for X

IGNORE=		contains a severe bug, which will be fixed by the maintainer
EXPIRATION_DATE=2005-02-18
DEPRECATED=	"${IGNORE}"

USE_X_PREFIX=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/wmx/menu
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README.contrib ${PREFIX}/share/doc/wmx
.endif

.include <bsd.port.mk>
