# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xrestop
PORTVERSION=	0.4
PORTREVISION=	5
CATEGORIES=	x11
MASTER_SITES=	http://projects.o-hand.com/sources/${PORTNAME}/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor

BROKEN=		unfetchable

USES=		gmake pkgconfig ncurses xorg
USE_XORG=	x11 xext xrender xt xres xorgproto
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	XLIBS="-L${LOCALBASE}/lib -lX11"
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/xrestop man/man1/xrestop.1.gz

.include <bsd.port.mk>
