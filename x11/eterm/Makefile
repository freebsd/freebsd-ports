# New ports collection makefile for:	eterm
# Date created:        24 November 1997
# Whom:                Murray Stokely <murray@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	eterm
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	eterm
DISTNAME=	Eterm-${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org

BUILD_DEPENDS=	man2html:${PORTSDIR}/textproc/man2html

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_IMLIB=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-trans=imlib --enable-utmp \
		--enable-xim --with-theme-update \
		--with-backspace=bs
CONFIGURE_ENV=	LIBS="-lxpg4"

MAN1=		Eterm.1

post-install:
	@${CHMOD} 4711 ${PREFIX}/bin/Eterm
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/ReleaseNotes ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.1.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm_reference.html ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.tcap ${PREFIX}/share/doc/Eterm
	@${INSTALL_DATA} ${WRKSRC}/doc/Eterm.ti ${PREFIX}/share/doc/Eterm
.endif

.include <bsd.port.mk>
