# New ports collection makefile for:		wmDeskGuide
# Date created:					26 July 2002
# Whom:						Adam Weinberger <adam@vectors.cx>
#
# $FreeBSD$
#

PORTNAME=	wmDeskGuide
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://charybda.icm.edu.pl/~jarwyp/download/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	A pager for the WindowMaker dock

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomelibs gdkpixbuf

do-install:
		@${INSTALL_PROGRAM} ${WRKSRC}/wmDeskGuide ${PREFIX}/bin
.if !defined(NOPORTDOCS)
		@${MKDIR} ${DOCSDIR}
		@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
