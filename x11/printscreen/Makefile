# $FreeBSD$

PORTNAME=	printscreen
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Simple screenshot program for X11

LICENSE=	BSD

RUN_DEPENDS=	xwd:${PORTSDIR}/x11/xwd \
		xwdtopnm:${PORTSDIR}/graphics/netpbm

NO_WRKSUBDIR=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/printscreen

do-install:
	@${INSTALL_SCRIPT} ${FILESDIR}/printscreen.in ${STAGEDIR}${PREFIX}/bin/printscreen

.include <bsd.port.mk>
