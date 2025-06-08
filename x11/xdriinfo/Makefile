PORTNAME=	xdriinfo
DISTVERSION=	1.0.7
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Query configuration information of DRI drivers
WWW=		https://gitlab.freedesktop.org/xorg/app/xdriinfo

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl tar:xz xorg xorg-cat:app
USE_GL=		gl
USE_XORG=	x11 xorgproto
PLIST_FILES=	bin/xdriinfo share/man/man1/xdriinfo.1.gz

.include <bsd.port.mk>
