# New ports collection makefile for:	crystal
# Date Created:				22 July 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kde-icontheme-crystal
PORTVERSION=	3.7b
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.everaldo.com/crystal/
DISTNAME=	crystal_beta
DIST_SUBDIR=	KDE

MAINTAINER=	olgeni@FreeBSD.org

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

post-extract:
		@${FIND} ${WRKSRC} -name .xvpics | ${XARGS} ${RM} -r

do-install:
		@${CP} -r ${WRKSRC}/Crystal /usr/local/share/icons/

.include <bsd.port.mk>
