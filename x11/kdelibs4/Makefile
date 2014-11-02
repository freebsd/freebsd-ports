# Created by: arved@FreeBSD.org
# $FreeBSD$

PORTNAME=	kdelibs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	1
CATEGORIES=	x11 kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

LIB_DEPENDS=	libIlmImf.so:${PORTSDIR}/graphics/OpenEXR \
		libjasper.so:${PORTSDIR}/graphics/jasper \
		libpcre.so:${PORTSDIR}/devel/pcre \
		libavahi-core.so:${PORTSDIR}/net/avahi-app \
		libenchant.so:${PORTSDIR}/textproc/enchant \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libhal.so:${PORTSDIR}/sysutils/hal \
		libqca.so:${PORTSDIR}/devel/qca \
		libHUpnp.so:${PORTSDIR}/net/hupnp \
		libpolkit-qt-core-1.so:${PORTSDIR}/sysutils/polkit-qt \
		libdbusmenu-qt.so:${PORTSDIR}/devel/libdbusmenu-qt \
		libgrantlee_gui.so:${PORTSDIR}/devel/grantlee

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xauth:${PORTSDIR}/x11/xauth \
		${LOCALBASE}/share/xml/docbook/4.2:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdeprefix oxygen \
		attica automoc4 ontologies soprano strigi
USES=		cmake:outsource fam gettext perl5 shared-mime-info shebangfix tar:xz
USE_OPENSSL=	yes
USE_QT4=	corelib dbus declarative designer_build gui \
		network opengl phonon qt3support \
		qtestlib script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build \
		imageformats_run qdbusviewer_run
USE_XORG=	sm x11 xcursor xext xfixes xft xpm xrender xtst
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

CMAKE_ARGS+=	-DWITH_ACL:BOOL=Off \
		-DWITH_FAM:BOOL=On \
		-DWITH_ASPELL:BOOL=Off \
		-DWITH_HSPELL:BOOL=Off \
		-DWITH_UDev:BOOL=Off \
		-DHUPNP_ENABLED:BOOL=On \
		-DKDE_DISTRIBUTION_TEXT:STRING="${OPSYS}" \
		-DKDE_DEFAULT_HOME:STRING=".kde4"

SHEBANG_FILES=	kdecore/kconfig_compiler/checkkcfg.pl \
		kdeui/preparetips \
		khtml/bindings/scripts/generate-bindings.pl \
		kio/misc/fileshareset \
		kio/useragent.pl \
		kio/proxytype.pl \
		kioslave/http/kcookiejar/kcookiescfg.pl

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900004
LIB_DEPENDS+=	libutempter.so:${PORTSDIR}/sysutils/libutempter
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ConfigureChecks.cmake
.endif

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

.include <bsd.port.post.mk>
