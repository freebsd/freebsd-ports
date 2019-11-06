# Created by: hendrik@scholz.net
# $FreeBSD$

PORTNAME=	fluxconf
PORTVERSION=	0.9.9
PORTREVISION=	10
CATEGORIES=	x11-wm
MASTER_SITES=	http://devaux.fabien.free.fr/flux/

MAINTAINER=	alfredoj69@gmail.com
COMMENT=	Fluxbox window manager configuration program

BROKEN=		unfetchable

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gnome pkgconfig

USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
CFLAGS+=	-Wno-error
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

PORTDOCS=	fluxconf.png fluxkeys.png fluxmenu.png index.html
PLIST_FILES=	bin/fluxbare bin/fluxconf bin/fluxkeys bin/fluxmenu

OPTIONS_DEFINE=	DOCS NLS

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_PLIST_FILES=	share/locale/fi/LC_MESSAGES/fluxconf.mo \
			share/locale/fr/LC_MESSAGES/fluxconf.mo

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in fluxconf.png fluxkeys.png fluxmenu.png index.html
	${INSTALL_DATA} ${WRKSRC}/docs/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
