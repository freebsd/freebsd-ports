# New ports collection makefile for:	gnomecore
# Version required:			0.99.5
# Date created:				17 March 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.15 1999/01/31 20:50:58 vanilla Exp $
#

DISTNAME=	gnome-core-0.99.5
PKGNAME=	gnomecore-0.99.5
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-core

MAINTAINER=	nacai@iname.com

RUN_DEPENDS=	${X11BASE}/share/gnome/sounds/duck.wav:${PORTSDIR}/audio/gnomeaudio
LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop \
		ghttp.0:${PORTSDIR}/www/libghttp

# implicit dependencies
# gettext, esound, gnomelibs

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	chown root.kmem ${PREFIX}/bin/cpumemusage_applet
	chown root.kmem ${PREFIX}/bin/diskusage_applet
	chown root.kmem ${PREFIX}/bin/multiload_applet
	chmod 2555 ${PREFIX}/bin/cpumemusage_applet
	chmod 2555 ${PREFIX}/bin/diskusage_applet
	chmod 2555 ${PREFIX}/bin/multiload_applet

.include <bsd.port.mk>
