# New ports collection makefile for:   gnomelibs
# Version required:    0.27
# Date created:        17 June 1998
# Whom:                Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.3 1998/09/15 11:13:38 asami Exp $
#

DISTNAME=	gnome-libs-0.27
PKGNAME=	gnomelibs-0.27
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/ \
		ftp://ftp.gnome.org/pub/GNOME/sources/

MAINTAINER=	Nakai@technologist.com

BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
LIB_DEPENDS=	gdk_imlib\\.1\\.7:${PORTSDIR}/graphics/imlib
LIB_DEPENDS+=	gtk11\\.1\\.:${PORTSDIR}/x11-toolkits/gtk11
LIB_DEPENDS+=	tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	gif\\.3\\.:${PORTSDIR}/graphics/giflib
LIB_DEPENDS+=	png\\.2\\.:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	Xpm.5:${PORTSDIR}/graphics/xpm

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lxpg4"

pre-build:
	( cd ${WRKSRC}/support; ${GMAKE} gnomesupport.h )

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
