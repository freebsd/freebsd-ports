# Created by: Florent Thoumie <flz@xbsd.org>
# $FreeBSD$

PORTNAME=	wmctrl
PORTVERSION=	1.07
PORTREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	http://sweb.cz/tripie/utils/wmctrl/dist/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Command line tool to interact with an EWMH/NetWM compatible X managers

LICENSE=	GPLv2

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_XORG=	x11 xmu xext xt
USE_GNOME=	glib20

PLIST_FILES=	bin/wmctrl man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
