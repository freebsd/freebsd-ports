# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kde-baseapps
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	searchclient.0:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		tidy-0.99.0:${PORTSDIR}/www/tidy-lib

CONFLICTS=	kdebase-4.[0-6].* konq-plugins-4.[0-6].*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui qt3support script \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xt
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"

MAN1=		kbookmarkmerger.1 \
		kfind.1

OPTIONS=	KONSOLE "Install Konsole terminal emulator" on \
		KWRITE "Install KWrite text editor" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_KONSOLE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/konsole:${PORTSDIR}/x11/konsole
.endif

.ifndef(WITHOUT_KWRITE)
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kwrite:${PORTSDIR}/editors/kate
.endif

.include <bsd.port.mk>
