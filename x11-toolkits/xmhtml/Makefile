# Created by: Peter Hawkins <thepish@FreeBSD.org>
# $FreeBSD$

PORTNAME=	XmHTML
PORTVERSION=	1.1.9
PORTREVISION=	3
CATEGORIES=	x11-toolkits www
MASTER_SITES=	SF/${PORTNAME:tl}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif widget set for displaying HTML 3.2 documents

LICENSE=	LGPL20 # (or later)
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png

USES=		gmake jpeg libtool:build motif pkgconfig tar:tgz
USE_XORG=	xft xmu xpm xt
USE_LDCONFIG=	yes

LIBTOOL=	libtool
MAKE_ENV=	LIBTOOL=${LIBTOOL}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	(cd ${WRKSRC}/lib && ${LIBTOOL} --mode=install ${INSTALL_DATA} \
		libXmHTML.la ${STAGEDIR}${PREFIX}/lib)
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libXmHTML.so
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/XmHTML
	(cd ${WRKSRC}/include/XmHTML && ${INSTALL_DATA} *.h \
		${STAGEDIR}${PREFIX}/include/XmHTML)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC}/html && ${FIND} . ! -name "*Makefile*" | \
		${CPIO} --quiet -dump -R ${SHAREOWN}:${SHAREGRP} \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "book contrib examples" \
		${STAGEDIR}${EXAMPLESDIR} "! -type d ! -name Makefile"

.include <bsd.port.mk>
