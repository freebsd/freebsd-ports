# New ports collection makefile for:	gnomelibs
# Version required:			1.0.1
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.33 1999/03/09 01:09:05 nectar Exp $
#

DISTNAME=	gnome-libs-1.0.3
PKGNAME=	gnomelibs-1.0.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-1.0/sources

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gdk_imlib.2:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ORBit.1:${PORTSDIR}/devel/ORBit \
		esd.1:${PORTSDIR}/audio/esound

# implicit dependencies:
# gettext, gtk12, tiff34, jpeg, giflib, png

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-gnome-hello \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include \
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${X11BASE}/bin/gtk12-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
