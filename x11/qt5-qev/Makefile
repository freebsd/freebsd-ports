# $FreeBSD$

PORTNAME=	qev
DISTVERSION=	${QT5_VERSION}
PORTREVISION=	1
CATEGORIES=	x11
PKGNAMEPREFIX=	qt5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt QWidget events introspection tool

USE_QT=		core widgets
USES=		compiler:c++11-lang qmake qt-dist:5,tools

WRKSRC_SUBDIR=	src/${PORTNAME}

# qev is not connected to qttool's build system, so we cannot just run qmake qt-dist:5,tools
# and set {BUILD,INSTALL}_WRKSRC.
# Instead, we run qmake qt-dist:5,tools from src/${PORTNAME} but need to copy .qmake qt-dist:5,tools.conf to
# it for all required variables to be set (MODULE_VERSION etc).
post-patch:
	${CP} ${WRKSRC}/../../.qmake.conf ${WRKSRC}

.include <bsd.port.mk>
