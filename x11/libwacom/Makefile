# Created by: johalun0@gmail.com
# $FreeBSD$

PORTNAME=	libwacom
DISTVERSIONPREFIX=libwacom-
DISTVERSION=	1.2
CATEGORIES=	x11

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES+=	c70cb56f1670.patch:-p1 # https://github.com/linuxwacom/libwacom/pull/216

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Adds tablet support to libinput

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgudev-1.0.so:devel/libgudev

USE_GITHUB=	yes
GH_ACCOUNT=	linuxwacom

USES=		autoreconf gettext-runtime gmake gnome libtool \
		pkgconfig pathfix tar:bzip2
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's/-printf "%P\\n"/-print0 | xargs -0 basename/' \
		${WRKSRC}/data/Makefile.am ${WRKSRC}/data/layouts/Makefile.am

.include <bsd.port.mk>
