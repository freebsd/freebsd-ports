# New ports collection makefile for:	xforms
# Version required:	0.88.1
# Date created:		28 March 1997
# Whom:			gena
#
# $Id: Makefile,v 1.16 1998/05/12 06:34:18 tg Exp $
#

DISTNAME=	bxform-088
PKGNAME=	xforms-0.88.1
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://bragg.phys.uwm.edu/pub/xforms/freeBSD/ \
		ftp://ftp.via.ecp.fr/pub2/xforms/freeBSD/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/X11/xforms/freeBSD/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

USE_X_PREFIX=	yes
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
