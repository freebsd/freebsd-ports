# New ports collection makefile for:	eterm
# Version required:    0.7+PL5
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.6 1998/02/23 15:38:44 steve Exp $
#

DISTNAME=	Eterm-DR-0.7+PL5
PKGNAME=	eterm-0.7
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.mandrake.net/pub/Eterm/ \
		http://www.tcserv.com/archive/E/ \
		http://www.spd.louisville.edu/~mejenn01/archive/E/

MAINTAINER=	murray@cdrom.com

LIB_DEPENDS=	Imlib\\.1\\.:${PORTSDIR}/graphics/imlib

WRKSRC=		$(WRKDIR)/Eterm-DR-0.7
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
MAN1=		Eterm.1
ALL_TARGET=	FreeBSD

post-install:
	strip ${PREFIX}/bin/Eterm
	chown root.wheel ${PREFIX}/bin/Eterm
	chmod 4755 ${PREFIX}/bin/Eterm
.ifndef NOPORTDOCS
	${INSTALL_DATA} ${WRKSRC}/RELNOTES.Eterm ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.help ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.menu ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ref ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${PREFIX}/share/Eterm
	${INSTALL_SCRIPT} ${WRKSRC}/doc/colortest.sh ${PREFIX}/share/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/menu_cmd ${PREFIX}/share/Eterm
.endif

.include <bsd.port.mk>
