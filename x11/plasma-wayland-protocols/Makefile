PORTNAME=	plasma-wayland-protocols
DISTVERSION=	1.19.0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Plasma Specific Protocols for Wayland
WWW=		https://github.com/kde/plasma-wayland-protocols

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base:build

NO_ARCH=	yes

.include <bsd.port.mk>
