# $FreeBSD$

PORTNAME=	cwm
PORTVERSION=	5.5
CATEGORIES=	x11-wm
MASTER_SITES=	http://chneukirchen.org/releases/ \
		http://github.com/chneukirchen/${PORTNAME}/archive/v${PORTVERSION}.tar.gz?dummy=/

MAINTAINER=	braakvaak@aol.com
COMMENT=	Minimalistic window manager for X11 based on evilwm

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		pkgconfig:build
USE_XORG=	x11 xft xinerama xrandr

PLIST_FILES=	bin/cwm \
		man/man1/cwm.1.gz \
		man/man5/cwmrc.5.gz

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cwm ${STAGEDIR}${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cwm.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cwmrc.5 ${STAGEDIR}${MAN5PREFIX}/man/man5

.include <bsd.port.mk>
