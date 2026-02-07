PORTNAME=	xcm
PORTVERSION=	0.5.4
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X Color Management tools

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/docs/COPYING

LIB_DEPENDS=	libXcm.so:x11/libXcm \
		libOyranos.so:graphics/oyranos

USE_GITHUB=	yes
GH_ACCOUNT=	oyranos-cms
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${PREFIX}/share/man
USES=		pkgconfig xorg
USE_XORG=	x11 xfixes xmu xt

# xcm should be added to XORG_MODULES at /usr/ports/Mk/bsd.xorg.mk
# and LIB_DEPENDS is replaced by the following line:
#USE_XORG=	xcm

PLIST_FILES=	bin/xcm bin/xcmedid bin/xcmevents bin/xcmhextobin \
		share/man/man1/xcm.1.gz \
		share/man/man1/xcmddc.1.gz share/man/man1/xcmedid.1.gz \
		share/man/man1/xcmevents.1.gz share/man/man1/xcmhextobin.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
