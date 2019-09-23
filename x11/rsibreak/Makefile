# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rsibreak
DISTVERSION=	0.12.11
PORTREVISION=	0
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION:R}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE RSI prevention tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs config configwidgets coreaddons crash dbusaddons doctools ecm \
		iconthemes i18n idletime notifications notifyconfig \
		sonnet textwidgets xmlgui widgetsaddons windowsystem
USE_QT=		core dbus gui widgets xml buildtools_build qmake_build

.include <bsd.port.mk>
