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
PKGNAMESUFFIX?=	# empty
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

BUILD_DEPENDS=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info
LIB_DEPENDS=	searchclient:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		aspell:${PORTSDIR}/textproc/aspell \
		jasper:${PORTSDIR}/graphics/jasper \
		pcre:${PORTSDIR}/devel/pcre \
		avahi-core:${PORTSDIR}/net/avahi-app \
		enchant.1:${PORTSDIR}/textproc/enchant \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		idn:${PORTSDIR}/dns/libidn \
		utempter:${PORTSDIR}/sysutils/libutempter \
		hal.1:${PORTSDIR}/sysutils/hal \
		lzma.0:${PORTSDIR}/archivers/lzmautils-devel \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		iceauth:${PORTSDIR}/x11/iceauth \
		xauth:${PORTSDIR}/x11/xauth

CONFLICTS=	kdebase-workspace-4.1.*

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_BISON=	build
USE_OPENSSL=	yes
USE_BDB=	40+
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network opengl qt3support \
		qtestlib script sql svg xml designer phonon \
		assistant svg qdbusviewer makeqpf imageformats \
		qmake_build moc_build rcc_build uic_build
USE_GNOME=	libxml2 libxslt
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DWITH_FAM:BOOL=Off \
		-DWITH_ACL:BOOL=Off \
		-DKDE4_PREFIX:String=${KDE4_PREFIX} \
		-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include" \
		-DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib" \
		-DCMAKE_SHARED_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DCMAKE_INCLUDE_PATH:STRING="${LOCALBASE}/include"
CMAKE_ARGS+=	-DCMAKE_EXE_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"
CMAKE_ARGS+=	-DCMAKE_SHARED_LINKER_FLAGS:STRING="-L${LOCALBASE}/lib"

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

.if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h) || defined(WITH_LIBDNS)
LIB_DEPENDS+=	avahi-qt4:${PORTSDIR}/net/avahi-qt4 \
		dns_sd:${PORTSDIR}/net/avahi-libdns
.else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.endif

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/../kde3support/kdeui/k3sconfig.cpp \
		${WRKSRC}/../kdecore/network/k3socks.cpp \
		${WRKSRC}/../kdecore/kernel/kstandarddirs.cpp \
		${WRKSRC}/../kdeui/dialogs/kcupsoptionswidget_p.cpp \
		${WRKSRC}/../kdeui/kernel/start-session-bus.sh \
		${WRKSRC}/../kio/kssl/kopenssl.cpp \
		${WRKSRC}/../kio/kio/ksambashare.cpp \
		${WRKSRC}/../kjsembed/qtonly/FindQJSInternal.cmake

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/../cmake/modules/*.cmake
	${REINPLACE_CMD} -e 's|/usr/local/include/db4|${BDB_INCLUDE_DIR}|' \
		-e 's|NAMES db|NAMES ${BDB_LIB_NAME} ${LOCALBASE}/lib|' \
		${WRKSRC}/../cmake/modules/FindBerkeleyDB.cmake
	${REINPLACE_CMD} -e 's|addToUtmp ""|addToUtmp "${LOCALBASE}/lib"|' \
		-e 's|utempter.h|${LOCALBASE}/include/utempter.h|' \
		${WRKSRC}/../ConfigureChecks.cmake
	#prevent updating mime during build
#	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
#		${WRKSRC}/../mimetypes/CMakeLists.txt
	#default KDEHOME dir
	${REINPLACE_CMD} -e '/KDE_DEFAULT_HOME/s|.kde|.kde4|' \
		${WRKSRC}/../CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>
