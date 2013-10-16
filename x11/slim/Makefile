# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.5
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim/ \
		SF/slim.berlios

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LICENSE=	GPLv2

LIB_DEPENDS=	libdbus-1.so:${PORTSDIR}/devel/dbus \
		libpthread-stubs.so:${PORTSDIR}/devel/libpthread-stubs \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libck-connector.so:${PORTSDIR}/sysutils/consolekit \
		libexpat.so:${PORTSDIR}/textproc/expat2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

USES=		cmake pkgconfig
USE_XORG=	ice sm x11 xau xcb xdmcp xext xft xmu xorg-server xrender xt
USE_RC_SUBR=	slim
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes

OPTIONS_DEFINE=		PAM
OPTIONS_DEFAULT=	PAM

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPAM}
CMAKE_ARGS+=	-DUSE_PAM=yes
PLIST_SUB+=	PAM=""
.else
CMAKE_ARGS+=	-DUSE_PAM=no
PLIST_SUB+=	PAM="@comment "
.endif

post-patch:
	@${CP} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|' \
		-e 's|/etc|${PREFIX}/etc|' \
		-e 's|share/man|man|' \
		-e 's|slim.conf|slim.conf.sample|' \
		-e '/systemd/d' \
		${WRKSRC}/CMakeLists.txt

post-install:
.	if ${PORT_OPTIONS:MPAM}
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/slim.default
.	endif

.include <bsd.port.mk>
