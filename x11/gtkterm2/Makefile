# New ports collection makefile for:	gtkterm2
# Date created:		2004-06-12
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gtkterm2
PORTVERSION=	0.2.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	gtkterm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple GTK-2 terminal with tabs

USE_LIBTOOL_VER=13
USE_GNOME=	gnomeprefix vte lthack
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GETOPT_LONG=yes

DATADIR=	${PREFIX}/share/gnome
PORTDOCS=	README
PLIST_FILES=	bin/gtkterm2 \
		share/locale/de/LC_MESSAGES/gtkterm2.mo \
		%%DATADIR%%/pixmaps/gtkterm2.png
LCDIR=		${PREFIX}/share/locale/de/LC_MESSAGES

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gtkterm2 ${PREFIX}/bin
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/gtkterm2.png ${DATADIR}/pixmaps
	@${MKDIR} ${LCDIR}
	@${INSTALL_DATA} ${WRKSRC}/po/de.gmo ${LCDIR}/gtkterm2.mo
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
