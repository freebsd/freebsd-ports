# New ports collection makefile for:	ratpoison
# Date created:		January 20, 2001
# Whom:			Gergely Nagy <8@free.bsd.hu>
#
# $FreeBSD$
#

PORTNAME=	ratpoison
PORTVERSION=	0.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	8@free.bsd.hu

MAN1=		ratpoison.1
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if		defined(NOPORTDOCS)
INSTALL_TARGET=	SUBDIRS=src install-exec
.endif

.include <bsd.port.mk>
