# New ports collection makefile for:   gnomelibs
# Version required:    0.30.1
# Date created:        17 June 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.18 1998/12/14 03:27:52 asami Exp $
#

DISTNAME=	gnome-libs-0.30.1
PKGNAME=	gnomelibs-0.30.1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	gdk_imlib.1:${PORTSDIR}/graphics/imlib
LIB_DEPENDS+=	gtk11.1:${PORTSDIR}/x11-toolkits/gtk11
LIB_DEPENDS+=	tiff.4:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gif.3:${PORTSDIR}/graphics/giflib
LIB_DEPENDS+=	png.2:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	Xpm.4:${PORTSDIR}/graphics/xpm
LIB_DEPENDS+=	ORBit.0:${PORTSDIR}/devel/ORBit

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include \
		-I${X11BASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib -lxpg4"

pre-build:
	( cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h )

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
