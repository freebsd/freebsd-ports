PORTNAME=	deforaos-integration
PORTVERSION=	0.1.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Integration/
DISTNAME=	Integration-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop integration
WWW=		https://www.defora.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${LOCALBASE}/bin/surfer:www/deforaos-surfer \
				${LOCALBASE}/bin/metacity:x11-wm/metacity \
				gnome-icon-theme>=0:misc/gnome-icon-theme
BUILD_DEPENDS=	${LOCALBASE}/include/Desktop/Locker.h:x11/deforaos-locker \
				${LOCALBASE}/include/Desktop/Keyboard.h:x11/deforaos-keyboard \
				${LOCALBASE}/include/Desktop/Player.h:multimedia/deforaos-player \
				${LOCALBASE}/include/Desktop/Phone.h:comms/deforaos-phone
LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libpurple.so:net-im/libpurple \
		libsofia-sip-ua.so:net/sofia-sip \
		libpulse.so:audio/pulseaudio \
		libPanel.so.0:x11-wm/deforaos-panel \
		libharfbuzz.so:print/harfbuzz \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus

USES=		gnome pkgconfig xorg desktop-file-utils

USE_GNOME=	gtk30 cairo gdkpixbuf2
USE_XORG=	x11
USE_LDCONFIG=	yes
#MAKE_ARGS+=	PREFIX=${PREFIX}
#MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/modem/*.so \
	${STAGEDIR}${PREFIX}/lib/Phone/plugins/*.so \
	${STAGEDIR}${PREFIX}/lib/Locker/plugins/*.so \
	${STAGEDIR}${PREFIX}/lib/Panel/applets/*.so

.include <bsd.port.mk>
