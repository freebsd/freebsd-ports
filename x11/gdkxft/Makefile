# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gdkxft
PORTVERSION=	1.5
PORTREVISION=	10
CATEGORIES=	x11
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-aliased font support for gtk+

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libXft.so:x11-fonts/libXft

USE_GNOME=	gtk12
USES=		iconv pkgconfig libtool
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -lgnuregex ${ICONV_LIB}
CFLAGS+=	`pkg-config xft --cflags`
CONFIGURE_ARGS=	--sbindir=${PREFIX}/bin \
		--without-gnome
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|src capplet|src @BUILD_CAPPLET_TRUE@capplet|g ; \
		 s|DESTDIR)\$$(datadir|DESTDIR)\$$(pkgdatadir|g ; \
		 s|la_LDFLAGS =.*$$|la_LDFLAGS = -module -avoid-version|g'
	@${REINPLACE_CMD} 's/<regex\.h>/<gnuregex.h>/' ${WRKSRC}/src/gdkxft.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgdkxft.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
