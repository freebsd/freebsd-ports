# New ports collection makefile for:	eterm
# Version required:    0.8.7
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.9 1998/10/09 18:05:11 vanilla Exp $
#

DISTNAME=	Eterm-0.8.7
PKGNAME=	eterm-0.8.7
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/Eterm/ \
		http://www.tcserv.com/archive/E/

MAINTAINER=	murray@cdrom.com

LIB_DEPENDS=	Imlib.1:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

MAN1=		Eterm.1

pre-patch:
.if ( defined(KANJI) )
	${CP} ${FILESDIR}/patch-kanji ${PATCHDIR}
.endif

post-install:
	chown root.wheel ${PREFIX}/bin/Eterm
	chmod 4755 ${PREFIX}/bin/Eterm

.ifndef NOPORTDOCS
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ref ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${PREFIX}/share/Eterm
	${INSTALL_SCRIPT} ${WRKSRC}/doc/colortest.sh ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/menu_cmd ${PREFIX}/share/Eterm
.endif

.include <bsd.port.mk>
