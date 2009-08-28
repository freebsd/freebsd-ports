# New ports collection makefile for:   lxsession
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxsession
PORTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	x11-wm gnome
MASTER_SITES=	SF/lxde/LXSession%20%28deprecated%20old%20ver%29/LXSession%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Session Manager

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal
BUILD_DEPENDS=	docbook-to-man:${PORTSDIR}/textproc/docbook-to-man

CONFLICTS=	lxsession-lite-[0-9]*

USE_GNOME=	gtk20 intlhack libgnome

USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

MAN1=		lxsession.1 lxsession-logout.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
