# New ports collection makefile for:   aterm
# Version required:	0.3.2
# Date created:		17 January 1999
# Whom:			Jim Mock <jim@phrantic.phear.net>
#
# $Id: Makefile,v 1.1.1.1 1999/01/26 03:25:16 steve Exp $
#

DISTNAME=	aterm-0.3.2
CATEGORIES=	x11
MASTER_SITES=	http://www.tigr.net/afterstep/as-apps/download/aterm/

MAINTAINER=	jim@phrantic.phear.net

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-transparency --enable-background-image \
		--disable-delete-key --disable-backspace-key
MAN1=		aterm.1

do-build:
	(cd ${WRKSRC} && make)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/aterm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/aterm.1 ${PREFIX}/man/man1/aterm.1

.include <bsd.port.mk>
