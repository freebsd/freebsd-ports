# $FreeBSD$

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_WORKSPACE_VERSION}
PORTREVISION=	4
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${KDE4_VERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Plasma Desktop

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit \
		libpci.so:${PORTSDIR}/devel/libpci \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libqalculate.so:${PORTSDIR}/math/libqalculate \
		libprison.so:${PORTSDIR}/graphics/prison \
		libboost_thread.so:${PORTSDIR}/devel/boost-libs \
		libdbusmenu-qt.so:${PORTSDIR}/devel/libdbusmenu-qt \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libpng.so:${PORTSDIR}/graphics/png \
		libxcb-render-util.so:${PORTSDIR}/x11/xcb-util-renderutil \
		libxcb-image.so:${PORTSDIR}/x11/xcb-util-image \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms
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

USE_GL=		glu
USE_GNOME=	glib20
USE_KDE4=	kactivities kdelibs kdeprefix nepomuk-core oxygen \
		pimlibs akonadi automoc4 ontologies qimageblitz soprano strigi
USES=		cmake:outsource compiler:c++11-lib gettext gmake jpeg \
		pkgconfig shebangfix tar:xz
USE_QT4=	corelib dbus declarative designer_build gui network \
		opengl phonon qtestlib script sql webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	kbproto x11 xau xcomposite xcursor xdamage xdmcp xfixes \
		xft xi xinerama xkbfile xrandr xrender xres xscrnsaver xtst
SHEBANG_FILES=	kwin/clients/oxygen/data/update_oxygen.pl
USE_LDCONFIG=	yes

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
GPS_LIB_DEPENDS=	libgps.so:${PORTSDIR}/astro/gpsd
GPS_CMAKE_ON=	-DWITH_libgps:BOOL=ON
GPS_CMAKE_OFF=	-DWITH_libgps:BOOL=OFF

GSTREAMER_DESC=	Multimedia via Phonon-GStreamer
GSTREAMER_USE=	QT4=phonon-gst_run

KACTIVITY_DESC=		Activity Manager daemon
KACTIVITY_RUN_DEPENDS=	${KDE4_PREFIX}/bin/kactivitymanagerd:${PORTSDIR}/x11/kactivitymanagerd

PYTHON_DESC=		Python plasmoids support
PYTHON_RUN_DEPENDS=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_python/plasma_importer.py:${PORTSDIR}/x11/plasma-scriptengine-python

RUBY_DESC=		Ruby plasmoids support
RUBY_RUN_DEPENDS=	${KDE4_PREFIX}/share/apps/plasma_scriptengine_ruby/applet.rb:${PORTSDIR}/x11/plasma-scriptengine-ruby

UPOWER_DESC=		Power management via UPower
UPOWER_RUN_DEPENDS=	${LOCALBASE}/libexec/upowerd:${PORTSDIR}/sysutils/upower

VLC_DESC=		Multimedia via Phonon-VLC
VLC_RUN_DEPENDS=	${KDE4_PREFIX}/lib/kde4/plugins/phonon_backend/phonon_vlc.so:${PORTSDIR}/multimedia/phonon-vlc

WALLPAPERS_DESC=	Install official KDE wallpapers
WALLPAPERS_RUN_DEPENDS=	${KDE4_PREFIX}/share/wallpapers/Horos/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers \
			${KDE4_PREFIX}/share/wallpapers/stripes-freebsd-blue/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers-freebsd

.if !exists(/usr/lib/libutempter.so)
LIB_DEPENDS+=	libutempter.so:${PORTSDIR}/sysutils/libutempter
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

post-install-GSTREAMER-on:
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}

post-install-GSTREAMER-off:
	@${CAT} ${FILESDIR}/pkg-message.gstreamer >> ${PKGMESSAGE}
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}

.include <bsd.port.mk>
