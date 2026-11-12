PORTNAME=	fastcompmgr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	x11-wm

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Fast compositor for X11

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	tycho-kirchner
USE_XORG=	x11 xcomposite xdamage xfixes xorgproto xrender

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
