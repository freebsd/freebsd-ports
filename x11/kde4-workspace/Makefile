# Created by: kde@FreeBSD.org
# $FreeBSD$

PORTNAME=	kde-workspace
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE_kde} \
		${MASTER_SITE_LOCAL} \
		http://people.FreeBSD.org/~avilla/distfiles/
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src/:kde \
			avilla/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:kde \
		stripes-freebsd-1.0.tar.bz2
DIST_SUBDIR=	KDE
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	dbus-1.3:${PORTSDIR}/devel/dbus \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit \
		pci.3:${PORTSDIR}/devel/libpci \
		hal.1:${PORTSDIR}/sysutils/hal \
		qalculate.5:${PORTSDIR}/math/libqalculate \
		prison.0:${PORTSDIR}/graphics/prison \
		boost_thread:${PORTSDIR}/devel/boost-libs \
		dbusmenu-qt.2:${PORTSDIR}/devel/libdbusmenu-qt \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		kactivities.6:${PORTSDIR}/x11/kactivities

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
		${LOCALBASE}/etc/pam.d/kde:${PORTSDIR}/security/pam_kde

CONFLICTS=	kdeaccessibility-4.[0-6].* kdebase-workspace-4.[0-6].*

SUB_FILES=	pkg-message
USE_RC_SUBR=	kdm4
USE_XZ=		yes
USE_GETTEXT=	yes
USE_GL=		glu
USE_GNOME=	glib20
USE_ICONV=	yes
USE_KDE4=	kdehier kdelibs kdeprefix oxygen pimlibs \
		akonadi automoc4 ontologies qimageblitz soprano strigi
KDE4_BUILDENV=	yes
USE_QT4=	dbus declarative gui network opengl phonon \
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
		PLASMA_RUBY "Support for plasmoids written in Ruby" off \
		UPOWER "Support for power management" on \
		WALLPAPERS "Official KDE wallpapers" on

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
USE_GSTREAMER+=	core
USE_QT4+=	phonon-gst_run
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

.if !defined(WITHOUT_UPOWER)
RUN_DEPENDS+=	${LOCALBASE}/libexec/upowerd:${PORTSDIR}/sysutils/upower
.endif

.if !defined(WITHOUT_WALLPAPERS)
RUN_DEPENDS+=	${KDE4_PREFIX}/share/wallpapers/Horos/metadata.desktop:${PORTSDIR}/x11-themes/kde4-wallpapers
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
LIB_DEPENDS+=	usb-0.1.8:${PORTSDIR}/devel/libusb
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
.if defined(WITHOUT_PHONON_GSTREAMER)
	@${CAT} ${FILESDIR}/pkg-message-phonon-gstreamer >> ${PKGMESSAGE}
.endif
	@${HEAD} -1 ${PKGMESSAGE} >> ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
