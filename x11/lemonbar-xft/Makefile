PORTNAME=	lemonbar-xft
DISTVERSION=	g20201213
CATEGORIES=	x11

MAINTAINER=	DtxdF@riseup.net
COMMENT=	Fork of lemonbar with support for Xft (fontconfig typefaces)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		gmake localbase:ldflags perl5 xorg

USE_XORG=	xcb xft x11
USE_PERL5=	build

CONFLICTS_INSTALL=	lemonbar

PLIST_FILES=	bin/lemonbar \
		man/man1/lemonbar.1.gz

USE_GITLAB=	yes
GL_ACCOUNT=	protesilaos
GL_COMMIT=	0042efd2ec1477ab96eb044ebba72a10aefff21f

.include <bsd.port.mk>
