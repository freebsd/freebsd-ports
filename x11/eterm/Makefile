# New ports collection makefile for:	eterm
# Version required:    0.8.8
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $Id: Makefile,v 1.13 1999/01/17 17:56:12 nectar Exp $
#

DISTNAME=	Eterm-0.8.8
PKGNAME=	eterm-0.8.8
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.eterm.org/pub/Eterm/ \
		http://eterm.is.nontoxic.org/download/ \
		ftp://ftp.livewire.com.au/pub/linuxberg/files/x11/system/ \
		ftp://ftp.c-com.net/pub/.30/LinuxBerg/files/x11/system/ \
		ftp://ftp.sunsite.auc.dk/disk6/linuxberg.com/files/x11/system/

MAINTAINER=	murray@cdrom.com

BUILD_DEPENDS=	libtool:${PORTSDIR}/devel/libtool
LIB_DEPENDS=	Imlib.2:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" LOCALBASE=${LOCALBASE}

MAN1=		Eterm.1

pre-patch:
.if ( defined(KANJI) )
	${CP} ${FILESDIR}/patch-kanji ${PATCHDIR}
.endif

post-patch:
	@find ${WRKSRC} -name '*.orig' | xargs ${RM} -f

post-install:
	chown root.wheel ${PREFIX}/bin/Eterm
	chmod 4755 ${PREFIX}/bin/Eterm
	${INSTALL_SCRIPT} ${WRKSRC}/doc/colortest.sh ${PREFIX}/share/Eterm
.ifndef NOPORTDOCS
	${MKDIR} ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.help ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ref ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ.html ${PREFIX}/share/doc/Eterm
	${INSTALL_DATA} ${WRKSRC}/doc/menu_cmd ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.mk>
