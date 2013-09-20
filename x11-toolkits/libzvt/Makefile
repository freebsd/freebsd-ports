# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libzvt
PORTVERSION=	2.0.1
PORTREVISION=	21
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library components for Zed's Virtual Terminal

USE_BZIP2=	yes
USE_XORG=	x11
USES=		bison pathfix gmake pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gtk20 libartlgpl2
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

NO_STAGE=	yes
post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -E -e \
	    	's|-DG[[:alpha:]]*_DISABLE_DEPRECATED||g'

.include <bsd.port.mk>
