# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gdm/Makefile,v 1.117 2008/03/22 04:21:52 mezz Exp $
#

PORTNAME=	gdm
PORTVERSION=	2.20.7
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 version of xdm display manager

BUILD_DEPENDS=	zenity:${PORTSDIR}/x11/zenity
LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit
RUN_DEPENDS=	zenity:${PORTSDIR}/x11/zenity \
		xrdb:${PORTSDIR}/x11/xrdb

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_XORG=	dmx dmxproto
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_RC_SUBR=	gdm
USE_GNOME_SUBR=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack intlhack gnomehier librsvg2 gnomedocutils \
		gnomeprefix
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"
CONFIGURE_ARGS=--with-console-kit=yes

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

GNOME_LOCALSTATEDIR=	/var

MAN1=		gdm.1

OPTIONS=	IPV6 "Enable IPv6 support" off \
		LOG_LIMIT "Limit ~/.xsession-errors size" on

.include <bsd.port.pre.mk>

.if exists(/usr/include/security/pam_misc.h)
PLIST_SUB+=	PAM_MISC=""
.else
PLIST_SUB+=	PAM_MISC="@comment "
.endif

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if defined(WITHOUT_LOG_LIMIT)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-daemon_slave.c
.endif

post-patch:
.if ( ${OSVERSION} > 600000 && ${OSVERSION} < 600006 ) || \
	( ${OSVERSION} < 503101 )
.for po in zh_CN.po
	@${REINPLACE_CMD} -e 's|%-|%|g' ${WRKSRC}/po/${po}
.endfor
.endif
	@${REINPLACE_CMD} -e 's|root:root|root:wheel|g' \
		${WRKSRC}/config/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|g' \
		${WRKSRC}/configure ${WRKSRC}/po/*.po ${WRKSRC}/gui/*.glade \
		${WRKSRC}/daemon/*.c ${WRKSRC}/docs/*/*.*
	@${REINPLACE_CMD} -e 's|/etc/gdm/gdm.conf|${PREFIX}/etc/gdm/gdm.conf|' \
		${WRKSRC}/docs/gdm.1

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	${INSTALL_DATA} ${WRKSRC}/config/gdm.conf-custom \
		${PREFIX}/etc/gdm/custom.conf.default
	@${MKDIR} ${PREFIX}/etc/gdm/Sessions
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
