PORTNAME=	vte
PORTVERSION=	0.28.2
PORTREVISION?=	3
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER?=	gnome@FreeBSD.org
COMMENT?=	Gtk 2 based terminal widget with accessibility and I18N support

USES+=		tar:xz

PORTSCOUT=	ignore:1

RUN_DEPENDS+=	${LOCALBASE}/libexec/gnome-pty-helper:x11-toolkits/gnome-pty-helper

USES+=		cpe gettext gmake gnome libtool localbase pathfix pkgconfig
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GNOME?=	gnomeprefix gtk20 intltool introspection:build
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS?=--disable-python \
		--disable-Bsymbolic \
		--disable-freetypetest \
		--disable-static \
		--with-gtk=2.0 \
		--enable-introspection \
		--disable-gnome-pty-helper

CPE_VENDOR=	nalin_dahyabhai

.include <bsd.port.mk>
