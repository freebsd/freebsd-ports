# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	fbcmd
PORTVERSION=	0.5.1
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	http://darkshed.net/files/c_cpp/fbcmd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Commandline utility for controlling fluxbox

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	fluxbox:x11-wm/fluxbox

USES=		gmake localbase:ldflags tar:bzip2
ALL_TARGET=	first
MAKE_ARGS=	CXX="${CXX}" CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" \
		CXXFLAGS="${CXXFLAGS}" LFLAGS="${LDFLAGS}"

USE_XORG=	x11 xmu
PLIST_FILES=	bin/fbcmd

post-patch:
	@${REINPLACE_CMD} 's|?=|=|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbcmd ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
