# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	verve-plugin
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/src/panel-plugins/${PKGNAMEPREFIX}${PORTNAME}/${PORTVERSION:R}
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Command line plugin for the Xfce Desktop

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre.so:devel/pcre \
		libdbus-glib-1.so:devel/dbus-glib \
		libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gettext-tools gmake gnome libtool pkgconfig tar:bzip2 xfce
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 intlhack intltool pango
USE_XFCE=	panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-dbus

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
