# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsynaptics
PORTVERSION=	0.14.6b
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://qsynaptics.sourceforge.net/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to access the Xorg/XFree86 Synaptics TouchPad Driver

USES=		libtool tar:bzip2
GNU_CONFIGURE=	yes
USE_XORG=	x11
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
