PORTNAME=	mkcomposecache
DISTVERSION=	1.2.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Program to create Compose cache files
WWW=		https://gitlab.freedesktop.org/xorg/app/mkcomposecache

LICENSE=	SUSE
LICENSE_NAME=	SUSE Products GmbH license
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xorgproto

PLIST_FILES=	sbin/mkcomposecache share/man/man8/mkcomposecache.8.gz

.include <bsd.port.mk>
