# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightdm-gtk-greeter
PORTVERSION=	2.0.2
CATEGORIES=	x11
MASTER_SITES=	https://launchpad.net/${PORTNAME}/${PORTVERSION:R}/${PORTVERSION}/+download/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK+ greeter for LightDM

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm

USES=		gettext gmake localbase pkgconfig xfce
GNU_CONFIGURE=	yes
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XFCE=	libexo
USE_XORG=	x11

.include <bsd.port.mk>
