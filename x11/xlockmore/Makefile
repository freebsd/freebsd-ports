# New ports collection makefile for:	xlockmore
# Version required:     4.12
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.42 1998/10/01 02:17:49 jseger Exp $
#

DISTNAME=       xlockmore-4.12
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+= --enable-kerberos4
.endif
USE_X_PREFIX=	yes
MAN1=		xlock.1

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} > 300000
CONFIGURE_ARGS+= --with-libraries=/usr/lib/aout
.endif

WITH_MESAGL?=	yes
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesagl
LIB_DEPENDS+=		GL.14:${PORTSDIR}/graphics/Mesa3
.else
CONFIGURE_ARGS+=	--without-mesagl
.endif

.include <bsd.port.mk>
