# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	xcb-proto
PORTVERSION=	1.9
CATEGORIES=	x11 python
MASTER_SITES=	http://xcb.freedesktop.org/dist/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	The X protocol C-language Binding (XCB) protocol

BUILD_DEPENDS=	xmllint:${PORTSDIR}/textproc/libxml2

USE_BZIP2=	yes
USES=		pathfix
USE_PYTHON=	yes
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/xcb

.include <bsd.port.mk>
