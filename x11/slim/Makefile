# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.4
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://slim.berlios.de/releases/

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

USE_CMAKE=	yes
USE_XORG=	ice sm x11 xau xdmcp xext xft xmu xorg-server xrender xt
USE_PKGCONFIG=	build
USE_RC_SUBR=	slim
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes

MAN1=		slim.1

OPTIONS=	PAM "Use pam" off

.include <bsd.port.pre.mk>

.if defined(WITH_PAM)
CMAKE_ARGS+=	-DUSE_PAM=yes
PLIST_SUB+=	PAM=""
.else
CMAKE_ARGS+=	-DUSE_PAM=no
PLIST_SUB+=	PAM="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e 's|"/etc"|"${PREFIX}/etc"|' \
	    -e 's|slim.conf|slim.conf.sample|' \
	    -e 's|set(MANDIR "$${CMAKE_INSTALL_PREFIX}/share/man")|set(MANDIR "${PREFIX}/man")|' \
	    ${WRKSRC}/CMakeLists.txt
	@${MV} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|std::snprintf|snprintf|' ${WRKSRC}/Ck.cpp

# Fix a previous bad install - Ok to remove at version 1.3.5 or later
pre-install:
	@${RM} -f ${LOCALBASE}/share/man/man1/slim.1
	@${RMDIR} ${LOCALBASE}/share/man/man1 2>/dev/null || true
	@${RMDIR} ${LOCALBASE}/share/man 2>/dev/null || true

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	@if [ ! -f ${PREFIX}/etc/slim.conf ]; then \
		${CP} ${PREFIX}/etc/slim.conf.sample ${PREFIX}/etc/slim.conf ; \
	fi
.	if defined(WITH_PAM)
	@${INSTALL_DATA} ${FILESDIR}/pam.conf ${PREFIX}/etc/pam.d/slim.default
	@if [ ! -f ${PREFIX}/etc/pam.d/slim ]; then \
		${CP} ${PREFIX}/etc/pam.d/slim.default ${PREFIX}/etc/pam.d/slim ; \
	fi
.	endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
