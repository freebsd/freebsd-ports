# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.5
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.berlios.de/pub/slim/ \
		SF/slim.berlios

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		ck-connector:${PORTSDIR}/sysutils/consolekit \
		expat:${PORTSDIR}/textproc/expat2 \
		xcb:${PORTSDIR}/x11/libxcb \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

USES=		cmake pkgconfig
USE_XORG=	ice sm x11 xau xdmcp xext xft xmu xorg-server xrender xt
USE_RC_SUBR=	slim
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes

MAN1=		slim.1

OPTIONS_DEFINE=	PAM

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
	@if [ ! -f ${PREFIX}/etc/slim.conf ]; then \
		${CP} ${PREFIX}/etc/slim.conf.sample ${PREFIX}/etc/slim.conf ; \
	fi
.	if ${PORT_OPTIONS:MPAM}
	@${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/slim.default
	@if [ ! -f ${PREFIX}/etc/pam.d/slim ]; then \
		${CP} ${PREFIX}/etc/pam.d/slim.default ${PREFIX}/etc/pam.d/slim ; \
	fi
.	endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
