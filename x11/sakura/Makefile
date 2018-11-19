# Created by: chinsan
# $FreeBSD$

PORTNAME=	sakura
PORTVERSION=	3.6.0
CATEGORIES=	x11 gnome
MASTER_SITES=	http://launchpadlibrarian.net/368320954/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE

LICENSE=	GPLv2

LIB_DEPENDS=	libgnutls.so:security/gnutls \
		libpcre2-8.so:devel/pcre2

BROKEN_powerpc64=	fails to build: sakura.c:1348: 'for' loop initial declaration used outside C99 mode

OPTIONS_DEFINE=	DOCS

USE_GNOME=	cairo gdkpixbuf2 vte3
USE_XORG=	x11
USES=		cmake pkgconfig gettext perl5 tar:bzip2
USE_PERL5=	build
LDFLAGS+=	-lintl

post-patch:
	@${REINPLACE_CMD} -e 's,share/man,man,g ; \
		/-O2/d ; \
		/FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
