# New ports collection makefile for:	xforms
# Version required:	0.88
# Date created:		28 March 1997
# Whom:			gena
#
# $Id: Makefile,v 1.13 1998/01/05 17:24:19 vanilla Exp $
#

DISTNAME=	bxform-088
PKGNAME=	xforms-0.88
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://einstein.phys.uwm.edu/pub/xforms/freeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X11=	yes
WRKSRC=		${WRKDIR}/xforms
MAN1=		fdesign.1 fd2ps.1
MAN5=		xforms.5

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	@${RM} ${PREFIX}/man/man5/forms.5
	@ln -fs xforms.5.gz ${PREFIX}/man/man5/forms.5.gz
.endif

.include <bsd.port.mk>
