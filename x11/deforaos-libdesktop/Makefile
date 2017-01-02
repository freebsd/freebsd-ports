# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libdesktop
PORTVERSION=	0.2.2
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4447/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	libDesktop-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS desktop library

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem

USE_GNOME=	gtk20
USES=		pkgconfig
USE_LDCONFIG=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

MAKE_JOBS_UNSAFE=	yes
OPTIONS_DEFINE=	DOCS

DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl \
	gtkdoc-check:textproc/gtk-doc

post-patch:
	${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	${REINPLACE_CMD} 's|-Wl,-pie||g' ${WRKSRC}/tools/Makefile
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
