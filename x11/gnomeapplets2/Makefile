# New ports collection makefile for:	gnomeapplets2
# Date created:				26th May 2000
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomeapplets2
PORTVERSION=	2.8.2
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-applets/2.8
DISTNAME=	gnome-applets-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Applets components for the Gnome 2 Desktop Environment

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2 \
		xklavier.8:${PORTSDIR}/x11/libxklavier

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNOME_DESKTOP_VERSION=2
USE_GNOME=	gnomehier gnomeprefix gnomehack intlhack gnomepanel \
		gstreamerplugins gail
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		FREEBSD_SYS=${FREEBSD_SYS}

GCONF_SCHEMAS=	charpick.schemas drivemount.schemas geyes.schemas gkb.schemas \
		gswitchit.schemas gtik.schemas gweather.schemas \
		mailcheck.schemas mini-commander.schemas mixer.schemas \
		modemlights.schemas multiload.schemas stickynotes.schemas

FREEBSD_SYS?=	/usr/src/sys

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -fPIC"
PLIST_SUB=	BATTERY="@comment "
.else
GCONF_SCHEMAS+=	battstat.schemas
PLIST_SUB=	BATTERY=""

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "              W  A  R  N  I  N  G"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} "* gnomeapplets2 requires that you have your kernel  *"
	@${ECHO_MSG} "* sources installed. If your kernel sources         *"
	@${ECHO_MSG} "* are somewhere other than /usr/src/sys, you        *"
	@${ECHO_MSG} "* may set the FREEBSD_SYS variable to the           *"
	@${ECHO_MSG} "* correct path.                                     *"
	@${ECHO_MSG} "*****************************************************"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/icons/hicolor|(prefix)/share/icons/hicolor|g' \
		${WRKSRC}/gswitchit/Makefile.in

.include <bsd.port.post.mk>
