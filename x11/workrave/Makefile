# New ports collection makefile for:   Workrave
# Date created:                        15 Jul 2003
# Whom:                                Koop Mast <einekoai@chello.nl>
# Date modified:              	13 Jul 2005
# Whom:                        		 Alex de Kruijff <freebsd@akruijff.dds.nl>
#
# $FreeBSD$
#

PORTNAME=	workrave
PORTVERSION=	1.8.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Gnome RSI prevention tool

LIB_DEPENDS=	gnomeuimm-2.6.1:${PORTSDIR}/x11-toolkits/libgnomeuimm26 \
		gnet-2.0.0:${PORTSDIR}/net/gnet2

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomepanel gconf2 intltool
USE_GCC=	3.4
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--datadir=${PREFIX}/share/gnome/workrave \
		--enable-gconf \
		--enable-gnome \
		--enable-exercises

.include <bsd.port.mk>
