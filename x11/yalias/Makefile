# New ports collection makefile for:   yalias
# Date created:        8 September 2003
# Whom:                Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	yalias
PORTVERSION=	0.7
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/ \
		ftp://ftp.i-scream.org/pub/offog.org/files/ \
		http://ftp.i-scream.org/pub/offog.org/files/

MAINTAINER=	tim@bishnet.net
COMMENT=	An enhanced execution box with regex pattern matching

USE_GNOME=	gtk20
USE_XLIB=	yes

USE_X_PREFIX=	yes

ALL_TARGET=	yalias
MAKE_ARGS=	prefix=${PREFIX} YALIASDIR=${DATADIR}

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
