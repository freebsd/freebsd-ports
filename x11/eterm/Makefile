# New ports collection makefile for:	eterm
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@cdrom.com>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION= 	0.8.10
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.eterm.org/pub/Eterm/ \
		http://eterm.is.nontoxic.org/download/ \
		ftp://ftp.livewire.com.au/pub/linuxberg/files/x11/system/ \
		ftp://ftp.c-com.net/pub/.30/LinuxBerg/files/x11/system/ \
		ftp://ftp.sunsite.auc.dk/disk6/linuxberg.com/files/x11/system/
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	murray@FreeBSD.org

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		Eterm.1

pre-patch:
.if ( defined(KANJI) )
	${CP} ${FILESDIR}/patch-kanji ${PATCHDIR}
.endif

# this is needed to remove leftover files from applied patches.
pre-install:
.for i in Eterm emacs irc mutt tn3270 trans
	@${RM} -f ${WRKSRC}/themes/$i/*.orig
.endfor

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.ifndef NOPORTDOCS
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.mk>
