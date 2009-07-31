# New ports collection makefile for:	libzvt
# Date created:				12 April 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libzvt
PORTVERSION=	2.0.1
PORTREVISION=	18
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for Zed's Virtual Terminal

USE_BZIP2=	yes
USE_XORG=	x11
USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:15
USE_GNOME=	gnomeprefix gnomehack gtk20 libartlgpl2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG[[:alpha:]]*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
