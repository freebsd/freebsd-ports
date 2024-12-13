PORTNAME=	xseticon
PORTVERSION=	0.1
DISTVERSIONSUFFIX=	+bzr14
CATEGORIES=	x11
MASTER_SITES=	${WWW}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Set window icon for any given X11 window
WWW=		http://www.leonerd.org.uk/code/xseticon/

LICENSE=	GPLv2+

LIB_DEPENDS=	libgd.so:graphics/gd

USES=		gmake gnome pkgconfig xorg
USE_GNOME=	glib20
USE_XORG=	x11 xmu

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's,gcc,$${CC} $${CFLAGS},' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
