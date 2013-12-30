# Created by: Markus Brueffer <markus@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libsynaptics
PORTVERSION=	0.14.6b
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://qsynaptics.sourceforge.net/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to access the Xorg/XFree86 Synaptics TouchPad Driver

USE_BZIP2=	yes
USE_LDCONFIG=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's/%%PTHREAD_LIBS%%/${PTHREAD_LIBS}/g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
