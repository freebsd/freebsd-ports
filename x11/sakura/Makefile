# Created by: chinsan
# $FreeBSD$

PORTNAME=	sakura
PORTVERSION=	3.4.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://launchpadlibrarian.net/301803318/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE

LIB_DEPENDS=	libgnutls.so:security/gnutls

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_GNOME=	cairo gdkpixbuf2 vte3
USE_XORG=	x11
USES=		cmake pkgconfig gettext tar:bzip2
LDFLAGS+=	-lintl

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,g ; \
		/-O2/d ; \
		/FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
