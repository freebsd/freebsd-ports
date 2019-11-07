# Created by: jmz
# $FreeBSD$

PORTNAME=	xgrab
PORTVERSION=	2.41
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/applications
DISTNAME=	${PORTNAME}sc.2_41

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 image grabber

BUILD_DEPENDS=	xrdb:x11/xrdb

BROKEN_armv6=		fails to install: xrdb: Socket is not connected: Can't open display ':0'
BROKEN_armv7=		fails to install: xrdb: Socket is not connected: Can't open display ':0'

USES=		display:build imake:notall tar:Z xorg
USE_XORG=	x11 xaw

MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  -f
CFLAGS+=	-Wno-error=return-type
post-patch:
	@${REINPLACE_CMD} 's,\*envp,\*\*envp,g' ${WRKSRC}/xgrabxaw.c

.include <bsd.port.mk>
