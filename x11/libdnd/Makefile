# New ports collection makefile for:   libDnd
# Version required:		1.1
# Date created:                8 August 1997
# Whom:                        lukin@okbmei.msk.su
#
# $Id$
#

DISTNAME=	dnd.1.1
PKGNAME=	libdnd-1.1
CATEGORIES=	x11
MASTER_SITES=	http://leb.net/OffiX/
EXTRACT_SUFX=	.tgz

MAINTAINER=	lukin@okbmei.msk.su

WRKSRC=		${WRKDIR}/DND/DNDlib
GNU_CONFIGURE=	yes
ALL_TARGET=	libC libCpp

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/libdnd
	${INSTALL_MAN} ${WRKDIR}/DND/DNDdoc/* ${PREFIX}/share/doc/libdnd
.endif

.include <bsd.port.mk>
