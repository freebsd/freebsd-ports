# $FreeBSD$

PORTNAME=	wayland-logout
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Simple logout on Wayland

LICENSE=	MIT

USE_GITHUB=	yes
GH_ACCOUNT=	soreau
NO_ARCH=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
