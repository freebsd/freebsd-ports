# $FreeBSD$

PORTNAME=	kde-runtime
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	x11 kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic applications for the KDE system

LIB_DEPENDS=	IlmImf:${PORTSDIR}/graphics/OpenEXR \
		jpeg:${PORTSDIR}/graphics/jpeg \
		exiv2:${PORTSDIR}/graphics/exiv2 \
		slp:${PORTSDIR}/net/openslp \
		smbclient:${PORTSDIR}/net/samba-libsmbclient \
		ssh:${PORTSDIR}/security/libssh \
		qzeitgeist:${PORTSDIR}/sysutils/qzeitgeist \
		nepomukcore:${PORTSDIR}/sysutils/nepomuk-core \
		kactivities:${PORTSDIR}/x11/kactivities
# Explicitly depend on libssh to avoid interference with ssh.4 from
# compat7x.
BUILD_DEPENDS=	${LOCALBASE}/lib/libssh.so:${PORTSDIR}/security/libssh
RUN_DEPENDS=	cagibid:${PORTSDIR}/net/cagibi

CONFLICTS=	kdebase-runtime-4.[0-6].* kdebase-workspace-4.5.[0-5] nepomukcontroller-0.2

USE_XZ=		yes
USE_GETTEXT=	yes
USE_KDE4=	kdehier kdelibs kdeprefix oxygen \
		attica automoc4 pimlibs sharedmime strigi
KDE4_BUILDENV=	yes
USE_QT4=	dbus declarative designer gui phonon qt3support \
		script svg webkit xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11 xcursor
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kdesu.1
MAN8=		nepomukserver.8 nepomukservicestub.8

OPTIONS_DEFINE=	NEPOMUK PULSEAUDIO XINE ZEITGEIST

NEPOMUK_DESC=	Nepomuk semantic desktop via Virtuoso
PULSEAUDIO_DESC=Audio configuration via PulseAudio
XINE_DESC=	Phonon-xine configuration via xine
ZEITGEIST_DESC=	Event logging via Zeitgeist

# Explicitly disable ALSA, see for details:
# http://mail.kde.org/pipermail/kde-freebsd/2010-March/008015.html
CMAKE_ARGS+=	-DWITH_ALSA:BOOL=OFF

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNEPOMUK}
RUN_DEPENDS+=	virtuoso-t:${PORTSDIR}/databases/virtuoso
.endif

.if ${PORT_OPTIONS:MSPEAKER}
LIB_DEPENDS+=	pulse:${PORTSDIR}/audio/pulseaudio \
		canberra:${PORTSDIR}/audio/libcanberra
USE_GNOME+=	glib20
.else
CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MXINE}
LIB_DEPENDS+=	xine:${PORTSDIR}/multimedia/libxine
PLIST_SUB+=	XINE=""
.else
CMAKE_ARGS+=	-DWITH_Xine:BOOL=OFF
PLIST_SUB+=	XINE="@comment "
.endif

.if ${PORT_OPTIONS:MZEITGEIST}
RUN_DEPENDS+=	zeitgeist-daemon:${PORTSDIR}/sysutils/zeitgeist
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
LIB_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

.if ${KDE4_PREFIX} != ${LOCALBASE}
PLIST_SUB+=	HACK=""
.else
PLIST_SUB+=	HACK="@comment "
post-extract:
	${REINPLACE_CMD} -e '/add_subdirectory.*hicolor/d' \
		${PATCH_WRKSRC}/pics/CMakeLists.txt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${PATCH_WRKSRC}/khelpcenter/infotree.cpp \
		${PATCH_WRKSRC}/kioslave/info/kde-info2html.conf \
		${PATCH_WRKSRC}/kioslave/man/kio_man.cpp \
		${PATCH_WRKSRC}/kioslave/man/man2html.cpp \
		${PATCH_WRKSRC}/cmake/modules/FindCLucene.cmake

.include <bsd.port.post.mk>
