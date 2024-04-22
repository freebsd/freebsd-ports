PORTNAME=	xinput
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Very useful utility for configuring and testing XInput devices
WWW=		http://ftp.x.org/contrib/utilities/xinput.README

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	xorgproto x11 xi xext xrandr xinerama

PLIST_FILES=	bin/xinput share/man/man1/xinput.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

.include <bsd.port.mk>
