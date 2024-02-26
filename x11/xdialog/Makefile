PORTNAME=	xdialog
PORTVERSION=	2.3.1
PORTREVISION=	11
CATEGORIES=	x11
MASTER_SITES=	http://xdialog.free.fr/
DISTNAME=	${PORTNAME:S/x/X/}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Drop in replacement for the "dialog" or "cdialog" programs
WWW=		http://xdialog.free.fr/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz
LIB_DEPENDS+=	libfontconfig.so:x11-fonts/fontconfig
LIB_DEPENDS+=	libfreetype.so:print/freetype2

USES=		gnome localbase pkgconfig tar:bzip2
USE_GNOME=	cairo gdkpixbuf2 gtk20
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--with-gtk2

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|m4 lib src|m4 src|g ; \
		 s|-I../lib||g ; \
		 s|-L../lib -lgetopt||g ; \
		 s| install-docDATA||g'
	@${REINPLACE_CMD} -e 's,Xdialog\\-%%version%%,xdialog,' \
		${WRKSRC}/doc/Xdialog.man

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}${DESKTOPDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps
	${INSTALL_DATA} ${PATCHDIR}/bsdconfig.desktop ${STAGEDIR}${DESKTOPDIR}
	${INSTALL_DATA} ${PATCHDIR}/bsdconfig-48.png ${STAGEDIR}${PREFIX}/share/icons/hicolor/48x48/apps/bsdconfig.png

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/samples
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.png ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/* ${STAGEDIR}${DOCSDIR}/samples

.include <bsd.port.mk>
