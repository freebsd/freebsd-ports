# New ports collection makefile for:   	flwm
# Date created:				12 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

PORTNAME=	flwm
PORTVERSION=	1.00
CATEGORIES=	x11-wm
MASTER_SITES=	http://flwm.sourceforge.net/ \
		http://www.cinenet.net/users/spitzak/flwm/ \
		ftp://ftp.sai.msu.su/pub/X11/win_man/
EXTRACT_SUFX=	.tgz

MAINTAINER=	demon@FreeBSD.org
COMMENT=	The Fast Light Window Manager

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

MAKE_ENV+=	PTHREAD_LIBS=${PTHREAD_LIBS}

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		flwm.1
PLIST_FILES=	bin/flwm

.include <bsd.port.mk>
