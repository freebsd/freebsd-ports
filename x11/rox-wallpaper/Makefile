# $FreeBSD$

PORTNAME=	rox-wallpaper
PORTVERSION=	2.3
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/rox/Wallpaper/${PORTVERSION}
DISTNAME=	Wallpaper-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Wallpaper management tool for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:x11-fm/rox-filer \
		${PYTHON_PKGNAMEPREFIX}roxlib>=0:devel/py-roxlib

USES=		python:2.7 shebangfix
SHEBANG_FILES=	AppRun
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/Wallpaper

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/apps
	${CP} -r ${WRKSRC} ${STAGEDIR}${PREFIX}/apps/Wallpaper

.include <bsd.port.mk>
