# New ports collection makefile for:	xorg-edit
# Date created:		4 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xorg-edit
PORTVERSION=	06.10.12
CATEGORIES=	x11
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${PORTVERSION}-src

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	GUI to edit xorg.conf

USE_WX=		2.6+
WX_UNICODE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
BUILD_WRKSRC=	${WRKSRC}/sources
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${CHMOD} 644 ${BUILD_WRKSRC}/*

post-patch:
	@${REINPLACE_CMD} -e 's/wx-config/wxgtk2u-2.6-config/g' ${BUILD_WRKSRC}/${MAKEFILE}

do-install:
	@${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME} ${PREFIX}/bin/

.include <bsd.port.mk>
