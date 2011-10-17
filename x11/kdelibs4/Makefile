# -*-mode: makefile-*-
# New ports collection makefile for:	KDE libraries 4
# Date created:				19 January 2008
# Whom:					arved@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	kdelibs
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde ipv6
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

LIB_DEPENDS=	searchclient.0:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR \
		aspell.16:${PORTSDIR}/textproc/aspell \
		jasper.4:${PORTSDIR}/graphics/jasper \
		pcre.0:${PORTSDIR}/devel/pcre \
		avahi-core.7:${PORTSDIR}/net/avahi-app \
		enchant.1:${PORTSDIR}/textproc/enchant \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		hal.1:${PORTSDIR}/sysutils/hal \
		qca.2:${PORTSDIR}/devel/qca \
		HUpnp.1:${PORTSDIR}/net/hupnp \
		attica.0:${PORTSDIR}/x11-toolkits/attica \
		polkit-qt-core-1.1:${PORTSDIR}/sysutils/polkit-qt \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient \
		dbusmenu-qt.2:${PORTSDIR}/devel/libdbusmenu-qt

BUILD_DEPENDS=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell \
		${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		${LOCALBASE}/share/ontology/core/rdf.ontology:${PORTSDIR}/x11-toolkits/shared-desktop-ontologies \
		xauth:${PORTSDIR}/x11/xauth \
		${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml \
		${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:${PORTSDIR}/textproc/docbook-xsl

CONFLICTS=	kdebase-runtime-4.5.[0-5]

LATEST_LINK=	${PORTNAME}4

USE_BZIP2=	yes
USE_FAM=	yes
USE_GETTEXT=	yes
USE_GNOME=	libxml2 libxslt
USE_KDE4=	automoc4 kdehier kdeprefix oxygen sharedmime
KDE4_BUILDENV=	yes
USE_OPENSSL=	yes
USE_PERL5=	yes
USE_QT_VER=	4
QT_COMPONENTS=	dbus declarative designer gui imageformats_run \
		network opengl phonon qdbusviewer_run qt3support \
		qtestlib script sql svg webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	sm x11 xcursor xext xfixes xrender xtst
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DWITH_ACL:BOOL=Off \
		-DWITH_FAM:BOOL=On \
		-DHUPNP_INCLUDE_PATH:PATH="${LOCALBASE}/include" \
		-D_KDE_DEFAULT_HOME_POSTFIX:STRING="4"

MAN1=	checkXML.1 \
	kde4-config.1 \
	kdecmake.1 \
	kjs.1 \
	kjscmd.1 \
	kross.1 \
	makekdewidgets.1
MAN7=	kdeoptions.7 \
	qtoptions.7
MAN8=	kbuildsycoca4.8 \
	kcookiejar4.8 \
	kded4.8 \
	kdeinit4.8 \
	meinproc4.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma.5:${PORTSDIR}/archivers/xz
.endif

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	utempter:${PORTSDIR}/sysutils/libutempter
EXTRA_PATCHES=	${FILESDIR}/extra-patch-ConfigureChecks.cmake
.endif

.if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h) || defined(WITH_LIBDNS)
LIB_DEPENDS+=	avahi-qt4.1:${PORTSDIR}/net/avahi-qt4 \
		dns_sd:${PORTSDIR}/net/avahi-libdns
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

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
