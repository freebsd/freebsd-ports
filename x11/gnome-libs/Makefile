# New ports collection makefile for:	gnomelibs
# Version required:			1.0.9
# Date created:				17 June 1998
# Whom:					Yukihiro Nakai <Nakai@technologist.com>
#
# $Id: Makefile,v 1.40 1999/05/09 17:13:15 steve Exp $
#

DISTNAME=	gnome-libs-1.0.9
PKGNAME=	gnomelibs-1.0.9
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-libs

MAINTAINER=	nacai@iname.com

LIB_DEPENDS=	gdk_imlib.4:${PORTSDIR}/graphics/imlib \
		Xpm.4:${PORTSDIR}/graphics/xpm \
		ORBit.2:${PORTSDIR}/devel/ORBit \
		esd.1:${PORTSDIR}/audio/esound

GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOLFILES=	configure libart_lgpl/configure
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--disable-gnome-hello \
		--disable-test-gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-I${LOCALBASE}/include/giflib" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gnome.1	

.include <bsd.port.mk>
