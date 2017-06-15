# Created by: johalun0@gmail.com
# $FreeBSD$

PORTNAME=	libwacom
PORTVERSION=	0.23
CATEGORIES=	x11
MASTER_SITES=	https://sourceforge.net/projects/linuxwacom/files/libwacom/

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

USES=		gettext-runtime gmake libtool localbase pkgconfig \
		pathfix tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
