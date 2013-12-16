# $FreeBSD$

PORTNAME=	xrx
PORTVERSION=	1.0.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	RX helper program

XORG_CAT=	app
USE_XORG=	x11 xt xext xtrans xproxymngproto xau xaw ice
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool

post-patch:
	@${REINPLACE_CMD} -e 's|mozilla-plugin|disabled-libxul-plugin|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
