# New ports collection makefile for:   lxsession-lite
# Date created:                2008/06/20
# Whom:                        chinsan
#
# $FreeBSD$
#

PORTNAME=	lxsession-lite
PORTVERSION=	0.3.6
PORTREVISION=	4
CATEGORIES=	x11-wm gnome
MASTER_SITES=	SF/lxde/LXSession%20%28session%20manager%29/LXSession%20Lite%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LXDE Lite Session Manager

LIB_DEPENDS=	hal.1:${PORTSDIR}/sysutils/hal

CONFLICTS=	lxsession-[0-9]*

USE_GNOME=	gtk20
USE_AUTOTOOLS=	automake:110:env
USE_GMAKE=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC}

DATADIR=	${PREFIX}/share/lxsession

MAN1=		lxsession.1 lxsession-logout.1

.if !defined(WITHOUT_NLS)
USE_GETTEXT=    yes
PLIST_SUB+=     NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=     NLS="@comment "
.endif

.include <bsd.port.mk>
