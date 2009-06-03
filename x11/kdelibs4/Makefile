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

BUILD_DEPENDS=	${LOCALBASE}/lib/libhspell.a:${PORTSDIR}/hebrew/hspell
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
		hal.1:${PORTSDIR}/sysutils/hal \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient \
		phonon.4:${PORTSDIR}/multimedia/phonon
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		iceauth:${PORTSDIR}/x11/iceauth \
		xauth:${PORTSDIR}/x11/xauth

.if exists(${LOCALBASE}/include/avahi-compat-libdns_sd/dns_sd.h) || defined(WITH_LIBDNS)
LIB_DEPENDS+=	avahi-qt4:${PORTSDIR}/net/avahi-qt4 \
		dns_sd:${PORTSDIR}/net/avahi-libdns
.else
LIB_DEPENDS+=	dns_sd:${PORTSDIR}/net/mDNSResponder
.endif

CONFLICTS=	kdebase-workspace-4.1.*

LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network opengl qt3support \
		qtestlib script sql svg xml designer \
		assistant svg qdbusviewer makeqpf imageformats \
		qmake_build moc_build rcc_build uic_build
USE_GNOME=	libxml2 libxslt
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS+=	-DWITH_FAM:BOOL=Off \
		-DKDE4_PREFIX:String=${KDE4_PREFIX}

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

post-extract:
	${MKDIR} ${WRKSRC}

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/../cmake/modules/*.cmake
	#prevent updating mime during build
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${WRKSRC}/../mimetypes/CMakeLists.txt
	#default KDEHOME dir
	${REINPLACE_CMD} -e '/KDE_DEFAULT_HOME/s|.kde|.kde4|' \
		${WRKSRC}/../CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
