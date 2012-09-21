# $FreeBSD$

PORTNAME=	lxrandr
PORTVERSION=	0.1.2
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXRandR%20%28monitor%20config%20tool%29/LXRandR%20${PORTVERSION}

MAINTAINER=	ericturgeon@ghostbsd.org
COMMENT=	LXDE screen manager

USE_GNOME=	gtk20
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
USE_XORG=	xrandr
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

MAN1=		lxrandr.1

post-install:
	@-${LOCALBASE}/bin/update-desktop-database > /dev/null

.include <bsd.port.mk>
