# -*-mode: makefile-*-
# New ports collection makefile for:	kdebase-workspace
# Date created:				22 Januar 2008
# Whom:					kde@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE_kde} \
		${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~avilla/distfiles/
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src/:kde \
			avilla/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kde \
		stripes-freebsd-1.0${EXTRACT_SUFX}
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	qimageblitz.4:${PORTSDIR}/x11/qimageblitz \
		dbus-1.3:${PORTSDIR}/devel/dbus \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit \
		pci.3:${PORTSDIR}/devel/libpci \
		hal.1:${PORTSDIR}/sysutils/hal \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		prison.0:${PORTSDIR}/graphics/prison \
		searchclient.0:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		boost_thread.4:${PORTSDIR}/devel/boost-libs \
		dbusmenu-qt.2:${PORTSDIR}/devel/libdbusmenu-qt \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		ttf.4:${PORTSDIR}/print/freetype \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

BUILD_DEPENDS=	${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies

RUN_DEPENDS=	${KDE4_PREFIX}/env/xdg-env.sh:${PORTSDIR}/misc/kde4-xdg-env \
		${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xprop:${PORTSDIR}/x11/xprop \
		xsetroot:${PORTSDIR}/x11/xsetroot \
		xmessage:${PORTSDIR}/x11/xmessage \
		xrdb:${PORTSDIR}/x11/xrdb \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		xset:${PORTSDIR}/x11/xset \
		setxkbmap:${PORTSDIR}/x11/setxkbmap \
		${KDE4_PREFIX}/bin/ksysguardd:${PORTSDIR}/sysutils/ksysguardd \
		${KDE4_PREFIX}/lib/kde4/libexec/polkit-kde-authentication-agent-1:${PORTSDIR}/sysutils/polkit-kde \
		${LOCALBASE}/etc/pam.d/kde:${PORTSDIR}/security/pam_kde

CONFLICTS=	kdeaccessibility-4.[0-6].* kdebase-workspace-4.[0-6].*

SUB_FILES=	kdm layout.js
USE_RC_SUBR=	kdm4
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	glib20
USE_ICONV=	yes
USE_KDE4=	akonadi automoc4 kdehier kdelibs kdeprefix oxygen pimlibs
KDE4_BUILDENV=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus declarative gui network opengl phonon \
		qt3support qtestlib script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	kbproto x11 xau xcomposite xcursor xdamage xdmcp xfixes \
		xft xi xinerama xkbfile xrandr xrender xres xscrnsaver xtst
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

USERS=		kdm
GROUPS=		kdm

MAN1=		plasmaengineexplorer.1 plasmapkg.1 plasmoidviewer.1

# PyKDE4, Xmms and Googlegadgets could be enabled.
CMAKE_ARGS+=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DBUILD_python:BOOL=OFF \
		-DBUILD_ruby:BOOL=OFF \
		-DWITH_BlueZ:BOOL=OFF \
		-DWITH_Sensors:BOOL=OFF \
		-DWITH_NetworkManager:BOOL=OFF \
		-DWITH_Xmms:BOOL=OFF \
		-DWITH_Googlegadgets:BOOL=OFF \
		-DWITH_PyKDE4:BOOL=OFF

OPTIONS=	GPS "Support for GPS geolocation dataengine" on \
		PHONON_GSTREAMER "GStreamer backend for Phonon (recommended)" on \
		PHONON_VLC "VLC backend for Phonon" off \
		PLASMA_PYTHON "Support for plasmoids written in Python" off \
		PLASMA_RUBY "Support for plasmoids written in Ruby" off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_GPS)
LIB_DEPENDS+=	gps.20:${PORTSDIR}/astro/gpsd
CMAKE_ARGS+=	-DWITH_libgps:BOOL=ON
PLIST_SUB+=	GPS=""
.else
CMAKE_ARGS+=	-DWITH_libgps:BOOL=OFF
PLIST_SUB+=	GPS="@comment "
.endif

.if !defined(WITHOUT_PHONON_GSTREAMER)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_gstreamer.so:${PORTSDIR}/multimedia/phonon-gstreamer
.endif

.if defined(WITH_PHONON_VLC)
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so:${PORTSDIR}/multimedia/phonon-vlc
.endif

.if defined(WITH_PLASMA_PYTHON)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:${PORTSDIR}/x11/plasma-scriptengine-python
.endif

.if defined(WITH_PLASMA_RUBY)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:${PORTSDIR}/x11/plasma-scriptengine-ruby
.endif

.include <bsd.port.pre.mk>

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
		${PATCH_WRKSRC}/kcontrol/keyboard/x11_helper.cpp \
		${PATCH_WRKSRC}/kdm/backend/client.c \
		${PATCH_WRKSRC}/kdm/kfrontend/genkdmconf.c \
		${PATCH_WRKSRC}/CMakeLists.txt

pre-configure:
	${REINPLACE_CMD} -e '/ksysguardd/ d' \
		${PATCH_WRKSRC}/ksysguard/CMakeLists.txt \
		${PATCH_WRKSRC}/ksysguard/example/CMakeLists.txt
	${REINPLACE_CMD} -e 's|<qhash.h>|<QHash>|' \
		${PATCH_WRKSRC}/kwin/effects/thumbnailaside/thumbnailaside.h
	${REINPLACE_CMD} -e '/PolicyKit/ d' \
		${PATCH_WRKSRC}/doc/CMakeLists.txt

post-install:
	${LN} -sf ${PREFIX}/bin/startkde ${PREFIX}/bin/startkde4
	${MV} ${PREFIX}/bin/kdm ${PREFIX}/bin/kdm-bin
	${MV} ${PREFIX}/lib/kde4/libexec/kdm_config ${PREFIX}/lib/kde4/libexec/kdm-bin_config
	${MV} ${PREFIX}/lib/kde4/libexec/kdm_greet ${PREFIX}/lib/kde4/libexec/kdm-bin_greet
	${INSTALL_SCRIPT} ${WRKDIR}/kdm ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/apps/plasma/layout-templates/org.kde.freebsd.defaultWallpaper/contents
	${INSTALL_DATA} ${FILESDIR}/metadata.desktop ${PREFIX}/share/apps/plasma/layout-templates/org.kde.freebsd.defaultWallpaper
	${INSTALL_DATA} ${WRKDIR}/layout.js ${PREFIX}/share/apps/plasma/layout-templates/org.kde.freebsd.defaultWallpaper/contents
	cd ${WRKDIR}/stripes-freebsd-1.0 && \
		${COPYTREE_SHARE} . ${PREFIX}/share/wallpapers
	${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
