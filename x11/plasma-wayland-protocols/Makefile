# $FreeBSD$

PORTNAME=	plasma-wayland-protocols
DISTVERSION=	1.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma Specific Protocols for Wayland

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build qmake_build

.include <bsd.port.mk>
