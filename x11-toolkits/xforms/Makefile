PORTNAME=	xforms
DISTVERSION=	1.2.4
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	x11-toolkits graphics
MASTER_SITES=	SAVANNAH

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Graphical user interface toolkit for X Window System
WWW=		http://xforms-toolkit.org/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libtiff.so:graphics/tiff

USES=		gl jpeg libtool localbase:ldflags xorg
USE_GL=		gl
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xpm

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

post-patch:
	${REINPLACE_CMD} 's|#define fl_draw_box|#define fl_drw_box|'	\
		${WRKSRC}/lib/include/Basic.h

.include <bsd.port.mk>
