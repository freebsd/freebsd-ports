# $FreeBSD$

PORTNAME=	x11extras
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	x11
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt platform-specific features for X11-based systems

USE_QT=		core gui
USES=		compiler:c++11-lang qmake qt-dist:5,x11extras perl5
USE_PERL5=	build
USE_LDCONFIG=	${PREFIX}/${QT_LIBDIR_REL}

.include <bsd.port.mk>
