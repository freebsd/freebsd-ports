# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm2
PORTVERSION=	2.4.0.12
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		sources/${PORTNAME:S/2$//}/2.4
DISTNAME=	gdm-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomehier
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

GDMDIR?=	${PREFIX}/etc/gdm

.include <bsd.port.pre.mk>

.if exists(/usr/include/security/pam_misc.h)
PLIST_SUB=	PAM_MISC=""
.else
PLIST_SUB=	PAM_MISC="@comment "
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-fetch:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-extract:
	@${SED} -e "s,%%PREFIX%%,${PREFIX},g" \
		${FILESDIR}/gdm.sh.sample > ${WRKSRC}/gdm.sh.sample

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/gdm.sh.sample ${PREFIX}/etc/rc.d
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${CHOWN} -R gdm:gdm ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.else
	@${CHOWN} -R 92:92 ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.endif
	@${CHMOD} 0750 ${PREFIX}/share/gnome/gdm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
