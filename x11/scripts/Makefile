PORTNAME=	scripts
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Various X related scripts
WWW=		https://cgit.freedesktop.org/xorg/app/scripts

RUN_DEPENDS=	ksh:shells/pdksh

USES=		shebangfix xorg xorg-cat:app
USE_XORG=	x11

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

post-patch:
	@${REINPLACE_CMD} -e 's|XCOMM!/bin/ksh|XCOMM!${ksh_CMD}|' ${WRKSRC}/xauth_switch_to_sun-des-1.cpp

.include <bsd.port.mk>
