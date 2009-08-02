# New ports collection makefile for:	gnome-launch-box
# Date created:			12 Jan 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-launch-box
PORTVERSION=	20060112
PORTREVISION=	7
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An application launcher for the GNOME desktop

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	libgnomeui evolutiondataserver gnomemenus gnomedesktop

USE_AUTOTOOLS=	autoconf:262 autoheader:262 automake:19 aclocal:19 libtool:22
ACLOCAL_ARGS=	-I ${LOCALBASE}/share/aclocal
AUTOMAKE_ARGS=	-a
LIBTOOLFILES=
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PORTDOCS=	AUTHORS README TODO

pre-configure:
	@${LN} -sf ${AUTOMAKE_DIR}/mkinstalldirs ${CONFIGURE_WRKSRC}
	@cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} && \
		${LOCALBASE}/bin/intltoolize

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
