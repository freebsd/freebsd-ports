# Created by: Anton Törnqvist <antont@inbox.lv>
# $FreeBSD$

PORTNAME=	sxhkd
PORTVERSION=	0.5.5
CATEGORIES=	x11

MAINTAINER=	antont@inbox.lv
COMMENT=	Simple X hotkey daemon

LIB_DEPENDS=	libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms

USE_GITHUB=	yes
GH_ACCOUNT=	baskerville
GH_COMMIT=	7e895ad

USES=		gmake

PLIST_FILES=	bin/sxhkd \
		man/man1/sxhkd.1.gz

.include <bsd.port.mk>
