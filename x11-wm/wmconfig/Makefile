# New ports collection makefile for:	wmconfig
# Whom:					Tommy Scheunemann <net@arrishq.org>
# Date created:		17 August 2003
#
# $FreeBSD$
#

PORTNAME=	wmconfig
PORTVERSION=	1.2.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.arrishq.net/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Menu generation tool for X window managers

USE_BZIP2=	yes
USE_GETOPT_LONG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		wmconfig.1x

PORTDOCS=	AUTHORS NEWS README TODO

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
