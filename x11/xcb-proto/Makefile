# New ports collection makefile for:	xcb-proto
# Date Created:				2006-08-23
# Whom:					Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	xcb-proto
PORTVERSION=	1.7.1
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/dist/ \
		http://distfiles.pirateparty.in/%SUBDIR%/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ashish

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

BUILD_DEPENDS=	xmllint:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
USES=	pathfix
USE_PYTHON=	2.5+
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
