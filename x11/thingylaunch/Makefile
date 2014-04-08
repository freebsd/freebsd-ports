# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thingylaunch
PORTVERSION=	1.2.0
CATEGORIES=	x11
MASTER_SITES=	http://gahr.ch/thingylaunch/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight tab-completing launcher for X

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi

USE_XORG=	x11 xproto
USE_CXXSTD=	c++11
USES=		cmake:outsource compiler:c++11-lib

CXXFLAGS+=	-std=c++11

USE_GITHUB=	yes
GH_ACCOUNT=	gahr
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	48688bc

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
