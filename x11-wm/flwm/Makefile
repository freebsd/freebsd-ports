# New ports collection makefile for:   	flwm
# Date created:				12 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	flwm
PORTVERSION=	1.00
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	gj
EXTRACT_SUFX=	.tgz

MAINTAINER=	gj@FreeBSD.org
COMMENT=	The Fast Light Window Manager

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

GNU_CONFIGURE=	yes
MAN1=		flwm.1
PLIST_FILES=	bin/flwm

.include <bsd.port.pre.mk>

# could be a problem if both versions of freetype are installed
.if exists(${LOCALBASE}/include/freetype1/freetype/freetype.h)
CONFIGURE_ARGS= --includedir="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype1"
.elif exists(${LOCALBASE}/include/freetype2/freetype/freetype.h)
CONFIGURE_ARGS= --includedir="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2"
.endif

.include <bsd.port.post.mk>
