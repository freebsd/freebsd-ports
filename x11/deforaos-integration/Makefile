PORTNAME=	integration
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Integration/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Integration-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop integration
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/Desktop/Locker.h:x11/deforaos-locker \
		${LOCALBASE}/include/Desktop/Keyboard.h:x11/deforaos-keyboard \
		${LOCALBASE}/include/Desktop/Player.h:multimedia/deforaos-player \
		${LOCALBASE}/include/Desktop/Phone.h:comms/deforaos-phone
LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libMailer.so.0:mail/deforaos-mailer \
		libNotes.so.0:deskutils/deforaos-notes \
		libpurple.so:net-im/libpurple \
		libsofia-sip-ua.so:net/sofia-sip \
		libpulse.so:audio/pulseaudio \
		libPanel.so.0:x11-wm/deforaos-panel \
		libTodo.so.0:deskutils/deforaos-todo \
		libharfbuzz.so:print/harfbuzz \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus
RUN_DEPENDS=	${LOCALBASE}/bin/surfer:www/deforaos-surfer \
		${LOCALBASE}/bin/metacity:x11-wm/metacity \
		gnome-icon-theme>=0:misc/gnome-icon-theme

USES=		desktop-file-utils gnome pkgconfig xorg

USE_GNOME=	cairo gdkpixbuf gtk30
USE_LDCONFIG=	yes
USE_XORG=	x11

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/modem/*.so \
	${STAGEDIR}${PREFIX}/lib/Phone/plugins/*.so \
	${STAGEDIR}${PREFIX}/lib/Locker/plugins/*.so \
	${STAGEDIR}${PREFIX}/lib/Mailer/plugins/*.so \
	${STAGEDIR}${PREFIX}/lib/Panel/applets/*.so

.include <bsd.port.mk>
