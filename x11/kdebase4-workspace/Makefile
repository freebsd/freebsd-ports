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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	usb-0.1.8:${PORTSDIR}/devel/libusb \
		qimageblitz.4:${PORTSDIR}/x11/qimageblitz\
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
		xset:${PORTSDIR}/x11/xset

SUB_FILES=	kdm
USE_KDE4=	kdelibs kdeprefix kdehier automoc4
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	assistant corelib dbus designer gui_build moc network opengl rcc \
		script svg sql qt3support qtestlib uic3 xml porting webkit
USE_GETTEXT=	yes
USE_ICONV=	yes

CMAKE_ARGS+=	-DWITH_BlueZ:BOOL=Off

post-extract:
	${MKDIR} ${WRKSRC}

pre-configure:

.for item in effects/showfps.h scene.h workspace.h
	${REINPLACE_CMD} -e 's|<qdatetime.h>|<QDateTime>|'\
		${WRKSRC}/../kwin/${item}
.endfor
.for item in client.h compositingprefs.h
	${REINPLACE_CMD} -e 's|<qframe.h>|<QFrame>|'\
		${WRKSRC}/../kwin/${item}
.endfor
.for item in placement.cpp popupinfo.cpp tabbox.cpp
	${REINPLACE_CMD} -e 's|<qdrawutil.h>|<QtGui/qdrawutil.h>|'\
		-e 's|<qdesktopwidget.h>|<QDesktopWidget>|'\
		${WRKSRC}/../kwin/${item}
.endfor
	${REINPLACE_CMD} -e 's|<qsessionmanager.h>|<QSessionManager>|'\
		${WRKSRC}/../kwin/sm.cpp
.for item in effects/desktopgrid.h toplevel.h
	${REINPLACE_CMD} -e 's|<qobject.h>|<QObject>|'\
		${WRKSRC}/../kwin/${item}
.endfor
	${REINPLACE_CMD} -e 's|<qpainter.h>|<QPainter>|'\
		${WRKSRC}/../kwin/effects/presentwindows.cpp
	${REINPLACE_CMD} -e 's|<qcursor.h>|<QCursor>|'\
		-e 's|<qevent.h>|<QtEvents>|'\
		${WRKSRC}/../kwin/effects/test/test_input.cpp
	${REINPLACE_CMD} -e 's|<qhash.h>|<QHash>|'\
		${WRKSRC}/../kwin/effects/thumbnailaside.h
	${REINPLACE_CMD} -e 's|<qdir.h>|<QDir>|'\
		-e 's|<qfile.h>|<QFile>|'\
		${WRKSRC}/../kwin/effects/videorecord.cpp
.for item in kcmkwin/kwinoptions/windows.cpp clients/plastik/plastikclient.cpp\
		clients/plastik/plastikclient.cpp
	${REINPLACE_CMD} -e 's|<qdesktopwidget.h>|<QDesktopWidget>|'\
		${WRKSRC}/../kwin/${item}
.endfor
.for item in b2/b2client.cpp kwmtheme/kwmthemeclient.cpp\
		laptop/laptopclient.cpp modernsystem/modernsys.cpp\
		redmond/redmond.cpp
	${REINPLACE_CMD} -e 's|<qdrawutil.h>|<QtGui/qdrawutil.h>|'\
		${WRKSRC}/../kwin/clients/${item}
.endfor
	${REINPLACE_CMD} -e 's|<qbitmap.h>|<QBitmap>|'\
		-e 's|<qlabel.h>|<QLabel>|'\
		-e 's|<qlayout.h>|<QLayout>|'\
		-e 's|<qpainter.h>|<QPainter>|'\
		-e 's|<qtooltip.h>|<QToolTip>|'\
		${WRKSRC}/../kwin/clients/oxygen/oxygenclient.cpp
	${REINPLACE_CMD} -e 's|<qevent.h>|<QtEvents>|'\
		${WRKSRC}/../kwin/effects/desktopgrid.cpp

post-configure:
	${REINPLACE_CMD} -e 's|/\* #undef HAVE_XKB \*/|#define HAVE_XKB 1|'\
		${WRKSRC}/../build/config-X11.h

post-install:
	${CHGRP} kmem ${KDE4_PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${KDE4_PREFIX}/bin/ksysguardd
	@${LN} -sf ${KDE4_PREFIX}/bin/startkde ${KDE4_PREFIX}/bin/startkde4
	@${MV} ${KDE4_PREFIX}/bin/kdm ${KDE4_PREFIX}/bin/kdm-bin
	@${MV} ${KDE4_PREFIX}/lib/kde4/libexec/kdm_config ${KDE4_PREFIX}/lib/kde4/libexec/kdm-bin_config
	@${MV} ${KDE4_PREFIX}/lib/kde4/libexec/kdm_greet ${KDE4_PREFIX}/lib/kde4/libexec/kdm-bin_greet
	@${INSTALL_SCRIPT} ${WRKDIR}/kdm ${KDE4_PREFIX}/bin

.include <bsd.port.mk>
