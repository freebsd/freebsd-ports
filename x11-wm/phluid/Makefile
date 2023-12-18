PORTNAME=	phluid
PORTVERSION=	0.0.3
PORTREVISION=	13
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-src/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager that emphasizes efficiency, speed, and beauty
WWW=		https://sourceforge.net/projects/phluid/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Last upstream release was in 2000
EXPIRATION_DATE=	2024-01-18

LIB_DEPENDS=	libImlib2.so:graphics/imlib2

USES=		gmake localbase:ldflags xorg
USE_XORG=x11

GNU_CONFIGURE=	yes

LDFLAGS+=	-lm -lX11

.include <bsd.port.mk>
