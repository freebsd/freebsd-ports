# New ports collection makefile for:	gnomecore
# Version required:			1.0.9
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	gnome-core-1.0.9
PKGNAME=	gnomecore-1.0.9
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-core

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/startup.wav:${PORTSDIR}/audio/gnomeaudio
LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop \
		gnomeprint.1:${PORTSDIR}/print/gnomeprint \
		ghttp.1:${PORTSDIR}/www/libghttp

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
