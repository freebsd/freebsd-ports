# New ports collection makefile for:	eterm
# Version required:    0.8.6
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.8 1998/09/25 09:52:45 asami Exp $
#

DISTNAME=	Eterm-0.8.6
PKGNAME=	eterm-0.8.6
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/Eterm/ \
		http://www.tcserv.com/archive/E/

MAINTAINER=	murray@cdrom.com

LIB_DEPENDS=	Imlib.1:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

#ALL_TARGET=	FreeBSD
MAN1=		Eterm.1

post-install:
	strip ${PREFIX}/bin/Eterm-0.8
	chown root.wheel ${PREFIX}/bin/Eterm-0.8
	chmod 4755 ${PREFIX}/bin/Eterm-0.8
.ifndef NOPORTDOCS
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/Eterm
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
