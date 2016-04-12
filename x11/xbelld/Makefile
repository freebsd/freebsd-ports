# Created by: Nosov Artem <chip-set@mail.ru>
# $FreeBSD$

PORTNAME=	xbelld
PORTVERSION=	0.2b2
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://www.meowfishies.com/code/
DISTNAME=	${PORTNAME}-0.2beta2

MAINTAINER=	chip-set@mail.ru
COMMENT=	XBellD is a small daemon for replacing the standard X terminal bell

LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile

USES=		imake tar:tgz
USE_XORG=	ice sm xtrap xmu xt
USE_GNOME=	esound

# xbelld calls sqrt which requires -lm on some architectures
MAKE_ARGS=	EXTRA_LDOPTIONS="-lX11 -laudiofile -lm"

PLIST_FILES=	bin/xbelld \
		lib/X11/app-defaults/XBellD \
		man/man1/xbelld.1.gz
XFREE86_HTML_MAN=no

.include <bsd.port.mk>
