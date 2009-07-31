# New ports collection makefile for:	xorg-edit
# Date created:		4 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-edit
PORTVERSION=	07.08.11
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GUI to edit xorg.conf

USE_WX=		2.6
USE_BZIP2=	yes
WX_UNICODE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
#BUILD_WRKSRC=	${WRKSRC}/sources
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CHMOD} -R a+rX,u+w ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|g;s|/usr/local|$${PREFIX}|g'\
		${BUILD_WRKSRC}/xorgedit/${MAKEFILE}
	@${REINPLACE_CMD} -e '/^CXX.*=/d' ${BUILD_WRKSRC}/libxorgedit/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
