# New ports collection makefile for:	xlockmore
# Version required:     4.06.1
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.23 1997/10/10 09:24:38 tg Exp $
#

DISTNAME=       xlockmore-4.06.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gl --without-motif --without-sx --without-mesagl \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --enable-mouse-motion
USE_X11=	yes
MAN1=		xlock.1

.include <bsd.port.mk>
