# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-i18n
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-Release
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina desktop environment localization files

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	lumina>=0:x11/lumina

USES=		tar:xz
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	pcbsd

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/Lumina-DE/i18n
	tar xvf ${WRKSRC}/dist/${PORTNAME}.txz -C ${STAGEDIR}${PREFIX}/share/Lumina-DE/i18n

.include <bsd.port.mk>
