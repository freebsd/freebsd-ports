# $FreeBSD$

PORTNAME=	xkbcomp
PORTVERSION=	1.2.4
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Compile XKB keyboard description

LICENSE=	MIT

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/xorg-macros.oc:${PORTSDIR}/devel/xorg-macros
XORG_CAT=	app
USE_XORG=	x11 xkbfile
USE_GNOME=	gnomehack

PLIST_FILES=	bin/xkbcomp \
		libdata/pkgconfig/xkbcomp.pc

MAN1=		xkbcomp.1

.include <bsd.port.mk>
