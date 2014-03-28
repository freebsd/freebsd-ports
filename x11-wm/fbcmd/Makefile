# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	fbcmd
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://darkshed.net/files/c_cpp/fbcmd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A commandline utility for controlling fluxbox

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox

USES=		gmake tar:bzip2
ALL_TARGET=	first
CFLAGS+=	"-I${LOCALBASE}/include"

USE_XORG=	x11 xmu
PLIST_FILES=	bin/fbcmd

NO_STAGE=	yes
post-extract:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${LOCALBASE}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbcmd ${PREFIX}/bin

.include <bsd.port.mk>
