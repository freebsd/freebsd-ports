PORTNAME=	libmatekbd
PORTVERSION=	1.26.0
PORTREVISION=	2
CATEGORIES=	x11 mate
MASTER_SITES=	MATE
DIST_SUBDIR=	mate

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	MATE keyboard shared library
WWW=		https://mate-desktop.org/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxklavier.so:x11/libxklavier

PORTSCOUT=	limitw:1,even

USES=		gettext gmake gnome libtool localbase pathfix \
		pkgconfig tar:xz xorg
USE_GNOME=	cairo gtk30 intltool introspection:build
USE_XORG=	x11
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

GLIB_SCHEMAS=	org.mate.peripherals-keyboard-xkb.gschema.xml

.include <bsd.port.mk>
