PORTNAME=	xrestop
DISTVERSION=	0.6
CATEGORIES=	x11

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	X11 server side resource usage statistics monitor
WWW=		https://www.freedesktop.org/wiki/Software/xrestop/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses tar:xz xorg xorg-cat:app
USE_XORG=	x11 xext xres xorgproto

PLIST_FILES=	bin/xrestop share/man/man1/xrestop.1.gz

.include <bsd.port.mk>
