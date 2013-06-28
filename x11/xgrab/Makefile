# Created by: jmz
# $FreeBSD$

PORTNAME=	xgrab
PORTVERSION=	2.41
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB
MASTER_SITE_SUBDIR=	applications
DISTNAME=	${PORTNAME}sc.2_41
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 image grabber

BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb

USES=		display:build imake
USE_XORG=	x11

MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
# "make depend" blows up
XMKMF=		xmkmf
CFLAGS+=	-Wno-error=return-type

MAN1=		xgrab.1 xgrabsc.1

post-patch:
	@${REINPLACE_CMD} 's,\*envp,\*\*envp,g' ${WRKSRC}/xgrabxaw.c

.include <bsd.port.mk>
