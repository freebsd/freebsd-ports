# $FreeBSD$

PORTNAME=	euclid-wm
PORTVERSION=	0.4.3
CATEGORIES=	x11-wm
#MASTER_SITES=	http://euclid-wm.googlecode.com/files/
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	anastmag@gmail.com
COMMENT=	Minimalist, tiling window manager for X11

LICENSE=	BSD3CLAUSE

BROKEN=		Unfetchable (google code has gone away)

OPTIONS_DEFINE=	XINERAMA
XINERAMA_DESC=	X11 Xinerama extention support
OPTIONS_DEFAULT=XINERAMA

XINERAMA_ALL_TARGET=	euclid-wm
XINERAMA_USE=	XORG=xinerama

USES=	gmake
USE_XORG=	x11

PLIST_FILES=	bin/euclid-wm \
		bin/start-euclid \
		man/man1/euclid-wm.1.gz \
		share/euclid-wm/euclid-wm.conf \
		share/euclid-wm/euclidrc \
		share/euclid-wm/VERSION \
		share/xsessions/euclid.desktop

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/euclid-wm

.include <bsd.port.mk>
