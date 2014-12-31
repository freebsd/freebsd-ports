# $FreeBSD$

PORTNAME=	slop
PORTVERSION=	4.1.15
CATEGORIES=	x11

MAINTAINER=	neel@neelc.org
COMMENT=	Make a screen selection and print the selection coordinates to stdout

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	naelstrof
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	cbc1856

USES=		cmake
USE_XORG=	x11 xext
PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/slop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
