# New ports collection makefile for:	xlockmore
# Version required:     4.04
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.20 1997/07/30 08:02:42 tg Exp $
#

DISTNAME=       xlockmore-4.04
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --without-gl --without-motif --without-sx --without-mesagl \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
USE_X11=	yes
MAN1=		xlock.1

do-install:
	@(cd ${WRKSRC}/modes; make install)
	@chown root:bin ${PREFIX}/bin/xlock
	@chmod 4751 ${PREFIX}/bin/xlock

.include <bsd.port.mk>
