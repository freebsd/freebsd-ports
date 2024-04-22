PORTNAME=	xmh
PORTVERSION=	1.0.5
CATEGORIES=	x11 mail

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Send and read mail with an X interface to MH

RUN_DEPENDS+=	repl:mail/nmh

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xaw xmu xt xbitmaps

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

.include <bsd.port.mk>
