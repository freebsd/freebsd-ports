# New ports collection makefile for:	xmhtml
# Version required:     1.69
# Date created:		18 Feb 1999
# Whom:			Peter Hawkins <thepish@freebsd.org>
#
# $Id: Makefile,v 1.3 1999/02/18 15:02:42 thepish Exp $
#

DISTNAME=	XmHTML-1.1.0

CATEGORIES=	x11 www
MASTER_SITES=	ftp://crl.nmsu.edu/pub/XmHTML/ \
		ftp://ftp.ist.co.uk/pub/motif/XmHTML/ \
		ftp://ftp.nerdnet.nl/pub/X11/Widgets/XmHTML/

PATCH_SITES=	ftp://crl.nmsu.edu/pub/XmHTML/
PATCHFILES=	patch-102697.gz

MAINTAINER=	thepish@freebsd.org

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes

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
