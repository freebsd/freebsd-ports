# Created by: arved@FreeBSD.org
# $FreeBSD$

PORTNAME=	kdelibs
PORTVERSION=	${KDE4_KDELIBS_VERSION}
PORTREVISION=	6
CATEGORIES=	x11 kde kde-applications
PKGNAMESUFFIX=	-kde4

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

DEPRECATED=	KDE4 is EOL upstream
EXPIRATION_DATE=	2018-12-31

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	error: member access into incomplete type 'RSA' (aka 'rsa_st')

LIB_DEPENDS=	libImath.so:graphics/ilmbase \
		libjasper.so:graphics/jasper \
		libpcre.so:devel/pcre \
		libenchant.so:textproc/enchant \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libhal.so:sysutils/hal \
		libqca.so:devel/qca@qt4 \
		libpolkit-qt-core-1.so:sysutils/polkit-qt@qt4 \
		libdbusmenu-qt.so:devel/libdbusmenu-qt@qt4 \
		libstreams.so:deskutils/libstreams

BUILD_DEPENDS=	docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:misc/hicolor-icon-theme \
		xauth:x11/xauth \
		docbook-xml>0:textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl

# kdelibs's last release was as part of KDE Applications 17.08.3
KDE_APPLICATIONS_VERSION=	17.08.3

USES=		cmake:outsource fam gettext grantlee:4 jpeg kde:4 perl5 \
		qt:4 shared-mime-info shebangfix tar:xz ssl
USE_GNOME=	libxml2 libxslt
USE_KDE=	oxygen-icons5 \
		attica automoc4 ontologies soprano strigi
USE_QT=		corelib dbus declarative designer_build gui \
		network opengl phonon qt3support \
		qtestlib script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build \
		imageformats_run qdbusviewer_run
USE_XORG=	ice sm x11 xau xcursor xdmcp xext xfixes xft xpm xrender xtst
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

CMAKE_ARGS+=	-DWITH_ACL:BOOL=Off \
		-DWITH_FAM:BOOL=On \
		-DWITH_ASPELL:BOOL=Off \
		-DWITH_HSPELL:BOOL=Off \
		-DWITH_UDev:BOOL=Off \
		-DKDE_DISTRIBUTION_TEXT:STRING="${OPSYS}" \
		-DKDE_DEFAULT_HOME:STRING=".kde4"

# Do not conflict with KDE Frameworks 5 headers: instead of installing kdelibs4
# headers directly into ${LOCALBASE}/include, put them into include/kde4 (this
# also applies to all ports depending on kdelibs4 that derive their header
# installation location from it).
# If we install the headers directly into ${LOCALBASE}/include, with KDE
# Frameworks 5 installed it is possible to end up in a situation where the
# compiler is passed this:
#   -I${LOCALBASE}/include -I${LOCALBASE}/KF5
# which in turn leads to kdelibs4 headers with the same name being used instead
# of the KF5 ones, possibly breaking the build.
CMAKE_ARGS+=	-DINCLUDE_INSTALL_DIR:PATH="${KDE_PREFIX}/include/kde4"

SHEBANG_FILES=	kdecore/kconfig_compiler/checkkcfg.pl \
		kdeui/preparetips \
		khtml/bindings/scripts/generate-bindings.pl \
		kio/misc/fileshareset \
		kio/useragent.pl \
		kio/proxytype.pl \
		kioslave/http/kcookiejar/kcookiescfg.pl

OPTIONS_DEFINE=	AVAHI OPENEXR UPNP
OPTIONS_DEFAULT=	AVAHI OPENEXR
OPTIONS_SUB=	yes

AVAHI_LIB_DEPENDS=	libavahi-core.so:net/avahi-app

UPNP_DESC=	UPnP backend for Solid (WARNING: Unstable)
UPNP_LIB_DEPENDS=	libHUpnp.so:net/hupnp
UPNP_CMAKE_ON=	-DHUPNP_ENABLED:BOOL=On

OPENEXR_LIB_DEPENDS=	libIlmImf.so:graphics/openexr
OPENEXR_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_OpenEXR

post-patch:
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/kde3support/kdeui/k3sconfig.cpp \
		${PATCH_WRKSRC}/kdecore/network/k3socks.cpp \
		${PATCH_WRKSRC}/kdecore/kernel/kstandarddirs.cpp \
		${PATCH_WRKSRC}/kdeui/dialogs/kcupsoptionswidget_p.cpp \
		${PATCH_WRKSRC}/kdeui/kernel/start-session-bus.sh \
		${PATCH_WRKSRC}/kio/kssl/kopenssl.cpp \
		${PATCH_WRKSRC}/kio/kio/ksambashare.cpp \
		${PATCH_WRKSRC}/kjsembed/qtonly/FindQJSInternal.cmake
# Fix rgb named colors database path.
	${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/kdeui/colors/kcolordialog.cpp

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
			 -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/modules/*.cmake \
		${PATCH_WRKSRC}/ConfigureChecks.cmake \
		${PATCH_WRKSRC}/doc/api/doxygen.sh
	${REINPLACE_CMD} -e 's|/usr/include|${LOCALBASE}/include|g' \
		${PATCH_WRKSRC}/cmake/modules/FindDNSSD.cmake
	${REINPLACE_CMD} -e 's|soprano/cmake|cmake/Modules|g' \
		${PATCH_WRKSRC}/cmake/modules/FindSoprano.cmake
# FindBerkeleyDB.cmake should be rewritten to support multiple version
# provided by ports, instead of hardcoding one of them
#	${REINPLACE_CMD} -e 's|/usr/local/include/db4|${BDB_INCLUDE_DIR}|' \
#		-e 's|NAMES db|NAMES ${BDB_LIB_NAME} ${LOCALBASE}/lib|' \
#		${PATCH_WRKSRC}/cmake/modules/FindBerkeleyDB.cmake
# When XSync (xext) is found, xscreensaver is just used as a fallback,
# then we can disable it.
	${REINPLACE_CMD} -e '/macro_bool_to_01/ s|^.*X11_Xscreensaver.*$$|set(HAVE_XSCREENSAVER 0)|' \
		${PATCH_WRKSRC}/CMakeLists.txt

post-install:
# workaround for non-standard mime files and directories
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/mime/all \
		${STAGEDIR}/${PREFIX}/share/mime/uri

.include <bsd.port.mk>
