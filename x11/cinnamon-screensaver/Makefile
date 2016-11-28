# Created by: Gustau Perez i Querol <gustau.perez@gmail.com>
# $FreeBSD$

PORTNAME=	cinnamon-screensaver
PORTVERSION=	2.4.1
CATEGORIES=	x11 gnome
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME screen saver and locker

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		gnome-autogen.sh:devel/gnome-common
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libcinnamon-desktop.so:x11/cinnamon-desktop \
		libdbus-glib-1.so:devel/dbus-glib
RUN_DEPENDS=	pam_helper:security/pam_helper \
		gsettings-desktop-schemas>=3.2.0:devel/gsettings-desktop-schemas \
		gnome-keyring>=0:security/gnome-keyring

USES=		autoreconf:build gettext gmake libtool pathfix pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint
USE_XORG=	x11 xext xxf86vm xxf86misc xscrnsaver
USE_GNOME=	gnomedesktop3 gnomeprefix intlhack intlhack libgnomekbd libxml2
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
CFLAGS=		-I${LOCALBASE}/include -Wno-error=format-nonliteral
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
	@${ECHO} "#define PASSWD_HELPER_PROGRAM \"/usr/local/bin/pam_helper\"" \
		>> ${WRKSRC}/config.h.in

post-install:
	${INSTALL_DATA} ${WRKDIR}/cinnamon-screensaver.pam \
		${STAGEDIR}${PREFIX}/etc/pam.d/cinnamon-screensaver
	${RM} -r ${STAGEDIR}${PREFIX}/etc/pam.d/pam.d/

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
