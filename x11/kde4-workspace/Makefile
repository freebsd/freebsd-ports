# $FreeBSD$

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	12
CATEGORIES=	x11 kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libck-connector.so:sysutils/consolekit2 \
		libpci.so:devel/libpci \
		libhal.so:sysutils/hal \
		libqjson.so:devel/qjson \
		libcln.so:math/cln \
		libqalculate.so:math/libqalculate \
		libprison.so:graphics/prison \
		libboost_thread.so:devel/boost-libs \
		libdbusmenu-qt.so:devel/libdbusmenu-qt \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libpng.so:graphics/png \
		libxcb-render-util.so:x11/xcb-util-renderutil \
		libxcb-image.so:x11/xcb-util-image \
		libxcb-keysyms.so:x11/xcb-util-keysyms
BUILD_DEPENDS=	xrdb:x11/xrdb
RUN_DEPENDS=	${KDE_PREFIX}/env/xdg-env.sh:misc/kde4-xdg-env \
		${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		xprop:x11/xprop \
		xsetroot:x11/xsetroot \
		xmessage:x11/xmessage \
		xrdb:x11/xrdb \
		mkfontdir:x11-fonts/mkfontdir \
		xset:x11/xset \
		setxkbmap:x11/setxkbmap \
		${KDE_PREFIX}/bin/ksysguardd:sysutils/ksysguardd \
		${KDE_PREFIX}/lib/kde4/libexec/polkit-kde-authentication-agent-1:sysutils/polkit-kde \
		${KDE_PREFIX}/lib/kde4/libexec/polkitkde1helper:sysutils/kcm-polkit-kde \
		${LOCALBASE}/etc/pam.d/kde:security/pam_kde \
		${KDE_PREFIX}/share/apps/ksplash/Themes/Default/Theme.rc:x11-themes/kde4-base-artwork

USES=		cmake:outsource,noninja compiler:c++11-lib gettext gmake jpeg kde:4 \
		pkgconfig shebangfix tar:xz
USE_GL=		gl glu
USE_GNOME=	glib20 libxml2
USE_KDE=	kactivities kdelibs nepomuk-core oxygen-icons5 \
		pimlibs akonadi automoc4 ontologies qimageblitz soprano strigi
USE_QT4=	corelib dbus declarative designer_build gui network \
		opengl phonon qtestlib script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	ice sm kbproto x11 xau xcb xcomposite xcursor xdamage xdmcp xext xfixes \
		xft xi xinerama xkbfile xpm xrandr xrender xres xscrnsaver xtst xxf86vm
SHEBANG_FILES=	kwin/clients/oxygen/data/update_oxygen.pl
USE_LDCONFIG=	yes

KDE_APPLICATIONS_VERSION=	15.08.0

CMAKE_ARGS=	-DCMAKE_REQUIRED_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DBUILD_python:BOOL=OFF \
		-DBUILD_ruby:BOOL=OFF \
		-DWITH_Xmms:BOOL=OFF \
		-DWITH_UDev:BOOL=OFF

SUB_FILES=	pkg-message
USE_RC_SUBR=	kdm4

USERS=		kdm
GROUPS=		kdm

OPTIONS_DEFINE=	GLES GPS KACTIVITY UPOWER WALLPAPERS
OPTIONS_GROUP=	PHONON PLASMA
OPTIONS_GROUP_PHONON=	GSTREAMER VLC
OPTIONS_GROUP_PLASMA=	PYTHON RUBY
OPTIONS_DEFAULT=	GLES GPS KACTIVITY UPOWER VLC WALLPAPERS
OPTIONS_SUB=	yes # GPS GLES

GLES_DESC=	OpenGL ES 2.0 support in kwin and kinfocenter
GLES_USE=	GL=egl,glesv2
GLES_CMAKE_OFF=	-DWITH_OpenGLES=off

GPS_DESC=	GPS geolocation via gpsd
GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_CMAKE_ON=	-DWITH_libgps:BOOL=ON
GPS_CMAKE_OFF=	-DWITH_libgps:BOOL=OFF

GSTREAMER_DESC=	Multimedia via Phonon-GStreamer
GSTREAMER_USE=	QT4=phonon-gst_run

KACTIVITY_DESC=		Activity Manager daemon
KACTIVITY_RUN_DEPENDS=	${KDE_PREFIX}/bin/kactivitymanagerd:x11/kactivitymanagerd

PYTHON_DESC=		Python plasmoids support
PYTHON_RUN_DEPENDS=	${KDE_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:x11/plasma-scriptengine-python

RUBY_DESC=		Ruby plasmoids support
RUBY_RUN_DEPENDS=	${KDE_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:x11/plasma-scriptengine-ruby

UPOWER_DESC=		Power management via UPower
UPOWER_RUN_DEPENDS=	${LOCALBASE}/libexec/upowerd:sysutils/upower

VLC_DESC=		Multimedia via Phonon-VLC
VLC_RUN_DEPENDS=	${KDE_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so:multimedia/phonon-vlc

WALLPAPERS_DESC=	Install official KDE wallpapers
WALLPAPERS_RUN_DEPENDS=	${KDE_PREFIX}/share/wallpapers/Horos/metadata.desktop:x11-themes/kde4-wallpapers \
			${KDE_PREFIX}/share/wallpapers/stripes-freebsd-blue/metadata.desktop:x11-themes/kde4-wallpapers-freebsd

.if !exists(/usr/lib/libutempter.so)
LIB_DEPENDS+=	libutempter.so:sysutils/libutempter
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
	${REINPLACE_CMD} -e '/PolicyKit/ d' \
		${PATCH_WRKSRC}/doc/CMakeLists.txt

post-install:
	${LN} -sf ${PREFIX}/bin/startkde ${STAGEDIR}${PREFIX}/bin/startkde4
# Install kde4.desktop to launch kde4 via sddm.
	${MKDIR} ${STAGEDIR}${PREFIX}/share/xsessions
	${INSTALL_DATA} ${FILESDIR}/kde4.desktop ${STAGEDIR}${PREFIX}/share/xsessions

post-install-GSTREAMER-on:
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}

post-install-GSTREAMER-off:
	@${CAT} ${FILESDIR}/pkg-message.gstreamer >> ${PKGMESSAGE}
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}

.include <bsd.port.mk>
