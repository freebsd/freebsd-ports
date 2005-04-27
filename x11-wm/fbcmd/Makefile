# New ports collection makefile for:	fbcmd
# Date created:		2004-09-24
# Whom:			Roman Bogorodskiy <bogorodskiy@inbox.ru>
#
# $FreeBSD$
#

PORTNAME=	fbcmd
PORTVERSION=	0.5.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://darkshed.feuersenger.net/files/c_cpp/fbcmd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	A commandline utility for controlling fluxbox

RUN_DEPENDS=	fluxbox:${PORTSDIR}/x11-wm/fluxbox-devel

USE_BZIP2=	yes
USE_GMAKE=	yes
ALL_TARGET=	first
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
MAKE_ARGS=	CXX="${CXX}" CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/fbcmd

post-extract:
	@${REINPLACE_CMD} -e "s|/usr/X11R6|${X11BASE}|g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbcmd ${PREFIX}/bin

.include <bsd.port.mk>
