# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase-workspace
# Date created:				22 Januar 2008
# Whom:					kde@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kdebase-workspace
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz\
		dbus-1.3:${PORTSDIR}/devel/dbus \
		hal.1:${PORTSDIR}/sysutils/hal \
		xklavier.12:${PORTSDIR}/x11/libxklavier
RUN_DEPENDS=	${KDE4_PREFIX}/env/xdg-env.sh:${PORTSDIR}/misc/kde4-xdg-env \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xprop:${PORTSDIR}/x11/xprop \
		xsetroot:${PORTSDIR}/x11/xsetroot \
		xmessage:${PORTSDIR}/x11/xmessage \
		xrdb:${PORTSDIR}/x11/xrdb \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		xset:${PORTSDIR}/x11/xset \
		setxkbmap:${PORTSDIR}/x11/setxkbmap

SUB_FILES=	kdm
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	assistant corelib dbus designer gui network opengl  \
		script svg sql qt3support qtestlib xml webkit \
		qmake_build moc_build rcc_build uic_build \
		porting_build uic3_build
USE_GETTEXT=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DWITH_BlueZ:BOOL=OFF \
		-DWITH_Sensors:BOOL=OFF \
		-DWITH_NetworkManager:BOOL=OFF \
		-DWITH_Xmms:BOOL=OFF \
		-DWITH_Googlegadgets:BOOL=OFF \
		-DWITH_QEdje:BOOL=OFF \
		-DWITH_PyKDE4:BOOL=OFF
#PyKDE4, Xmms and Googlegadgets could be enabled,
#QEdje has not been ported yet.

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

post-extract:
	${MKDIR} ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's|<qhash.h>|<QHash>|'\
		${WRKSRC}/../kwin/effects/thumbnailaside.h
.for item in b2/b2client.cpp kwmtheme/kwmthemeclient.cpp\
		laptop/laptopclient.cpp modernsystem/modernsys.cpp\
		redmond/redmond.cpp
	${REINPLACE_CMD} -e 's|<qdrawutil.h>|<QtGui/qdrawutil.h>|'\
		${WRKSRC}/../kwin/clients/${item}
.endfor

post-install:
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	@${LN} -sf ${PREFIX}/bin/startkde ${PREFIX}/bin/startkde4
	@${MV} ${PREFIX}/bin/kdm ${PREFIX}/bin/kdm-bin
	@${MV} ${PREFIX}/lib/kde4/libexec/kdm_config ${PREFIX}/lib/kde4/libexec/kdm-bin_config
	@${MV} ${PREFIX}/lib/kde4/libexec/kdm_greet ${PREFIX}/lib/kde4/libexec/kdm-bin_greet
	@${INSTALL_SCRIPT} ${WRKDIR}/kdm ${PREFIX}/bin

.include <bsd.port.post.mk>
