# New ports collection makefile for:	Xbae
# Version required:	4.6.2
# Date created:		11 December 96
# Whom:			Lars Koeller <Lars_Koeller@odie.physik2.uni-rostock.de>
# With some
# modifications from:	Andreas Klemm <andreas@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=	Xbae-4.7
PKGNAME=	xbae-4.7
CATEGORIES=	x11-toolkits math
MASTER_SITES=	ftp://sunsite.doc.ic.ac.uk/packages/X11/contrib/widgets/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	widgets/motif

MAINTAINER=	Lars.Koeller@Uni-Bielefeld.de

REQUIRES_MOTIF= YES
USE_IMAKE=	YES
MAN3=		XbaeCaption.3 XbaeMatrix.3

.include <bsd.port.pre.mk>

post-install:
.if ${PORTOBJFORMAT} == "aout"
	${LN} -sf libXbae.so.6.2 ${PREFIX}/lib/libXbae.so
.endif
	${RM} -rf ${PREFIX}/include/Xbae
	${LN} -sf Xbae-4.7 ${PREFIX}/include/Xbae
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.post.mk>
