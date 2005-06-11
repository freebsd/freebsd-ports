# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm
PORTVERSION=	2.8.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		sources/${PORTNAME:S/2$//}/2.8
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME 2 version of xdm display manager

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_RC_SUBR=	gdm.sh
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack gnomehier libgnomeui librsvg2
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GDMDIR?=	${PREFIX}/etc/gdm
PKGMESSAGE=	${WRKDIR}/pkg-message

MAN1=		gdm.1

OPTIONS=	IPV6 "Enable IPv6 support (This disables IPv4 support)" off

.include <bsd.port.pre.mk>

.if exists(/usr/include/security/pam_misc.h)
PLIST_SUB+=	PAM_MISC=""
.else
PLIST_SUB+=	PAM_MISC="@comment "
.endif

.if defined(WITH_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

post-patch:
.if ( ${OSVERSION} > 600000 && ${OSVERSION} < 600006 ) || \
	( ${OSVERSION} < 503101 )
.for po in zh_CN.po
	@${REINPLACE_CMD} -e 's|%-|%|g' ${WRKSRC}/po/${po}
.endfor
.endif

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${MKDIR} ${PREFIX}/etc/gdm/Sessions
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${PKGDIR}/pkg-message \
		| /usr/bin/fmt 75 79 > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
