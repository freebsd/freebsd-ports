# New ports collection makefile for:	gnomelibs
# Version required:			0.99.4
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.29 1999/01/27 08:31:54 fenner Exp $
#

DISTNAME=	gnome-libs-0.99.4
PKGNAME=	gnomelibs-0.99.4
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gnome-libs

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gdk_imlib.2:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ORBit.1:${PORTSDIR}/devel/ORBit \
		esd.1:${PORTSDIR}/audio/esound

# implicit dependencies:
# gettext, gtk11-devel, tiff34, jpeg, giflib, png

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-gnome-hello \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
