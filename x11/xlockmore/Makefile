# New ports collection makefile for:	xlockmore
# Date created:		9 November 1994
# Whom:			smace
#
# $FreeBSD$
#

PORTNAME=	xlockmore
PORTVERSION= 	4.16.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.tux.org/pub/tux/bagleyd/xlockmore/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	tg@FreeBSD.org

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --without-gl --without-motif --without-sx \
		--without-editres --without-dtsaver --without-rplay \
		--without-nas --without-gtk #--enable-customization
.if defined(MAKE_KERBEROS4)
CONFIGURE_ARGS+= --enable-kerberos4
.endif
USE_X_PREFIX=	yes
MAN1=		xlock.1

.include <bsd.port.pre.mk>

# .if ${OSVERSION} > 300000
# CONFIGURE_ARGS+= --with-libraries=/usr/lib/aout
# .endif

WITH_MESAGL?=	yes
.if ${WITH_MESAGL} == yes
CONFIGURE_ARGS+=	--with-mesagl
LIB_DEPENDS+=		GL.14:${PORTSDIR}/graphics/Mesa3
.else
CONFIGURE_ARGS+=	--without-mesagl
.endif

.include <bsd.port.post.mk>
