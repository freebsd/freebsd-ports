# New ports collection makefile for:   amaterus
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amaterus
PORTVERSION=	0.34.1
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.taiyaki.org/amaterus/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ window manager

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_X_PREFIX=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
