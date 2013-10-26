# $FreeBSD$

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop

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
		xcb-render-util:${PORTSDIR}/x11/xcb-util-renderutil \
		xcb-image:${PORTSDIR}/x11/xcb-util-image
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

USE_GL=		glu
USE_GNOME=	glib20
USE_KDE4=	kactivities kdehier kdelibs kdeprefix oxygen pimlibs \
		akonadi automoc4 ontologies qimageblitz soprano strigi
USES=		cmake:outsource pkgconfig gettext iconv
USE_QT4=	corelib dbus declarative designer_build gui network \
		opengl phonon qtestlib script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	kbproto x11 xau xcomposite xcursor xdamage xdmcp xfixes \
		xft xi xinerama xkbfile xrandr xrender xres xscrnsaver xtst
USE_XZ=		yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

# Xmms and Googlegadgets could be enabled.
CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DBUILD_python:BOOL=OFF \
		-DBUILD_ruby:BOOL=OFF \
		-DWITH_NetworkManager:BOOL=OFF \
		-DWITH_Xmms:BOOL=OFF \
		-DWITH_Googlegadgets:BOOL=OFF

SUB_FILES=	pkg-message
USE_RC_SUBR=	kdm4

USERS=		kdm
GROUPS=		kdm

OPTIONS_DEFINE=	GPS KACTIVITY UPOWER WALLPAPERS
OPTIONS_GROUP=	PHONON PLASMA
OPTIONS_GROUP_PHONON=	GSTREAMER VLC
OPTIONS_GROUP_PLASMA=	PYTHON RUBY
OPTIONS_DEFAULT=GPS GSTREAMER KACTIVITY UPOWER WALLPAPERS

GPS_DESC=	GPS geolocation via gpsd
GSTREAMER_DESC=	Multimedia via Phonon-GStreamer
KACTIVITY_DESC=	Activity Manager daemon
PYTHON_DESC=	Python plasmoids support
RUBY_DESC=	Ruby plasmoids support
UPOWER_DESC=	Power management via UPower
VLC_DESC=	Multimedia via Phonon-VLC
WALLPAPERS_DESC=Install official KDE wallpapers

NO_STAGE=	yes
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

.if ${PORT_OPTIONS:MKACTIVITY}
RUN_DEPENDS+=	${KDE4_PREFIX}/bin/kactivitymanagerd:${PORTSDIR}/x11/kactivitymanagerd
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
RUN_DEPENDS+=	${KDE4_PREFIX}/share/wallpapers/Horos/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers \
		${KDE4_PREFIX}/share/wallpapers/stripes-freebsd-blue/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers-freebsd
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1:${PORTSDIR}/devel/libusb
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
	${RM} ${WRKSRC}/plasma/generic/applets/batterymonitor/contents/code/logic.js.orig
	${RM} ${WRKSRC}/plasma/generic/applets/batterymonitor/contents/ui/batterymonitor.qml.orig

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
.if ! ${PORT_OPTIONS:MGSTREAMER}
	@${CAT} ${FILESDIR}/pkg-message.gstreamer >> ${PKGMESSAGE}
.endif
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
