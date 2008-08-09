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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
PKGNAMESUFFIX?=	# empty
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Base set of libraries needed by KDE programs

LIB_DEPENDS=	searchclient:${PORTSDIR}/deskutils/strigi \
		soprano.4:${PORTSDIR}/textproc/soprano \
		IlmImf:${PORTSDIR}/graphics/OpenEXR \
		aspell:${PORTSDIR}/textproc/aspell \
		jasper:${PORTSDIR}/graphics/jasper \
		pcre:${PORTSDIR}/devel/pcre \
		avahi-core:${PORTSDIR}/net/avahi \
		enchant.1:${PORTSDIR}/textproc/enchant \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg \
		dns_sd:${PORTSDIR}/net/mDNSResponder \
		idn:${PORTSDIR}/dns/libidn \
		hal.1:${PORTSDIR}/sysutils/hal \
		smbclient.0:${PORTSDIR}/net/samba-libsmbclient \
		phonon.4:${PORTSDIR}/multimedia/phonon
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info \
		iceauth:${PORTSDIR}/x11/iceauth \
		xauth:${PORTSDIR}/x11/xauth
# XXX: hebrew/hspell?
# XXX: gssapi/kerberos special handling?

CONFLICTS=	qt4-phonon-4*
LATEST_LINK=	${PORTNAME}4

USE_KDE4=	kdeprefix kdehier automoc4 sharedmime
KDE4_BUILDENV=	yes
USE_BZIP2=	yes
USE_FAM=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui moc network opengl qmake qt3support \
		qtestlib rcc script sql svg uic3 xml designer \
		assistant svg qdbusviewer makeqpf imageformats
USE_GNOME=	libxml2 libxslt

MAN1=		checkXML.1 kde4-config.1 makekdewidgets.1 kdecmake.1
MAN7=		kdeoptions.7 qtoptions.7
MAN8=		kbuildsycoca4.8

post-extract:
	${MKDIR} ${WRKSRC}

post-patch:
#fix finding automoc when PREFIX is not matched KDE4_PREFIX
	${REINPLACE_CMD} -e 's|NO_DEFAULT_PATH|${KDE4_PREFIX} NO_DEFAULT_PATH|' \
		${WRKSRC}/../cmake/modules/FindAutomoc4.cmake

pre-configure:
	${REINPLACE_CMD} -e 's|<qdatetime.h>|<QDateTime>|'\
		${WRKSRC}/../kjs/api/kjsobject.cpp
	#prevent updating mime during build
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/d; /SharedMimeInfo/d' \
		${WRKSRC}/../mimetypes/CMakeLists.txt
	${REINPLACE_CMD} -e 's|".kde"|".kde4"|' \
		${WRKSRC}/../CMakeLists.txt

post-install:
	@-update-mime-database ${KDE4_PREFIX}/share/mime

.include <bsd.port.mk>
