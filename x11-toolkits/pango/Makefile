# New ports collection makefile for:   pango
# Date Created:			18 July 2000
# Whom:				Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pango
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_GNOME:S,%SUBDIR%,sources/${PORTNAME}/1.4,} \
		ftp://ftp.gtk.org/pub/gtk/v2.3/
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	An open-source framework for the layout and rendering of i18n text

BUILD_DEPENDS=	freetype-config:${PORTSDIR}/print/freetype2
LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft
RUN_DEPENDS=	${FONTSCALE}:${X_FONTS_TTF_PORT} \
		${FONTENCOD}:${X_FONTS_ENCODINGS_PORT}

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomehack glib20
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
FONTENCOD=	${X11BASE}/lib/X11/fonts/encodings/tcvn-0.enc

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

