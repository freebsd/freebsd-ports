# New ports collection makefile for:	xlockmore
# Version required:     4.08.2
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.30 1998/03/16 10:04:04 tg Exp $
#

DISTNAME=       xlockmore-4.08.2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+= --enable-kerberos4
.endif
USE_X11=	yes
MAN1=		xlock.1

.if exists(${X11BASE}/lib/libMesaGL.a) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS+=	--with-mesagl
LIB_DEPENDS+=		GL\\.13:${PORTSDIR}/graphics/Mesa
.else
CONFIGURE_ARGS+=	--without-mesagl
.endif

.include <bsd.port.mk>
