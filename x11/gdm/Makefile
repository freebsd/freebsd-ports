# New ports collection makefile for:   gdm
# Date created:        12 September 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm
PORTVERSION=	2.2.5.5
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		sources/gdm/2.2
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libglade gdkpixbuf
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

GDMDIR?=	${PREFIX}/etc/gdm

.include <bsd.port.pre.mk>

.if exists(/usr/include/security/pam_misc.h)
PLIST_SUB=      PAM_MISC=""
.else
PLIST_SUB=      PAM_MISC="@comment "
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-fetch:
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${CHOWN} -R gdm:gdm ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.else
	@${CHOWN} -R 92:92 ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.endif
	@${CHMOD} 0750 ${PREFIX}/share/gnome/gdm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
