# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	sxhkd
PORTVERSION=	0.5.4
CATEGORIES=	x11

MAINTAINER=	antont@inbox.lv
COMMENT=	Simple X hotkey daemon

LIB_DEPENDS=	libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
GH_COMMIT=	eaf83e9

USES=		gmake

PLIST_FILES=	bin/sxhkd \
		man/man1/sxhkd.1.gz

.include <bsd.port.mk>
