# $FreeBSD$

PORTNAME=	xload
PORTVERSION=	1.1.3
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	System load average display for X

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_aarch64=		Fails to build: exec(xgettext) failed (No such file or directory)

XORG_CAT=	app
USE_XORG=	x11 xaw xmu xt

.include <bsd.port.mk>
