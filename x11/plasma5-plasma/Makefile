# $FreeBSD$

PORTNAME=	plasma
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	x11 kde
PKGNAMEPREFIX=	plasma5-

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE5 plasma meta port

LICENSE=	LGPL20

USES=		kde:5 metaport qt:5
# remove:
#   * bluedevil as we do have bluez
#   * plasma-pa don't depend on plamsa-pa by default
#   * breeze-kde4 don't pull in qt4 bits
USE_KDE=	${_USE_PLASMA_ALL:Nplasma-pa:Nbreeze-kde4}

.include <bsd.port.mk>
