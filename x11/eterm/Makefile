# New ports collection makefile for:	eterm
# Version required:    .6apl2
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.1.1.1 1997/11/01 14:58:46 jseger Exp $
#

DISTNAME=	Eterm-DR-0.6a
PKGNAME=	eterm-0.6a
CATEGORIES=	x11
MASTER_SITES=	http://www.tcserv.com/archive/E/ \
		http://www.spd.louisville.edu/~mejenn01/archive/E/

MAINTAINER=	murray@cdrom.com

LIB_DEPENDS=	Im\\.3\\.:${PORTSDIR}/graphics/imlib

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
