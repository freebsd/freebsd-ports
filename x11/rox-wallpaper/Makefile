# Ports collection Makefile for:	rox-wallpaper
# Date created:				Jan 13 2003
# Whom:					olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=		rox-wallpaper
PORTVERSION=		1.9.2
PORTREVISION=	1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	rox
DISTNAME=		wallpaper-${PORTVERSION}
EXTRACT_SUFX=		.tgz

MAINTAINER=		olgeni@FreeBSD.org
COMMENT=		Wallpaper management tool for the ROX desktop

RUN_DEPENDS=		${LOCALBASE}/bin/rox:${PORTSDIR}/x11-fm/rox-filer \
			${LOCALBASE}/lib/ROX-Lib2/python/rox/__init__.py:${PORTSDIR}/devel/py-roxlib

USE_PYTHON=		yes

do-build:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/apps
	@${CP} -r ${WRKSRC}/Wallpaper ${PREFIX}/apps/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/apps/Wallpaper

.include <bsd.port.mk>
