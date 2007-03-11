# New ports collection makefile for:	e17-module-uptime
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	screenshot
PORTVERSION=	20070223
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module which allows users to take screenshots

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment-devel

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje

OPTIONS=	IMAGIC "Use ImageMagick" on \
		SCROT "Use Scrot" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IMAGIC)
BUILD_DEPENDS+=	import:${PORTSDIR}/graphics/ImageMagick
RUN_DEPENDS+=	import:${PORTSDIR}/graphics/ImageMagick
.endif

.if defined(WITH_SCROT)
BUILD_DEPENDS+=	scrot:${PORTSDIR}/graphics/scrot
RUN_DEPENDS+=	scrot:${PORTSDIR}/graphics/scrot
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include "../../x11-wm/enlightenment-devel/bsd.efl.mk"
.include <bsd.port.post.mk>
