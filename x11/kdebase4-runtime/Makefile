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
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	xine.1:${PORTSDIR}/multimedia/libxine \
		slp.1:${PORTSDIR}/net/openslp \
		attica.0:${PORTSDIR}/x11-toolkits/attica \
		ssh.4:${PORTSDIR}/security/libssh
#explicitly depend on libssh to avoid interference with ssh.4 from compat7x
BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh

USE_KDE4=	kdelibs kdeprefix kdehier automoc4 #pimlibs
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus phonon \
		qmake_build moc_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kdesu.1

SUB_FILES=	nepomuk-env.sh

OPTIONS=	PULSEAUDIO "Enable playback via PulseAudio soundserver" off \
		VIRTUOSO "Install Virtuoso SQL server (required for Nepomuk)" off

# Explicitly disable alsa, see for details:
# http://mail.kde.org/pipermail/kde-freebsd/2010-March/008015.html
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.0:${PORTSDIR}/archivers/xz
.endif

.if defined(WITH_PULSEAUDIO)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

.if defined(WITH_VIRTUOSO)
RUN_DEPENDS+=	${LOCALBASE}/bin/virtuoso-t:${PORTSDIR}/databases/virtuoso
.endif

.if exists(${LOCALBASE}/lib/soprano/libsoprano_virtuosobackend.so)
CMAKE_ARGS+=	-DWITH_Nepomuk:BOOL=ON
MAN8=		nepomukserver.8 nepomukservicestub.8
PLIST_SUB+=	NEPOMUK=""
.else
CMAKE_ARGS+=	-DWITH_Nepomuk:BOOL=OFF
PLIST_SUB+=	NEPOMUK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/khelpcenter/infotree.cpp \
		${PATCH_WRKSRC}/kioslave/info/kde-info2html.conf \
		${PATCH_WRKSRC}/kioslave/man/kio_man.cpp \
		${PATCH_WRKSRC}/kioslave/man/man2html.cpp \
		${PATCH_WRKSRC}/cmake/modules/FindCLucene.cmake

post-install:
	${MKDIR} ${PREFIX}/env
	${INSTALL_SCRIPT} ${WRKDIR}/nepomuk-env.sh ${PREFIX}/env

.include <bsd.port.mk>
