PORTNAME=	sdorfehs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	x11-wm

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tiling window manager descended from ratpoison
WWW=		https://github.com/jcs/sdorfehs

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	jcs
USE_XORG=	x11 xft xrandr xres xtst

PLIST_FILES=	bin/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
