PORTNAME=	fbdesk
PORTVERSION=	1.4.1
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://fluxbox.sourceforge.net/download/ \
		GENTOO

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fluxbox utility to create and manage icons on the desktop
WWW=		https://fluxbox.sourceforge.net/fbdesk/

LICENSE=	MIT

LIB_DEPENDS=	libpng.so:graphics/png \
		libImlib2.so:graphics/imlib2

USES=		pkgconfig xorg
USE_CXXSTD=	c++14
USE_XORG=	xext xft xpm xrender

GNU_CONFIGURE=	yes

PORTDOCS=	ChangeLog INSTALL README

PLIST_FILES=	bin/fbdesk

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
