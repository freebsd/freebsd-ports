PORTNAME=	libfakekey
DISTVERSION=	0.3
CATEGORIES=	x11 kde
MASTER_SITES=	https://git.yoctoproject.org/cgit/cgit.cgi/${PORTNAME}/snapshot/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	X virtual keyboard library
WWW=		https://www.yoctoproject.org/tools-resources/projects/matchbox

LICENSE=	LGPL20+

USES=		autoreconf libtool pathfix pkgconfig xorg
USE_XORG=	x11 xtst
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--disable-static
INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC} && ${SETENV} NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
