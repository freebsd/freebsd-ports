# New ports collection makefile for:   gnomelibs
# Version required:    0.99.1
# Date created:        17 June 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.21 1999/01/04 08:43:06 vanilla Exp $
#

DISTNAME=	gnome-libs-0.99.1
PKGNAME=	gnomelibs-0.99.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	gdk_imlib.1:${PORTSDIR}/graphics/imlib \
		gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gif.3:${PORTSDIR}/graphics/giflib \
		png.2:${PORTSDIR}/graphics/png \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ORBit.1:${PORTSDIR}/devel/ORBit \
		esd.1:${PORTSDIR}/audio/esound

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-gnome-hello \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		GLIB_CONFIG="${LOCALBASE}/bin/glib11d-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

pre-build:
	( cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h )

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
