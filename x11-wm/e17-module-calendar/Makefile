# New ports collection makefile for:	e17-module-calendar
# Date created:		23 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	calendar
PORTVERSION=	23062006
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	e17-module-
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Nice calendar module for e17

BUILD_DEPENDS=	enlightenment:${PORTSDIR}/x11-wm/enlightenment-devel
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

PLIST_SUB+=	MODULE_ARCH=freebsd${OSREL}-${ARCH}

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
