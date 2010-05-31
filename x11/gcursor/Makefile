# New ports collection makefile for:	gcursor
# Date created:				08 March 2004
# Whom:					Mezz <mezz7@cox.net>
#
# $FreeBSD$
#

PORTNAME=	gcursor
PORTVERSION=	0.061
PORTREVISION=	12
CATEGORIES=	x11 gnome
MASTER_SITES=	http://download.qballcow.nl/programs/gcursor/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A mouse cursor theme selector for GNOME

RUN_DEPENDS=	file-roller:${PORTSDIR}/archivers/file-roller

USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack libgnomeui
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

DOCS=		AUTHORS COPYING ChangeLog INSTALL TODO

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/src/gcursor.c

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
