# Created by: Peter Hawkins <thepish@freebsd.org>
# $FreeBSD$

PORTNAME=	XmHTML
PORTVERSION=	1.1.7
PORTREVISION=	11
CATEGORIES=	x11-toolkits www
MASTER_SITES=	${MASTER_SITE_NETBSD}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Motif widget set for displaying HTML 3.2 documents

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USES=		gmake motif
USE_AUTOTOOLS=	libtool:env
USE_LDCONFIG=	yes
USE_XORG=	xmu
CFLAGS+=	-I${LOCALBASE}/include/libpng15

do-configure:
	@${DO_NADA}

post-build:
	${RM} -rf ${WRKSRC}/examples/.libs ${WRKSRC}/examples/*.lo ${WRKSRC}/examples/*.o
	${RM} -rf ${WRKSRC}/book/.libs ${WRKSRC}/book/*.lo ${WRKSRC}/book/*.o
	${RM} -rf ${WRKSRC}/contrib/.libs ${WRKSRC}/contrib/*.lo ${WRKSRC}/contrib/*.o

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${PREFIX}/include/XmHTML
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing docs into ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/html -cpf- . | ${TAR} -C ${DOCSDIR} -xpf-
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples into ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	${TAR} -C ${WRKSRC} -cpf- book contrib examples  | ${TAR} -C ${EXAMPLESDIR} -xpf-
.endif

.include <bsd.port.mk>
