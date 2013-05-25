# $FreeBSD$

PORTNAME=	luit
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Locale and ISO 2022 support for Unicode terminals

XORG_CAT=	app
USE_XORG=	x11 fontenc

CONFIGURE_ARGS=	--datadir=${LOCALBASE}/lib

# Use openpty(), FreeBSD 7 has grantpt but not /dev/ptmx
CONFIGURE_ENV=	ac_cv_func_grantpt=no

PLIST_FILES=	bin/luit

MAN1=		luit.1

.include <bsd.port.mk>
