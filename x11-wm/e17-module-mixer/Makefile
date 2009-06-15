# New ports collection makefile for:	e17-module-mixer
# Date created:		30 September 2006
# Whom:			Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mixer
PORTVERSION=	20080223
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	An e17 module to adjust audio mixer settings

BUILD_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment
RUN_DEPENDS=	enlightenment-config:${PORTSDIR}/x11-wm/enlightenment

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnometarget pkgconfig
USE_EFL=	edje
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS= --disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
