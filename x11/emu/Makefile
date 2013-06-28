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

BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb
RUN_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USES=		imake display
USE_XORG=	ice sm x11 xaw xext xmu xpm xt

WRKSRC=		${WRKDIR}/emu

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 900007
BROKEN=		fails to build with new utmpx
.endif

MAN1=		emu.1

pre-configure:
	cd ${WRKSRC}/client ; ${LN} -s ../doc/emu.man .

.include <bsd.port.post.mk>
