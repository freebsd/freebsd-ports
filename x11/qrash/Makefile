# New ports collection makefile for:	qrash
# Date created:		Oct 27, 1999
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	qrash
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://qmg.org/files/demos/qmg/ \
		ftp://qmg.org/pub/demos/qmg/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/demos
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Animated musical demo for X11

GNU_CONFIGURE=	yes
ONLY_FOR_ARCHS=	i386
USE_GCC=	2.95
USE_GMAKE=	yes
USE_PERL5=	yes	# XXX
USE_X_PREFIX=	yes

ALL_TARGET=	qrash

post-patch:
	@${PERL} -pi -e "s=PREFIX=${PREFIX}=g" ${WRKSRC}/resource.cc
	@${PERL} -pi -e "s=/usr/X11=${PREFIX}=g" ${WRKSRC}/configure
	${FIND} ${WRKSRC} -type f -exec ${PERL} -pi -e \
		"s:<malloc.h>:<stdlib.h>:g" {} \;

.include <bsd.port.mk>
