# Created by: jkh
# $FreeBSD$

PORTNAME=	emu
PORTVERSION=	1.31
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal emulator for the X Window System

BROKEN=		fails to build
DEPRECATED=	Broken, not staged
EXPIRATION_DATE=	2014-04-24

BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USES=		imake display
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

WRKSRC=		${WRKDIR}/emu

NO_STAGE=	yes

MAN1=		emu.1

pre-configure:
	cd ${WRKSRC}/client ; ${LN} -s ../doc/emu.man .

.include <bsd.port.mk>
