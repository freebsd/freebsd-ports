# New ports collection makefile for:	qrash
# Date created:		Oct 27, 1999
# Whom:			Trevor Johnson <trevor@jpj.net>
#
# $FreeBSD$
#

PORTNAME=	qrash
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://qmg.org/files/demos/qmg/ \
		ftp://qmg.org/pub/demos/qmg/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/demos
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes

ALL_TARGET=	qrash

post-patch:
	@${PERL} -pi -e "s=PREFIX=${PREFIX}=g" ${WRKSRC}/resource.cc
	@${PERL} -pi -e "s=/usr/X11=${PREFIX}=g" ${WRKSRC}/configure

.include <bsd.port.mk>
