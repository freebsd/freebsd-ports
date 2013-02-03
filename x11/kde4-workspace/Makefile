# $FreeBSD$

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE:C@$@:kde@} \
		LOCAL/avilla
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src/:kde
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kde \
		stripes-freebsd-1.0.tar.bz2
DIST_SUBDIR=	KDE
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		ck-connector:${PORTSDIR}/sysutils/consolekit \
		pci:${PORTSDIR}/devel/libpci \
		hal:${PORTSDIR}/sysutils/hal \
		qalculate:${PORTSDIR}/math/libqalculate \
		prison:${PORTSDIR}/graphics/prison \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		dbusmenu-qt:${PORTSDIR}/devel/libdbusmenu-qt \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		kactivities:${PORTSDIR}/x11/kactivities
BUILD_DEPENDS=	xrdb:${PORTSDIR}/x11/xrdb
RUN_DEPENDS=	${KDE4_PREFIX}/env/xdg-env.sh:${PORTSDIR}/misc/kde4-xdg-env \
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
		${KDE4_PREFIX}/lib/kde4/libexec/polkitkde1helper:${PORTSDIR}/sysutils/kcm-polkit-kde \
		${LOCALBASE}/etc/pam.d/kde:${PORTSDIR}/security/pam_kde \
		${KDE4_PREFIX}/share/apps/ksplash/Themes/Default/Theme.rc:${PORTSDIR}/x11-themes/kde4-base-artwork

CONFLICTS=	kdeaccessibility-4.[0-6].* kdebase-workspace-4.[0-6].*

USE_GETTEXT=	yes
USE_GL=		glu
USE_GNOME=	glib20
USE_ICONV=	yes
USE_KDE4=	kdehier kdelibs kdeprefix oxygen pimlibs \
		akonadi automoc4 ontologies qimageblitz soprano strigi
KDE4_BUILDENV=	yes
USE_PKGCONFIG=	build
USE_QT4=	dbus declarative gui network opengl phonon \
		qt3support qtestlib script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	kbproto x11 xau xcomposite xcursor xdamage xdmcp xfixes \
		xft xi xinerama xkbfile xrandr xrender xres xscrnsaver xtst
USE_XZ=		yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

# Xmms and Googlegadgets could be enabled.
CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DBUILD_python:BOOL=OFF \
		-DBUILD_ruby:BOOL=OFF \
		-DWITH_BlueZ:BOOL=OFF \
		-DWITH_Sensors:BOOL=OFF \
		-DWITH_NetworkManager:BOOL=OFF \
		-DWITH_Xmms:BOOL=OFF \
		-DWITH_Googlegadgets:BOOL=OFF \
		-DWITH_PyKDE4:BOOL=OFF

SUB_FILES=	pkg-message
USE_RC_SUBR=	kdm4

USERS=		kdm
GROUPS=		kdm

MAN1=		plasmaengineexplorer.1 plasmapkg.1 plasmoidviewer.1

OPTIONS_DEFINE=	GPS UPOWER WALLPAPERS
OPTIONS_GROUP=	PHONON PLASMA
OPTIONS_GROUP_PHONON=	GSTREAMER VLC
OPTIONS_GROUP_PLASMA=	PYTHON RUBY
OPTIONS_DEFAULT=GPS GSTREAMER UPOWER WALLPAPERS

GPS_DESC=	GPS geolocation via gpsd
GSTREAMER_DESC=	Multimedia via Phonon-GStreamer
PYTHON_DESC=	Python plasmoids support
RUBY_DESC=	Ruby plasmoids support
UPOWER_DESC=	Power management via UPower
VLC_DESC=	Multimedia via Phonon-VLC
WALLPAPERS_DESC=Install official KDE wallpapers

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPS}
LIB_DEPENDS+=	gps:${PORTSDIR}/astro/gpsd
CMAKE_ARGS+=	-DWITH_libgps:BOOL=ON
PLIST_SUB+=	GPS=""
.else
CMAKE_ARGS+=	-DWITH_libgps:BOOL=OFF
PLIST_SUB+=	GPS="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER+=	core
USE_QT4+=	phonon-gst_run
.endif

.if ${PORT_OPTIONS:MPYTHON}
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:${PORTSDIR}/x11/plasma-scriptengine-python
.endif

.if ${PORT_OPTIONS:MRUBY}
RUN_DEPENDS+=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:${PORTSDIR}/x11/plasma-scriptengine-ruby
.endif

.if ${PORT_OPTIONS:MUPOWER}
RUN_DEPENDS+=	${LOCALBASE}/libexec/upowerd:${PORTSDIR}/sysutils/upower
.endif

.if ${PORT_OPTIONS:MVLC}
RUN_DEPENDS+=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so:${PORTSDIR}/multimedia/phonon-vlc
.endif

.if ${PORT_OPTIONS:MWALLPAPERS}
RUN_DEPENDS+=	${KDE4_PREFIX}/share/wallpapers/Horos/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
.endif

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
.endif

post-extract:
	@(cd ${WRKDIR} && ${BZIP2_CMD} ${EXTRACT_BEFORE_ARGS} \
		${_DISTDIR}/stripes-freebsd-1.0.tar.bz2 ${EXTRACT_AFTER_ARGS})

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/startkde.cmake \
		${PATCH_WRKSRC}/kcontrol/kfontinst/lib/KfiConstants.h \
		${PATCH_WRKSRC}/kcontrol/kfontinst/kio/KioFonts.cpp \
		${PATCH_WRKSRC}/kcontrol/keyboard/x11_helper.cpp \
		${PATCH_WRKSRC}/kdm/backend/client.c \
		${PATCH_WRKSRC}/kdm/kfrontend/genkdmconf.c \
		${PATCH_WRKSRC}/CMakeLists.txt
	@${RM} ${WRKSRC}/plasma/generic/applets/batterymonitor/contents/ui/*.orig

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
	${INSTALL_DATA} ${FILESDIR}/05-freebsdWallpaper.js ${PREFIX}/share/apps/plasma-desktop/init
	cd ${WRKDIR}/stripes-freebsd-1.0 && \
		${COPYTREE_SHARE} . ${PREFIX}/share/wallpapers
.if ! ${PORT_OPTIONS:MGSTREAMER}
	@${CAT} ${FILESDIR}/pkg-message.gstreamer >> ${PKGMESSAGE}
.endif
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
