# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina-i18n
PORTVERSION=	1.0.0
CATEGORIES=	x11

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina desktop environment localization files

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	lumina>=0:x11/lumina

USES=		tar:xz
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	trueos
GH_PROJECT=	lumina-i18n
GH_TAGNAME=	a96928d

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/lumina-desktop/i18n
	tar xvf ${WRKSRC}/dist/${PORTNAME}.txz -C ${STAGEDIR}${PREFIX}/share/lumina-desktop/i18n

.include <bsd.port.mk>
