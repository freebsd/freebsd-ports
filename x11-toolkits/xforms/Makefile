# Created by: gena
# $FreeBSD$

PORTNAME=	xforms
DISTVERSION=	1.2.4
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical user interface toolkit for X Window System

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		gl jpeg libtool xorg
USE_XORG=	xpm
USE_GL=		gl
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} 's|#define fl_draw_box|#define fl_drw_box|'	\
		${WRKSRC}/lib/include/Basic.h

.include <bsd.port.mk>
