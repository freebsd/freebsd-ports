# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.6
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim/ \
		SF/slim.berlios

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libpng.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		cmake jpeg pkgconfig
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xmu xorg-server xrandr \
		xrender xt
USE_RC_SUBR=	slim
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes \
	-DBUILD_SLIMLOCK=no \
	-DBUILD_SHARED_LIBS=yes

OPTIONS_DEFINE=		PAM UTF8 CONSOLEKIT
OPTIONS_DEFAULT=	PAM CONSOLEKIT

UTF8_DESC=	Support UTF-8 characters
CONSOLEKIT_DESC=Enable support for consolekit

PLIST_SUB+=	VERSION="${PORTVERSION}"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DUSE_PAM=yes
PLIST_SUB+=	PAM=""
.else
CMAKE_ARGS+=	-DUSE_PAM=no
PLIST_SUB+=	PAM="@comment "
.endif

.if ${PORT_OPTIONS:MUTF8}
# patch taken from slim-unicode in Arch User Repository
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-utf8
.endif

.if ${PORT_OPTIONS:MCONSOLEKIT}
CMAKE_ARGS+=	-DUSE_CONSOLEKIT=yes
LIB_DEPENDS+=	libck-connector.so:${PORTSDIR}/sysutils/consolekit
.else
CMAKE_ARGS+=	-DUSE_CONSOLEKIT=no
.endif

post-patch:
	@${CP} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/slim.1

post-install:
.	if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/slim.default
.	endif

.include <bsd.port.mk>
