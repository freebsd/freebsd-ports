# New ports collection makefile for:	wmx
# Date created:		11. Jan 1998
# Whom:			Stefan Zehl <sec@42.org>
#
# $FreeBSD$
#

PORTNAME=	wmx
PORTVERSION= 	5.6
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.42.org/pub/wmx/ \
		http://www.all-day-breakfast.com/wmx/
DISTNAME=	${PORTNAME}-5sec6

MAINTAINER=	sec@42.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmx ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/lib/X11/wmx/menu
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/wmx
	${INSTALL_DATA} ${WRKSRC}/README.contrib ${PREFIX}/share/doc/wmx
.endif

.include <bsd.port.mk>
