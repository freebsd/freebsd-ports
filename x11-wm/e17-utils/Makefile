# New ports collection makefile for:	e17-utils
# Date created:		2006-07-16
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	utils
PORTVERSION=	20080223
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-
DISTNAME=	e_${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Various supplementary utilities for e17 window manager

DATADIR=	${PREFIX}/share/e_utils

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	imlib2 engrave ecore
USE_EFL_ECORE=	evas file config

OPTIONS=	SETROOT		"Build e17setroot"	on \
		ENTANGLE	"Build entangle"	on \
		EXIGE		"Build exige"		on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_SETROOT) && defined(WITHOUT_ENTANGLE) && \
	defined(WITHOUT_EXIGE)
IGNORE=		select at least one utility to install
.endif

.if !defined(WITHOUT_SETROOT)
BUILD_DEPENDS+=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS+=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
PLIST_SUB+=	SETROOT=""
.else
PLIST_SUB+=	SETROOT="@comment "
.endif

.if !defined(WITHOUT_ENTANGLE)
BUILD_DEPENDS+=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS+=	enlightenment:${PORTSDIR}/x11-wm/enlightenment
USE_EFL+=	edje eet
USE_EFL_ESMART+=	container text_entry
PLIST_SUB+=	ENTANGLE=""
.else
PLIST_SUB+=	ENTANGLE="@comment "
.endif

.if !defined(WITHOUT_EXIGE)
USE_EFL+=	edje eet
USE_EFL_ESMART+=	container text_entry
PLIST_SUB+=	EXIGE=""
.else
PLIST_SUB+=	EXIGE="@comment "
.endif

.include <bsd.port.post.mk>
