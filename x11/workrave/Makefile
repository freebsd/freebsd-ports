# New ports collection makefile for:	Workrave
# Date created:			15 Jul 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	workrave
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kwm@rainbow-runner.nl
COMMENT=	A Gnome RSI prevention tool

LIB_DEPENDS=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2 \
		gnomeuimm-2.0:${PORTSDIR}/x11-toolkits/libgnomeuimm \
		gnet-2.0.0:${PORTSDIR}/net/gnet2
BUILD_DEPENDS=	intltool-extract:${PORTSDIR}/textproc/intltool

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel gconf2
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome/workrave \
		--enable-gconf \
		--enable-gnome \
		--enable-exercises

.include <bsd.port.mk>
