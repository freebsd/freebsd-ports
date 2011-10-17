# New ports collection Makefile for:	konsole
# Date created:				30 July 2011
# Whom:					Alberto Villa <avilla@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	konsole
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE terminal emulator

CONFLICTS=	kdebase-4.[0-6].*

USE_BZIP2=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	xml moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xrender
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
