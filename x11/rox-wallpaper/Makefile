# Ports collection Makefile for:	rox-wallpaper
# Date created:				Jan 13 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rox-wallpaper
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF/rox/Wallpaper/${PORTVERSION}
DISTNAME=	wallpaper-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Wallpaper management tool for the ROX desktop

RUN_DEPENDS=	${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
		${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_BZIP2=	yes
USE_PYTHON=	yes

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Wallpaper ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Wallpaper

.include <bsd.port.mk>
