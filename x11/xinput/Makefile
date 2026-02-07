PORTNAME=	xinput
DISTVERSION=	1.6.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Very useful utility for configuring and testing XInput devices
WWW=		https://gitlab.freedesktop.org/xorg/app/xinput

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	xorgproto x11 xi xext xrandr xinerama

PLIST_FILES=	bin/xinput share/man/man1/xinput.1.gz

.include <bsd.port.mk>
