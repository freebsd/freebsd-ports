# $FreeBSD$

PORTNAME=	redkite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.1
CATEGORIES=	x11-toolkits

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	GUI toolkit

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake compiler:c++14-lang gnome localbase:ldflags
USE_GITHUB=	yes
GH_ACCOUNT=	quamplex
USE_GNOME=	cairo

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=${PREFIX}/lib
CMAKE_OFF=	ENABLE_EXAMPLES

.include <bsd.port.mk>
