# New ports collection makefile for:	enity
# Date created:		2006-08-14
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	enity
PORTVERSION=	20080223
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Create Etk dialogs using scripts

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_EFL=	etk
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/enity

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_bin_enity.c
.endif

.include <bsd.port.post.mk>
