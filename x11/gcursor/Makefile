# New ports collection makefile for:	gcursor
# Date created:				08 March 2004
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gcursor
PORTVERSION=	0.061
PORTREVISION=	3
CATEGORIES=	x11 gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gcursor/

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A mouse cursor theme selector for GNOME

RUN_DEPENDS=	file-roller:${PORTSDIR}/archivers/fileroller

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog INSTALL TODO

post-patch:
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|g' \
		${WRKSRC}/src/gcursor.c
	@${REINPLACE_CMD} -e 's|share/applications|share/gnome/applications|g' \
		${WRKSRC}/data/Makefile.in

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
