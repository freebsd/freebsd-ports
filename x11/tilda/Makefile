# New ports collection makefile for:	tilda
# Date created:				4 Jan 2005
# Whom:					Vlad V. Teterya <vlad@vlad.uz.ua>
#
# $FreeBSD$
#

PORTNAME=	tilda
PORTVERSION=	0.09.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	vlad@vlad.uz.ua
COMMENT=	Drop down x11 terminal with transparency support

BUILD_DEPENDS=	vte:${PORTSDIR}/x11-toolkits/vte
RUN_DEPENDS=	vte:${PORTSDIR}/x11-toolkits/vte

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GCC=	3.4+

PLIST_FILES=	bin/tilda
PORTDOCS=	AUTHORS ChangeLog README TODO

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/readconf.c

post-install:
.if !defined (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
