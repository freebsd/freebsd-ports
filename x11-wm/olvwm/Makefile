# New ports collection makefile for:	olvwm
# Version required:	4.1
# Date created:		21 October 1994
# Whom:			smace
#
# $id: Makefile,v 1.0 1994/10/21 00:00:00 smace Exp $
#

DISTNAME=	olvwm4
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.x.org/R5contrib/
EXTRACT_SUFX=	.tar.Z
DISTFILES=	olvwm4.tar.Z olvwm4.Patch01.Z
EXTRACT_ONLY=	olvwm4.tar.Z
NO_WRKSUBDIR=	yes
DEPENDS=	${PORTSDIR}/x11/xview-lib

pre-configure:
	@echo "Applying olvwm4 Patch01"
	@zcat ${DISTDIR}/olvwm4.Patch01.Z | patch -E -d ${WRKSRC} --quiet

.include <bsd.port.mk>
