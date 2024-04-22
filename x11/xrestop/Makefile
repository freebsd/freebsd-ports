PORTNAME=	xrestop
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 server side resource usage statistics monitor
WWW=		https://www.freedesktop.org/wiki/Software/xrestop/

USES=		gmake pkgconfig ncurses xorg xorg-cat:app
USE_XORG=	x11 xext xrender xt xres xorgproto
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GITLAB=	yes
GL_TAGNAME=	5e3d606e9e055c2442e90285b6fe7ffdc2f721b8

CONFIGURE_ENV=	XLIBS="-L${LOCALBASE}/lib -lX11"
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/xrestop share/man/man1/xrestop.1.gz

.include <bsd.port.mk>
