# New ports collection makefile for:   	flwm
# Version required:			0.24
# Date created:				12 February 1999
# Whom:                			Dima Sivachenko <dima@chg.ru>
#
# $FreeBSD$
#

DISTNAME=	flwm-0.24
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.cinenet.net/users/spitzak/flwm/ \
		ftp://ftp.sai.msu.su/pub/X11/win_man/
EXTRACT_SUFX=	.tgz

MAINTAINER=	dima@chg.ru

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
MAN1=		flwm.1

.include <bsd.port.mk>
