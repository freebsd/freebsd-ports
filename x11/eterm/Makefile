# New ports collection makefile for:	eterm
# Version required:    0.6apl2
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.4 1997/11/29 22:06:43 asami Exp $
#

DISTNAME=	Eterm-DR-0.6aPL2
PKGNAME=	eterm-0.6a2
CATEGORIES=	x11
MASTER_SITES=	ftp://cthulhu.mandrake.net/pub/Eterm/

MAINTAINER=	murray@cdrom.com

LIB_DEPENDS=	Im\\.4\\.:${PORTSDIR}/graphics/imlib

BROKEN=		R_OK undefined
WRKSRC=		$(WRKDIR)/Eterm-DR-0.6a
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAN1=		Eterm.1

do-build:
	cd ${WRKSRC}/src && \
	${GMAKE} clean && \
	${GMAKE} FreeBSD && \
	cd ../doc && \
	${GMAKE} alldoc

do-install:
	${INSTALL_PROGRAM} $(WRKSRC)/src/Eterm $(PREFIX)/bin
	${INSTALL_PROGRAM} $(WRKSRC)/doc/dorand $(PREFIX)/bin
	${INSTALL_SCRIPT} $(WRKSRC)/doc/random_pixmap.sh $(PREFIX)/bin
	${INSTALL_MAN} $(WRKSRC)/doc/Eterm.1 $(PREFIX)/man/man1
	${MKDIR} $(PREFIX)/share/Eterm
	${INSTALL_MAN} $(WRKSRC)/doc/FAQ $(PREFIX)/share/Eterm
	${INSTALL_MAN} $(WRKSRC)/RELNOTES.Eterm $(PREFIX)/share/Eterm
	${INSTALL_SCRIPT} ${WRKSRC}/doc/colortest.sh ${PREFIX}/share/Eterm
	${INSTALL_SCRIPT} ${WRKSRC}/doc/menu.sh ${PREFIX}/share/Eterm
	${INSTALL_MAN} ${WRKSRC}/doc/Eterm.help ${PREFIX}/share/Eterm
	${INSTALL_MAN} ${WRKSRC}/doc/Eterm.ref ${PREFIX}/share/Eterm
	${INSTALL_MAN} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/Eterm
	${INSTALL_MAN} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/Eterm
	${INSTALL_MAN} ${WRKSRC}/doc/MAIN.dist ${PREFIX}/share/Eterm

.include <bsd.port.mk>
