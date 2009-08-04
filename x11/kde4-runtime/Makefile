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

LIB_DEPENDS+=	lzma.0:${PORTSDIR}/archivers/lzmautils-devel \
		xine.1:${PORTSDIR}/multimedia/libxine \
		slp.1:${PORTSDIR}/net/openslp

USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4 kdeexp
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib opengl dbus phonon \
		qmake_build moc_build rcc_build uic_build
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

MAN1=	kdesu.1
MAN8=	nepomukserver.8 nepomukservicestub.8

OPTIONS=	PULSEAUDIO	"Enable playback via PulseAudio soundserver" off

.include <bsd.port.pre.mk>

.if defined(WITH_PULSEAUDIO)
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=ON
LIB_DEPENDS+=	pulse.0:${PORTSDIR}/audio/pulseaudio
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/../khelpcenter/infotree.cpp \
		${WRKSRC}/../kioslave/info/kde-info2html.conf \
		${WRKSRC}/../kioslave/man/kio_man.cpp \
		${WRKSRC}/../kioslave/man/man2html.cpp

.include <bsd.port.post.mk>
