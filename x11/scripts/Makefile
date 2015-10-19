# $FreeBSD$

PORTNAME=	scripts
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Various X related scripts

RUN_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh

XORG_CAT=	app
USE_XORG=	x11
USES=		shebangfix

post-patch:
	@${REINPLACE_CMD} -e 's|XCOMM!/bin/ksh|XCOMM!${ksh_CMD}|' ${WRKSRC}/xauth_switch_to_sun-des-1.cpp

.include <bsd.port.mk>
