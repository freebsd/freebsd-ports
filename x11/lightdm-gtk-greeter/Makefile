# Created by: Ben Woods <woodsb02@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lightdm-gtk-greeter
PORTVERSION=	2.0.8
CATEGORIES=	x11
MASTER_SITES=	https://github.com/Xubuntu/${PORTNAME}/releases/download/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	GTK+ greeter for LightDM

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	xdt-csource:devel/xfce4-dev-tools
LIB_DEPENDS=	liblightdm-gobject-1.so:x11/lightdm

USES=		gettext gmake gnome localbase pkgconfig xorg
USE_CSTD=	c99
USE_GNOME=	cairo gdkpixbuf2 gtk30 intltool
USE_XORG=	x11

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	(cd ${STAGEDIR}${PREFIX}/etc/lightdm && ${MV} lightdm-gtk-greeter.conf \
		lightdm-gtk-greeter.conf.sample)

.include <bsd.port.mk>
