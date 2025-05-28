PORTNAME=	xcompmgr
DISTVERSION=	1.1.10
CATEGORIES=	x11-wm

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Sample X compositing manager
WWW=		https://www.freedesktop.org/Software/xapps

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:xz xorg xorg-cat:app
USE_XORG=	x11 xcomposite xdamage xext xfixes xorgproto xrender

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
