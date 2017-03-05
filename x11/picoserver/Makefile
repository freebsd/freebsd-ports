# Created by: Kris Moore <kris@ixsystems.com>
# $FreeBSD$

PORTNAME=	picoserver
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://web.trueos.org/picodist/ \
		https://www.trueos.org/picodist/

MAINTAINER=	kris@ixsystems.com
COMMENT=	Server for hosting Pico clients

ONLY_FOR_ARCHS=	amd64

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/pico-server

NO_BUILD=	yes
USES=		tar:xz
USE_OPENRC_SUBR=	picoserver

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pico-server ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
