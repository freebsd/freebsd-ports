# New ports collection makefile for:	libsynaptics
# Date created:				Sun Mar 19 21:20:25 CET 2006
# Whom:					Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libsynaptics
PORTVERSION=	0.14.6b
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://qsynaptics.sourceforge.net/ \
		http://www.hitnet.rwth-aachen.de/~brueffer/distfiles/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Library to access the Xorg/XFree86 Synaptics TouchPad Driver

USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_XORG=	x11
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's/%%PTHREAD_LIBS%%/${PTHREAD_LIBS}/g' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
