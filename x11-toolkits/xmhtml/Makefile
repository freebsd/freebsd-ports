# New ports collection makefile for:	xmhtml
# Version required:     1.69
# Date created:		18 Feb 1999
# Whom:			Peter Hawkins <thepish@freebsd.org>
#
# $FreeBSD$
#

DISTNAME=	XmHTML-1.1.0
CATEGORIES=	x11-toolkits www
MASTER_SITES=	ftp://crl.nmsu.edu/pub/XmHTML/ \
		ftp://ftp.ist.co.uk/pub/motif/XmHTML/ \
		ftp://ftp.nerdnet.nl/pub/X11/Widgets/XmHTML/

PATCH_SITES=	ftp://crl.nmsu.edu/pub/XmHTML/
PATCHFILES=	patch-102697.gz

MAINTAINER=	thepish@freebsd.org

LIB_DEPENDS=    png.3:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
XMKMF=		PORTOBJFORMAT=${PORTOBJFORMAT} xmkmf -a

EXMP_DIR=	${PREFIX}/share/examples/${DISTNAME}/
DOCS_DIR=	${PREFIX}/share/doc/${DISTNAME}/

pre-install:
	${ECHO} "installing examples into ${EXMP_DIR}"
	@ ${MKDIR} ${EXMP_DIR}
	@ tar -C ${WRKSRC} -cpf- book contrib examples|tar -xvpf- -C ${EXMP_DIR}
	${ECHO} "installing docs into ${DOCS_DIR}"
	@ ${MKDIR} ${DOCS_DIR}
	@ (cd ${WRKSRC}/html; tar -cpf- * | tar -xvpf- -C ${DOCS_DIR} )

post-install:
	@ ${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
