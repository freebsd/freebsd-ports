# New ports collection makefile for:	xlockmore
# Version required:     4.11
# Date created:		9 November 1994
# Whom:			smace
#
# $Id: Makefile,v 1.36 1998/07/21 07:09:04 tg Exp $
#

DISTNAME=       xlockmore-4.11
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB}
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
USE_X_PREFIX=	yes
MAN1=		xlock.1

OSVERSION!=     sysctl -n kern.osreldate
.if ${OSVERSION} > 300000
CONFIGURE_ARGS+= --with-libraries=/usr/lib/aout
.endif

#
# MesaGL has a security hole. Don't use it in setuid binaries.
# Override this with WITH_MESAGL=yes in your environment.
#
WITH_MESAGL?=	no
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesagl
LIB_DEPENDS+=		GL\\.13:${PORTSDIR}/graphics/Mesa2
.else
CONFIGURE_ARGS+=	--without-mesagl
.endif

.include <bsd.port.mk>
