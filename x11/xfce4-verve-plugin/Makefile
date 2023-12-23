PORTNAME=	verve-plugin
PORTVERSION=	2.0.3
PORTREVISION=	2
CATEGORIES=	x11 xfce
MASTER_SITES=	XFCE/panel-plugins
PKGNAMEPREFIX=	xfce4-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${DISTVERSIONFULL}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Command line plugin for the Xfce Desktop
WWW=		https://goodies.xfce.org/projects/panel-plugins/xfce4-verve-plugin

LICENSE=	GPLv2

LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libharfbuzz.so:print/harfbuzz

USES=		compiler:c11 gettext-tools gmake gnome libtool pkgconfig \
		tar:bzip2 xfce
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk30 intltool pango
USE_XFCE=	libmenu panel

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-dbus

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext-runtime

.include <bsd.port.mk>
