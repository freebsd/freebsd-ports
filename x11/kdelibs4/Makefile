# Created by: arved@FreeBSD.org
# $FreeBSD$

PORTNAME=	kdelibs
PORTVERSION=	${KDE4_VERSION}
PORTREVISION=	2
CATEGORIES=	x11 kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		jasper:${PORTSDIR}/graphics/jasper \
		pcre:${PORTSDIR}/devel/pcre \
		avahi-core:${PORTSDIR}/net/avahi-app \
		enchant:${PORTSDIR}/textproc/enchant \
		gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		hal:${PORTSDIR}/sysutils/hal \
		qca:${PORTSDIR}/devel/qca \
		HUpnp:${PORTSDIR}/net/hupnp \
		polkit-qt-core-1:${PORTSDIR}/sysutils/polkit-qt \
		dbusmenu-qt:${PORTSDIR}/devel/libdbusmenu-qt

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		xauth:${PORTSDIR}/x11/xauth \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

CONFLICTS=	kdebase-runtime-4.5.[0-5]

LATEST_LINK=	${PORTNAME}4

USE_XZ=		yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	kdehier kdeprefix oxygen \
		attica automoc4 ontologies sharedmime soprano strigi
USES=		cmake:outsource fam gettext perl5
USE_OPENSSL=	yes
USE_QT4=	corelib dbus declarative designer_build gui \
		network opengl phonon qt3support \
		qtestlib script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build \
		imageformats_run qdbusviewer_run
USE_XORG=	sm x11 xcursor xext xfixes xrender xtst
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null

CMAKE_ARGS+=	-DWITH_ACL:BOOL=Off \
		-DWITH_FAM:BOOL=On \
		-DWITH_ASPELL:BOOL=Off \
		-DWITH_HSPELL:BOOL=Off \
		-DHUPNP_ENABLED:BOOL=On \
		-DKDE_DISTRIBUTION_TEXT:STRING="${OPSYS}" \
		-DKDE_DEFAULT_HOME:STRING=".kde4"

MAN1=	checkXML.1 \
	kconfig_compiler.1 \
	kde4-config.1 \
	kdecmake.1 \
	kjs.1 \
	kjscmd.1 \
	kross.1 \
	makekdewidgets.1 \
	preparetips.1
MAN7=	kdeoptions.7 \
	qtoptions.7
MAN8=	kbuildsycoca4.8 \
	kcookiejar4.8 \
	kded4.8 \
	kdeinit4.8 \
	meinproc4.8

OPTIONS_DEFINE=	AVAHI
AVAHI_DESC=	Use Avahi's mDNSResponder (otherwise Apple's)

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ConfigureChecks.cmake
.endif

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/avahi-libdns
.else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
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
# Ports fails to locate pimlibs and workspace when PREFIX!=KDE4_PREFIX.
# More search paths resolve the problem.
.for module in KdepimLibs KDE4Workspace
	${REINPLACE_CMD} -e '/find_package/s,PATHS,PATHS ${KDE4_PREFIX}/lib/cmake/${module},' \
		${PATCH_WRKSRC}/cmake/modules/Find${module}.cmake
.endfor

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

.include <bsd.port.post.mk>
