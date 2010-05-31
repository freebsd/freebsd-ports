# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	searchclient:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support \
		designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build

USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DWITH_RAW1394:BOOL=OFF \
		-DWITH_PCIUTILS:BOOL=OFF

OPTIONS=	WEBKIT	"KWebKit support in Konqueror KTTS plugin" off

MAN1=		kappfinder.1 \
		kbookmarkmerger.1 \
		kfind.1

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

.ifdef(WITH_WEBKIT)
LIB_DEPENDS+=	kwebkit.1:${PORTSDIR}/www/kwebkitpart
CMAKE_ARGS+=	-DWITH_KWebKitPart:BOOL=ON
PLIST_SUB+=	WEBKIT=""
.else
CMAKE_ARGS+=	-DWITH_KWebKitPart:BOOL=OFF
PLIST_SUB+=	WEBKIT="@comment "
.endif

.include <bsd.port.mk>
