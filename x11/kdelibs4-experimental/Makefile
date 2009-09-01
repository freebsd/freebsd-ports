# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 4
# Date created:				19 January 2008
# Whom:					arved at FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs-experimental
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
PKGNAMESUFFIX?=	# empty
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Experimantal set of libraries needed by KDE programs

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus phonon \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
