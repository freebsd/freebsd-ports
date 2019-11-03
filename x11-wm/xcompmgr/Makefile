# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xcompmgr
PORTVERSION=	1.1.8
CATEGORIES=	x11-wm

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Sample X compositing manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 xcomposite xext xfixes xdamage xrender

PLIST_FILES=	bin/${PORTNAME} man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
