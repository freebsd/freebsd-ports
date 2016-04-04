# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.6
PORTREVISION=	12
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim/ \
		SF/slim.berlios

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LICENSE=	GPLv2

LIB_DEPENDS=	libpthread-stubs.so:devel/libpthread-stubs \
		libpng.so:graphics/png \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

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
OPTIONS_SUB=	yes

UTF8_DESC=	Support UTF-8 characters
CONSOLEKIT_DESC=Enable support for consolekit

PLIST_SUB+=	VERSION="${PORTVERSION}"

PAM_CMAKE_ON=	-DUSE_PAM=yes
PAM_CMAKE_OFF=	-DUSE_PAM=no

# patch taken from slim-unicode in Arch User Repository
UTF8_EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-utf8

CONSOLEKIT_CMAKE_ON=	-DUSE_CONSOLEKIT=yes
CONSOLEKIT_LIB_DEPENDS=	libck-connector.so:sysutils/consolekit
CONSOLEKIT_CMAKE_OFF=	-DUSE_CONSOLEKIT=no

post-patch:
	@${CP} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/slim.1

post-install-PAM-on:
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/slim.sample

.include <bsd.port.mk>
