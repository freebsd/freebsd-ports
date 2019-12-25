# Created by: Eric Turgeon <ericbsd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	slick-greeter
PORTVERSION=	1.3.0
CATEGORIES=	x11

MAINTAINER=	ericbsd@FreeBSD.org
COMMENT=	A slick-looking LightDM greeter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm \
		libcanberra-gtk3.so:audio/libcanberra-gtk3
BUILD_DEPENDS=	valac:lang/vala

USES=		autoreconf gettext gmake gnome localbase pkgconfig xorg
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool

USE_XORG=	x11

USE_GITHUB=	yes
GH_ACCOUNT=	linuxmint

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

GLIB_SCHEMAS=	x.dm.slick-greeter.gschema.xml

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
