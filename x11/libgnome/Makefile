# New ports collection makefile for:	gnomelibs
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	gnomelibs
PORTVERSION= 	1.2.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/gnome-libs
DISTNAME=	gnome-libs-${PORTVERSION}

MAINTAINER=	ade@FreeBSD.org

LIB_DEPENDS=	gdk_imlib.5:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ORBit.2:${PORTSDIR}/devel/ORBit \
		esd.2:${PORTSDIR}/audio/esound

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config
GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libart_lgpl/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnome.1 gnome-config.1
MAN5=		gnome-mime.5

.include <bsd.port.mk>
