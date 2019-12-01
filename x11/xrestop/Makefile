# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xrestop
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	x11

MAINTAINER=	bland@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor

USES=		gmake pkgconfig ncurses xorg xorg-cat:app
USE_XORG=	x11 xext xrender xt xres xorgproto
GNU_CONFIGURE=	yes
USE_GITLAB=	yes
GL_COMMIT=	5e3d606e9e055c2442e90285b6fe7ffdc2f721b8

CONFIGURE_ENV=	XLIBS="-L${LOCALBASE}/lib -lX11"
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/xrestop man/man1/xrestop.1.gz

.include <bsd.port.mk>
