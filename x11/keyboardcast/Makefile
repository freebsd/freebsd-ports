PORTNAME=	keyboardcast
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	7
CATEGORIES=	x11

MAINTAINER=	eimar.koort@gmail.com
COMMENT=	Broadcast keystrokes to multiple X windows for Gnome2
WWW=		https://launchpad.net/keyboardcast

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwnck-1.so:x11-toolkits/libwnck

USE_GITHUB=	yes
GH_ACCOUNT=	ekoort

USES=		gnome pkgconfig xorg
USE_XORG=	xmu x11
USE_GNOME=	libglade2 gtk20

.include <bsd.port.mk>
