# New ports collection makefile for:	gnome-launch-box
# Date created:			12 Jan 2006
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnome-launch-box
PORTVERSION=	20060112
CATEGORIES=	x11 gnome
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	jylefort

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	An application launcher for the GNOME desktop

BROKEN=		fails to install

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	libgnomeui evolutiondataserver gnomemenus gnomedesktop

USE_AUTOTOOLS=	autoconf:259 autoheader:259 automake:19 aclocal:19 libtool:15
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}

.include <bsd.port.mk>
