# New ports collection makefile for:	xforms
# Version required:	0.88.1
# Date created:		28 March 1997
# Whom:			gena
#
# $Id: Makefile,v 1.20 1998/11/02 04:35:07 jseger Exp $
#

USE_X_PREFIX=	yes
.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
DISTNAME=	bxform-freebsd-elf
MASTER_SITES=	http://bragg.phys.uwm.edu/~zhao/ftp/
PATCHDIR=	${.CURDIR}/patches.elf
.else
DISTNAME=	bxform-088
MASTER_SITES=	ftp://bragg.phys.uwm.edu/pub/xforms/freeBSD/ \
		ftp://ftp.via.ecp.fr/pub2/xforms/freeBSD/ \
		ftp://ftp.st.ryukoku.ac.jp/pub/X11/xforms/freeBSD/
.endif
PKGNAME=	xforms-0.88.1
CATEGORIES=	graphics x11-toolkits
EXTRACT_SUFX=	.tgz

MAINTAINER=	gena@NetVision.net.il

PATCH_STRIP=	-p0 -t
WRKSRC=		${WRKDIR}/xforms
MAN1=		fdesign.1 fd2ps.1
MAN5=		xforms.5

post-install:
	${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOMANCOMPRESS)
	@${RM} ${PREFIX}/man/man5/forms.5
	@ln -fs xforms.5.gz ${PREFIX}/man/man5/forms.5.gz
.endif

.include <bsd.port.post.mk>
