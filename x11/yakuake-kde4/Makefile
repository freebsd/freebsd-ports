# Created by: Shane Bell <decept0@gmail.com>
# $FreeBSD$

PORTNAME=	yakuake
PORTVERSION=	2.9.9
PORTREVISION=	6
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src
PKGNAMESUFFIX=	-kde4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drop-down terminal emulator for KDE

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake gettext shebangfix tar:xz
SHEBANG_FILES=	data/updaters/yakuake-${PORTVERSION}-startupnotification.pl
USE_KDE4=	automoc4 kdelibs
USE_QT4=	qmake_build moc_build rcc_build uic_build

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
