# New ports collection makefile for:   gdm2
# Date created:        20 May 2002
# Whom:                Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gdm2
PORTVERSION=	2.4.0.0
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=		pre-gnome2/releases/gnome-2.0-desktop-rc2
DISTNAME=	gdm-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2	

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

GDMDIR?=	${PREFIX}/etc/gdm

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
IS_INTERACTIVE=	yes
.endif

.if !defined(BATCH) && !defined(PACKAGE_BUILDING)
pre-fetch:
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
