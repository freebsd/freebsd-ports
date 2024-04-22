PORTNAME=	xcompmgr
PORTVERSION=	1.1.8
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Sample X compositing manager
WWW=		https://www.freedesktop.org/Software/xapps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg xorg-cat:app
USE_XORG=	x11 xcomposite xext xfixes xdamage xrender

GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
