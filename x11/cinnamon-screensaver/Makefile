# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/x11/cinnamon-screensaver/Makefile 19704 2014-05-28 09:16:09Z gusi $

PORTNAME=	cinnamon-screensaver
PORTVERSION=	2.2.3
MASTER_SITES=	http://github.com/linuxmint/${PORTNAME}/archive/${PORTVERSION}.tar.gz?dummy=/
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		gnome-autogen.sh:${PORTSDIR}/devel/gnome-common
LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libcinnamon-desktop.so:${PORTSDIR}/x11/cinnamon-desktop \
		libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib
RUN_DEPENDS=	pam_helper:${PORTSDIR}/security/pam_helper \
		gsettings-desktop-schemas>=3.2.0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		${LOCALBASE}/lib/pam_gnome_keyring.so:${PORTSDIR}/security/gnome-keyring

USES=		gettext gmake libtool pathfix pkgconfig tar:xz
USE_XORG=	x11 xext xxf86vm xxf86misc xscrnsaver
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack libgnomekbd libxml2
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtoolize autoconf automake
PATHFIX_MAKEFILEIN=	Makefile.am
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pam-prefix=${PREFIX}/etc/pam.d \
		--without-systemd
INSTALL_TARGET=	install-strip

SUB_FILES+=	cinnamon-screensaver.pam

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/pam.d|${PREFIX}/etc/pam.d|g' \
		${WRKSRC}/src/gs-auth-pam.c
	@${REINPLACE_CMD} -e 's|find -m|find . -m|g' \
		${WRKSRC}/files/Makefile.in
#	@${REINPLACE_CMD} -e 's|@AUTH_SCHEME@|helper|g' \
#		${WRKSRC}/src/Makefile.in
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"/usr/local/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

post-install:
#	${CHOWN} root ${PREFIX}/libexec/gnome-screensaver-dialog
#	${CHMOD} +s ${PREFIX}/libexec/gnome-screensaver-dialog
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver
	${RM} -fr ${STAGEDIR}${PREFIX}/etc/pam.d/pam.d/

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
