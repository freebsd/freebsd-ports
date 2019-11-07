# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	xzoom
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	x11 accessibility
MASTER_SITES=	SUNSITE/libs/X

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Magnify, rotate, mirror the image on the X screen

USES=		imake tar:tgz xorg
USE_XORG=	x11 xext
PLIST_FILES=	bin/xzoom man/man1/xzoom.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xzoom ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xzoom.man ${STAGEDIR}${MAN1PREFIX}/man/man1/xzoom.1

.include <bsd.port.mk>
