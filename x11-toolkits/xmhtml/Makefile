PORTNAME=	XmHTML
PORTVERSION=	1.1.10
CATEGORIES=	x11-toolkits www
MASTER_SITES=	SF/${PORTNAME:tl}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Motif widget set for displaying HTML 3.2 documents
WWW=		https://sourceforge.net/projects/xmhtml/

LICENSE=	LGPL20+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libpng.so:graphics/png

USES=		gmake jpeg libtool:build motif pkgconfig tar:tgz xorg
USE_LDCONFIG=	yes
USE_XORG=	xft xmu xpm xt

MAKE_ENV=	LIBTOOL=${LIBTOOL}

OPTIONS_DEFINE=	DOCS EXAMPLES

LIBTOOL=	libtool

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	(cd ${WRKSRC}/lib && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libXmHTML.la ${STAGEDIR}${PREFIX}/lib)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXmHTML.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h \
		${STAGEDIR}${PREFIX}/include/XmHTML

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/html && ${COPYTREE_SHARE} . \
		${STAGEDIR}${DOCSDIR})

do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "book contrib examples" \
		${STAGEDIR}${EXAMPLESDIR} "! -name Makefile"

.include <bsd.port.mk>
