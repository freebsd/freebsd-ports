# New ports collection makefile for:	gtkterm2
# Date created:		2004-06-12
# Whom:			michael johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	gtkterm2
PORTVERSION=	0.2.3
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	gtkterm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple GTK-2 terminal with tabs

USE_GNOME=	gnometarget vte
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

PORTDOCS=	README
PLIST_FILES=	bin/gtkterm2 \
		share/locale/de/LC_MESSAGES/gtkterm2.mo \
		%%DATADIR%%/pixmaps/gtkterm2.png
PLIST_DIRS=	%%DATADIR%%/pixmaps %%DATADIR%%

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} -e 's|^CFLAGS=""||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/gtkterm2 ${PREFIX}/bin/gtkterm2
	${INSTALL_DATA} ${WRKSRC}/po/de.gmo \
		${PREFIX}/share/locale/de/LC_MESSAGES/gtkterm2.mo
	@${MKDIR} ${DATADIR}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/gtkterm2.png \
		${DATADIR}/pixmaps/gtkterm2.png
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
.endif

.include <bsd.port.mk>
