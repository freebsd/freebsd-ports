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
		polkit-qt-core.0:${PORTSDIR}/sysutils/policykit-qt \
		xklavier.12:${PORTSDIR}/x11/libxklavier \
		gps.19:${PORTSDIR}/astro/gpsd
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
USE_RC_SUBR=	kdm4
USE_KDE4=	kdelibs pimlibs kdeprefix kdehier automoc4 oxygen
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_QT_VER=	4
QT_COMPONENTS=	assistant corelib dbus designer gui network opengl  \
		script svg sql qt3support qtestlib xml webkit \
		qmake_build moc_build rcc_build uic_build \
		porting_build uic3_build phonon
USE_GETTEXT=	yes
USE_ICONV=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		plasmaengineexplorer.1

CONFLICTS=	kde4-windeco-aurorae-*

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

OPTIONS=	PLASMA_PYTHON "Support for plasmoids written in Python" off \
		PLASMA_RUBY "Support for plasmoids written in Ruby" off

.include <bsd.port.options.mk>

.if defined(WITH_PLASMA_PYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:${PORTSDIR}/x11/plasma-scriptengine-python
.endif

.if defined(WITH_PLASMA_RUBY)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:${PORTSDIR}/x11/plasma-scriptengine-ruby
.endif

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
.endif

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/startkde.cmake \
		${PATCH_WRKSRC}/kcontrol/kfontinst/lib/KfiConstants.h \
		${PATCH_WRKSRC}/kcontrol/kfontinst/kio/KioFonts.cpp \
		${PATCH_WRKSRC}/kcontrol/kxkb/x11helper.cpp \
		${PATCH_WRKSRC}/kdm/kfrontend/genkdmconf.c
	${CP} ${FILESDIR}/uptime.* ${WRKSRC}/ksysguard/ksysguardd/FreeBSD/

pre-configure:
	${REINPLACE_CMD} -e 's|sys/ptrace.h|signal.h|' \
		${PATCH_WRKSRC}/libs/ksysguard/processui/CMakeLists.txt
	${REINPLACE_CMD} -e 's|<qhash.h>|<QHash>|' \
		${PATCH_WRKSRC}/kwin/effects/thumbnailaside/thumbnailaside.h
.for item in b2/b2client.cpp kwmtheme/kwmthemeclient.cpp \
		laptop/laptopclient.cpp modernsystem/modernsys.cpp \
		redmond/redmond.cpp
	${REINPLACE_CMD} -e 's|<qdrawutil.h>|<QtGui/qdrawutil.h>|' \
		${PATCH_WRKSRC}/kwin/clients/${item}
.endfor

post-install:
	${CHGRP} kmem ${PREFIX}/bin/ksysguardd && \
		${CHMOD} g+s ${PREFIX}/bin/ksysguardd
	@${LN} -sf ${PREFIX}/bin/startkde ${PREFIX}/bin/startkde4
	@${MV} ${PREFIX}/bin/kdm ${PREFIX}/bin/kdm-bin
	@${MV} ${PREFIX}/lib/kde4/libexec/kdm_config ${PREFIX}/lib/kde4/libexec/kdm-bin_config
	@${MV} ${PREFIX}/lib/kde4/libexec/kdm_greet ${PREFIX}/lib/kde4/libexec/kdm-bin_greet
	@${INSTALL_SCRIPT} ${WRKDIR}/kdm ${PREFIX}/bin

.include <bsd.port.mk>
