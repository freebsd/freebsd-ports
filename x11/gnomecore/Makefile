# New ports collection makefile for:	gnomecore
# Version required:			1.0.3
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.19 1999/03/09 01:09:04 nectar Exp $
#

DISTNAME=	gnome-core-1.0.3
PKGNAME=	gnomecore-1.0.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-1.0/sources

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/startup.wav:${PORTSDIR}/audio/gnomeaudio
LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop \
		ghttp.1:${PORTSDIR}/www/libghttp

# implicit dependencies
# gettext, esound, gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
