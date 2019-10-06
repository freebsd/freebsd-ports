# $FreeBSD$

PORTNAME=	wcm
DISTVERSION=	s20191003
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayfire Config Manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libwf-config.so:devel/wf-config

CONFLICTS_INSTALL=	wcmcommander # bin/wcm

USES=		compiler:c++11-lib meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtkmm30 libxml2
GH_ACCOUNT=	WayfireWM
GH_TAGNAME=	0251264
DATADIR=	${PREFIX}/share/wayfire
INSTALLS_ICONS=	yes

.include <bsd.port.mk>
