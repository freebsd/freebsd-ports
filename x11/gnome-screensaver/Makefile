# New ports collection makefile for:	gnome-screensaver
# Date created:		09 June 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver/Makefile,v 1.36 2006/04/13 07:52:40 bland Exp $
#

PORTNAME=	gnome-screensaver
PORTVERSION=	2.14.1
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	dbus-1.2:${PORTSDIR}/devel/dbus
RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomemenus
CONFIGURE_ARGS=	--disable-pam \
		--with-gdm-config=${X11BASE}/etc/gdm/custom.conf \
		--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${X11BASE}/bin/xscreensaver-hacks
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	gnome-screensaver.schemas

PLIST=	${WRKDIR}/pkg-plist

XSCREENSAVER_DIR=	${X11BASE}/share/xscreensaver/config

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.X
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/configure

pre-install:
	@${CP} ${.CURDIR}/pkg-plist ${PLIST}
	@cd ${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
		${SED} -e 's:^:share/gnome/gnome-screensaver/themes/xscreensaver/:' | \
		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
	@${ECHO_CMD} @dirrm share/gnome/gnome-screensaver/themes/xscreensaver >> ${PLIST}
	@${ECHO_CMD} @dirrm share/gnome/gnome-screensaver/themes >> ${PLIST}
	@${ECHO_CMD} @dirrm share/gnome/gnome-screensaver >> ${PLIST}

post-install:
	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog
	${MKDIR} ${PREFIX}/share/gnome/gnome-screensaver/themes/xscreensaver
	cd ${PREFIX}/share/gnome/gnome-screensaver/themes/xscreensaver && \
		${FIND} -s ${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh

.include <bsd.port.post.mk>
