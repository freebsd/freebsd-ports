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
MASTER_SITES=	http://taiyaki.org/amaterus/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GTK+ window manager

DEPRECATED=	Abandonware, upstream disappeared
EXPIRATION_DATE=	2012-10-20

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk12 libxml
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
