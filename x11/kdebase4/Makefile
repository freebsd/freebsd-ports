# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase3.1
# Date created:				29 November 2002
# Whom:					kde@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	kdebase
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	searchclient:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		pci.2:${PORTSDIR}/devel/libpci

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus qt3support \
		designer network svg qtestlib \
		qmake_build moc_build rcc_build uic_build

USE_GETTEXT=	yes
USE_KDE4=	kdelibs runtime workspace kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DWITH_RAW1394:BOOL=OFF

MAN1=		kappfinder.1 \
		kbookmarkmerger.1 \
		kfind.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
.if ${OSVERSION} > 800090
	@${PATCH} ${PATCH_ARGS} < ${PATCHDIR}/extra-patch-libusb20
.endif
.if ${OSVERSION} >= 800100
	@${REINPLACE_CMD} -e 's,usb_revision.h,usbdi.h,g' \
		${WRKSRC}/../apps/kinfocenter/usbview/usbdevices.h
.endif

.include <bsd.port.post.mk>
