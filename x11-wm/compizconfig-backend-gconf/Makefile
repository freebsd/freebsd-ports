# Created by: Robert Noland <rnoland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	compizconfig-backend-gconf
PORTVERSION=	0.8.8
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://releases.compiz.org/${PORTVERSION}/

MAINTAINER=	freebsd-ports@dan.me.uk
COMMENT=	GConf backend for CompizConfig

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/compiz.pc:x11-wm/compiz
LIB_DEPENDS=	libcompizconfig.so:x11-wm/libcompizconfig \
		libstartup-notification-1.so:x11/startup-notification

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake gnome libtool:keepla pathfix pkgconfig tar:bzip2 xorg
USE_GNOME=	gconf2 glib20 libxslt
USE_LDCONFIG=	yes
USE_XORG=	ice sm x11 xcomposite xdamage xext xfixes xinerama xrandr

post-patch:
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|'	\
		${WRKSRC}/settings-backend/gconf.c	\

.include <bsd.port.mk>
