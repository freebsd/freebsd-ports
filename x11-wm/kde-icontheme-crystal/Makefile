# New ports collection makefile for:	kde-icontheme-crystal
# Date Created:				22 July 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kde-icontheme-crystal
PORTVERSION=	0.8
PORTEPOCH=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://crystalicons.planetfurry.com/
DISTNAME=	crystal_icons
DIST_SUBDIR=	KDE

MAINTAINER=	olgeni@FreeBSD.org

WRKSRC=		${WRKDIR}
NO_BUILD=	yes

post-extract:
		@${FIND} ${WRKSRC} -name .xvpics | ${XARGS} ${RM} -r

do-install:
		@${MKDIR} ${PREFIX}/share/icons
		@${CP} -r ${WRKSRC}/crystal ${PREFIX}/share/icons/
		@${CHMOD} -R a=rX,u+w ${PREFIX}/share/icons/crystal

.include <bsd.port.mk>
