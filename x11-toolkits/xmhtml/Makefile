# New ports collection makefile for:	xmhtml
# Date created:		18 Feb 1999
# Whom:			Peter Hawkins <thepish@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	XmHTML
PORTVERSION= 	1.1.7
CATEGORIES=	x11-toolkits www
MASTER_SITES=	http://www.xs4all.nl/~ripley/XmHTML/dist/

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

LIB_DEPENDS=    png.4:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

REQUIRES_MOTIF= yes
USE_GMAKE=      yes
USE_LIBTOOL=    yes
USE_X_PREFIX=   yes
USE_MOTIF=	yes

INSTALLS_SHLIB=	yes

EXMP_DIR=       ${X11BASE}/share/examples/${DISTNAME}/
DOCS_DIR=       ${X11BASE}/share/doc/${DISTNAME}/

EXMP_DIR=	${PREFIX}/share/examples/${DISTNAME}/
DOCS_DIR=	${PREFIX}/share/doc/${DISTNAME}/

post-patch:
	${TOUCH} ${WRKSRC}/configure
	${CHMOD} 755 ${WRKSRC}/configure

post-build:
	${RM} -rf ${WRKSRC}/examples/.libs ${WRKSRC}/examples/*.lo ${WRKSRC}/examples/*.o
	${RM} -rf ${WRKSRC}/book/.libs ${WRKSRC}/book/*.lo ${WRKSRC}/book/*.o
	${RM} -rf ${WRKSRC}/contrib/.libs ${WRKSRC}/contrib/*.lo ${WRKSRC}/contrib/*.o

pre-install:
	${ECHO} "installing examples into ${EXMP_DIR}"
	@ ${MKDIR} ${EXMP_DIR}
	@ tar -C ${WRKSRC} -cpf- book contrib examples|tar -xvpf- -C ${EXMP_DIR}
	${ECHO} "installing docs into ${DOCS_DIR}"
	@ ${MKDIR} ${DOCS_DIR}
	@ (cd ${WRKSRC}/html; tar -cpf- * | tar -xvpf- -C ${DOCS_DIR} )

do-install:
	${LIBTOOL} --mode=install ${INSTALL_DATA} \
		${WRKSRC}/lib/libXmHTML.la ${X11BASE}/lib
	${RM} -f ${X11BASE}/lib/libXmHTML.la
	${MKDIR} ${X11BASE}/include/XmHTML
	${INSTALL_DATA} ${WRKSRC}/include/XmHTML/*.h ${X11BASE}/include/XmHTML

post-install:
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
