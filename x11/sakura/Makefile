# Created by: chinsan

PORTNAME=	sakura
PORTVERSION=	3.8.2
CATEGORIES=	x11 gnome
MASTER_SITES=	http://launchpadlibrarian.net/535130180/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE

LICENSE=	GPLv2

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2

USES=		cmake gnome pkgconfig gettext perl5 tar:bz2 xorg

OPTIONS_DEFINE=	DOCS

USE_GNOME=	cairo gdkpixbuf2 vte3
USE_XORG=	x11
USE_PERL5=	build
LDFLAGS+=	-lintl

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,g ; \
		/-O2/d ; \
		/FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
