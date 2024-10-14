PORTNAME=	libdesktop
PORTVERSION=	0.4.2
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/libDesktop/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	libDesktop-${PORTVERSION}

MAINTAINER=	khorben@defora.org
COMMENT=	DeforaOS desktop library
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz \
		libSystem.so:devel/deforaos-libsystem \
		libX11.so:x11/libX11

USES=		gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 gtk30
USE_LDCONFIG=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${PREFIX}/share/man

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
			gtkdoc-check:textproc/gtk-doc \
			xsltproc:textproc/libxslt

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|tests||' ${WRKSRC}/Makefile
	${REINPLACE_CMD} -e 's|./docbook.sh -P "$$(DESTDIR)$$(PREFIX)" -i -- "$$(OBJDIR)widget.html"| \
		#./docbook.sh -P "$$(DESTDIR)$$(PREFIX)" -i -- "$$(OBJDIR)widget.html"|' \
		${WRKSRC}/doc/Makefile

post-patch-DOCS-off:
	${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/widget \
		${STAGEDIR}${PREFIX}/lib/libDesktop.so.0.0

.include <bsd.port.mk>
