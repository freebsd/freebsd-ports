# New ports collection makefile for:   gnomecore
# Version required:    0.99.1
# Date created:        17 March 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.9 1999/01/06 12:19:42 obrien Exp $
#

DISTNAME=	gnome-core-0.99.1
PKGNAME=	gnomecore-0.99.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gnome.1:${PORTSDIR}/x11/gnomelibs \
		gtop.0:${PORTSDIR}/devel/libgtop \
		esd.1:${PORTSDIR}/audio/esound \
		ghttp.0:${PORTSDIR}/www/libghttp

BROKEN=	'gnome-core-0.99.2 is the currently available'

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--with-gnome=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		CXXFLAGS="${CFLAGS}" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${X11BASE}/bin/glib11d-config" \
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
