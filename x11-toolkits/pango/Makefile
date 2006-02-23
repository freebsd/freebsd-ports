# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/x11-toolkits/pango/Makefile,v 1.43 2005/10/03 15:42:47 ahze Exp $
#

PORTNAME=	pango
PORTVERSION=	1.10.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/${PORTNAME}/1.10,} \
		ftp://ftp.gtk.org/pub/gtk/v2.7/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source framework for the layout and rendering of i18n text

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft \
		cairo.2:${PORTSDIR}/graphics/cairo
RUN_DEPENDS=	${FONTSCALE}:${X_FONTS_TTF_PORT} \
		${FONTENCOD}:${X_FONTS_ENCODINGS_PORT}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_AUTOTOOLS=  libtool:15
USE_GNOME=	gnomehack glib20 ltverhack
CONFIGURE_ARGS=	--with-qt=no \
		--with-html-dir=${PREFIX}/share/doc \
		--enable-static
PKGINSTALL=	${WRKDIR}/pkg-install
# Hmm.. tough one.  Found this one when I had graphics/hdf installed
# (which installs glist.h) which is picked up before the glib-2.0
# stuff, with Bad Results[tm]
#
GLIB2_CFLAGS=	`pkg-config glib-2.0 --cflags`
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype2 \
			${GLIB2_CFLAGS} -I${LOCALBASE}/include \
			-I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
PLIST_SUB=	VERSION="1.4.0"

FONTSCALE=	${X11BASE}/lib/X11/fonts/TTF/luximb.ttf
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/encodings.dir

MAN1=		pango-querymodules.1

post-patch:
	@${FIND} ${WRKSRC}/pango/opentype -name "*.[ch]" | ${XARGS} \
		${REINPLACE_CMD} -e 's|internal/tterrors\.h|fterrors.h| ; \
		s|TT_Err_|FT_Err_|g'
post-install:
	@${SED} -e 's|%%X11BASE%%|${X11BASE}|' < ${FILESDIR}/pkg-install.in \
		> ${PKGINSTALL}
.if !defined(PACKAGE_BUILDING)
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
