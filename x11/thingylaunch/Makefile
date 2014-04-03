# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	thingylaunch
PORTVERSION=	1.1.6
CATEGORIES=	x11
MASTER_SITES=	http://gahr.ch/thingylaunch/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight tab-completing launcher for X

LICENSE=	MIT BSD2CLAUSE
LICENSE_COMB=	multi

USE_XORG=	x11 xproto
USES=		cmake:outsource

USE_GITHUB=	yes
GH_ACCOUNT=	gahr
GH_TAGNAME=	${PORTVERSION}
GH_COMMIT=	caa7e02

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
