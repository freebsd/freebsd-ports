# New ports collection makefile for:	lwm
# Date created:		17 March 1998
# Whom:			J Han <hjh@photino.com>
#
# $FreeBSD$
#

PORTNAME=	lwm
PORTVERSION=	1.2.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.cs.york.ac.uk/pub/james/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lightweight window manager

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
