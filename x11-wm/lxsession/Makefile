# New ports collection makefile for:   lxsession
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxsession
PORTVERSION=	0.4.5
CATEGORIES=	x11-wm
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20${PORTVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	LXDE Session Manager

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal
BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man

CONFLICTS=	lxsession-lite-[0-9]*

USE_GNOME=	gtk20 intlhack

USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lxsession.1 lxsession-logout.1

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
