# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/x11/gnome-screensaver3/Makefile 18580 2013-06-23 08:40:31Z kwm $

PORTNAME=	gnome-screensaver
PORTVERSION=	3.6.1
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pam_helper:${PORTSDIR}/security/pam_helper \
		gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/lib/pam_gnome_keyring.so:${PORTSDIR}/security/gnome-keyring

USES=		gettext gmake pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_XORG=	x11 xext xxf86vm xxf86misc xscrnsaver
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack libgnomekbd
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pam-prefix=${PREFIX}/etc/pam.d \
		--without-systemd

SUB_FILES+=	gnome-screensaver.pam

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
	@${REINPLACE_CMD} -e 's|@AUTH_SCHEME@|helper|g' \
		${WRKSRC}/src/Makefile.in
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"/usr/local/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

post-install:
#	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
#	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog
	${INSTALL_DATA} ${WRKDIR}/gnome-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/gnome-screensaver

.include <bsd.port.mk>
