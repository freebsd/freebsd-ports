# New ports collection makefile for:	xcb-proto
# Date Created:				2006-08-23
# Whom:					Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xcb-proto
PORTVERSION=	1.0
CATEGORIES=	x11
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	wahjava@gmail.com
COMMENT=	The X protocol C-language Binding (XCB) protocol

BUILD_DEPENDS=	xmllint:${PORTSDIR}/textproc/libxml2

PREFIX?=	${X11BASE}
USE_BZIP2=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
