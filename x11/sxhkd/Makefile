# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	sxhkd
PORTVERSION=	0.5.7
CATEGORIES=	x11

MAINTAINER=	gor@clogic.com.ua
COMMENT=	Simple X hotkey daemon

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libxcb-keysyms.so:x11/xcb-util-keysyms

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville

USES=		gmake pkgconfig

PORTEXAMPLES=	*
PLIST_FILES=	bin/sxhkd \
		man/man1/sxhkd.1.gz

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.mk>
