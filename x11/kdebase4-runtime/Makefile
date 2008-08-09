# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase-runtime
# Date created:				22 Januar 2008
# Whom:					kde@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kdebase-runtime
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb \
		xcb.1:${PORTSDIR}/x11/libxcb \
		xine.1:${PORTSDIR}/multimedia/libxine \
		xklavier.12:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl moc rcc uic dbus
USE_FAM=	yes
USE_GETTEXT=	yes

MAN1=	kdesu.1

post-extract:
	${MKDIR} ${WRKSRC}

.include <bsd.port.mk>
