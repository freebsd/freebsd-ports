# New ports collection makefile for:	gnomelibs
# Version required:			1.0.6
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.38 1999/04/02 03:25:28 steve Exp $
#

DISTNAME=	gnome-libs-1.0.6
PKGNAME=	gnomelibs-1.0.6
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-libs

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gdk_imlib.3:${PORTSDIR}/graphics/imlib \
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
