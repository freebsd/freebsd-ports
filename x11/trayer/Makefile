PORTNAME=	trayer
PORTVERSION=	1.1.8
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	2
CATEGORIES=	x11

MAINTAINER=	madpilot@FreeBSD.org
COMMENT=	Lightweight GTK2-based systray for UNIX desktop
WWW=		https://github.com/sargon/trayer-srg

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		gmake gnome iconv pkgconfig xorg
USE_GITHUB=	yes
GH_ACCOUNT=	sargon
GH_PROJECT=	${PORTNAME}-srg
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk20 pango
USE_XORG=	x11 xmu

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}"

PLIST_FILES=	bin/trayer \
		share/man/man1/trayer.1.gz
PORTDOCS=	CHANGELOG CREDITS README

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
