# New ports collection makefile for:	vdesk
# Date created:				2002-05-13
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	vdesk
PORTVERSION=	1.2
CATEGORIES=	x11
MASTER_SITES=	http://offog.org/files/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Command-line utility for setting up and using virtual desktops

DOCS=		AUTHORS COPYING ChangeLog INSTALL NEWS README
PLIST_DIRS=	share/doc/vdesk
PLIST_FILES=	bin/vdesk
.if !defined(NOPORTDOCS)
.for ii in ${DOCS}
PLIST_FILES+=	share/doc/vdesk/${ii}
.endfor
.endif
USE_X_PREFIX=		yes
USE_AUTOCONF_VER=	259

post-extract:
# Avoid having to read this lengthy file.
	${RM} ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/vdesk ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
