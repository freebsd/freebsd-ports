# New ports collection makefile for:	gnome-screensaver
# Date created:		09 June 2005
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11/gnome-screensaver/Makefile,v 1.58 2006/10/07 19:45:39 marcus Exp $
#

PORTNAME=	gnome-screensaver
PORTVERSION=	2.16.3
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	xscreensaver-gl-helper:${PORTSDIR}/x11/xscreensaver-gnome-hacks

USE_BZIP2=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui gnomemenus
CONFIGURE_ARGS=	--with-gdm-config=${LOCALBASE}/etc/gdm/custom.conf \
		--with-xscreensaverdir=${XSCREENSAVER_DIR} \
		--with-xscreensaverhackdir=${LOCALBASE}/bin/xscreensaver-hacks
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
GCONF_SCHEMAS=	gnome-screensaver.schemas

PLIST=	${WRKDIR}/pkg-plist

XSCREENSAVER_DIR=	${LOCALBASE}/share/xscreensaver/config
SCREENSAVER_DIR=	share/gnome/applications/screensavers

XSCREENSAVER_EXCLUDE=	"(popsquares.xml)"

OPTIONS=	PAM "Pluggable Authentication Module support" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.X
.endif

.if !defined(WITH_PAM)
CONFIGURE_ARGS+=	--disable-pam
.endif

pre-install:
	@${CP} ${.CURDIR}/pkg-plist ${PLIST}
	@cd ${XSCREENSAVER_DIR} && ${FIND} -s * -maxdepth 1 -type f -name "*.xml" | \
		${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
		${SED} -e 's:^:${SCREENSAVER_DIR}/:' | \
		${SED} -e 's:[.]xml$$:.desktop:' >> ${PLIST}
	@${ECHO_CMD} @dirrm ${SCREENSAVER_DIR} >> ${PLIST}

post-install:
	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog
	cd ${PREFIX}/${SCREENSAVER_DIR} && \
		${FIND} -s ${XSCREENSAVER_DIR} -maxdepth 1 -type f -name "*.xml" | \
			${GREP} -Ev ${XSCREENSAVER_EXCLUDE} | \
			${XARGS} ${WRKSRC}/data/migrate-xscreensaver-config.sh

.include <bsd.port.post.mk>
