# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-i18n
PORTVERSION=	1.0.0
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina desktop environment localization files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	lumina>=0:x11/lumina

NO_BUILD=	yes
NO_ARCH=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina-i18n
GH_TAGNAME=	a96928d

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/lumina-desktop/i18n
	${TAR} xvf ${WRKSRC}/dist/${PORTNAME}.txz -C ${STAGEDIR}${PREFIX}/share/lumina-desktop/i18n

.include <bsd.port.mk>
