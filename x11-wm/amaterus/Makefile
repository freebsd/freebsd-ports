# New ports collection makefile for:   amaterus
# Date created:        26 January 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	amaterus
PORTVERSION=	0.34.1
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.taiyaki.org/amaterus/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ window manager

DEPRECATED=     Distfile is no more available
EXPIRATION_DATE=        2011-05-01

LIB_DEPENDS=	xml.5:${PORTSDIR}/textproc/libxml

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
