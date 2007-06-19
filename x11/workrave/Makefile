# New ports collection makefile for:	workrave
# Date created:				15 Jul 2003
# Whom:					Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	workrave
PORTVERSION=	1.8.3
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	SF

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	A Gnome RSI prevention tool

.if !defined(WITHOUT_GNOME)
LIB_DEPENDS=	gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26
.else
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24
.endif
.if !defined(WITHOUT_NETWORK)
LIB_DEPENDS+=	gnet-2.0.0:${PORTSDIR}/net/gnet2
.endif

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gconf2 intltool
.if !defined(WITHOUT_GNOME)
USE_GNOME+=	gnomepanel
.endif
USE_GCC=	3.4+
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--enable-gconf
.if defined(WITHOUT_GNOME)
CONFIGURE_ARGS+=--disable-gnome
PLIST_SUB=	GNOME="@comment "
.else
PLIST_SUB=	GNOME=""
.endif
.if defined(WITHOUT_NETWORK)
CONFIGURE_ARGS+=--disable-distribution
.endif

.include <bsd.port.mk>
