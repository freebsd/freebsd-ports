# New ports collection makefile for:   gdm
# Date created:        12 September 2000
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm
PORTVERSION=	2.2.5.4
PORTREVISION=	2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		stable/sources/gdm

MAINTAINER=	gnome@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

GDMDIR?=	${PREFIX}/etc/gdm

pre-fetch:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
	@${INSTALL_SCRIPT} ${WRKSRC}/config/gnomerc ${PREFIX}/etc/gdm
.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
	@${CHOWN} -R gdm:gdm ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.else
	@${CHOWN} -R 91:91 ${PREFIX}/share/gnome/gdm ${PREFIX}/etc/gdm
.endif
	@${CHMOD} 0750 ${PREFIX}/share/gnome/gdm
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
