# New ports collection makefile for:	neXtaw
# Version required:	0.5.1
# Date created:		16 January 1997
# Whom:			Thomas Gellekum <tg@FreeBSD.ORG>
#
# $Id: Makefile,v 1.6 1997/11/06 08:55:35 tg Exp $
#

DISTNAME=	neXtaw-0.5.1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.inf.ufrgs.br/~kojima/nextaw/
EXTRACT_SUFX=	.tar.gz.bin

MAINTAINER=	tg@FreeBSD.ORG

USE_IMAKE=	yes

post-extract:
	@${RM} -rf ${WRKSRC}/X11

post-configure:
	@${ECHO_MSG} "*********************************************************************"
	@${ECHO_MSG} "* Don't worry about the warning messages above, the port will build *"
	@${ECHO_MSG} "*********************************************************************"
	@cd ${WRKSRC}/exports/include/X11/neXtaw; ln -sf ../../../../*.h .

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/neXtaw
	${INSTALL_DATA} ${WRKSRC}/README.neXtaw ${PREFIX}/share/doc/neXtaw
.endif
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
