# New ports collection makefile for:	WindowMaker Theme Installer
# Date created:		09 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmthemeinstall
PORTVERSION=	0.62
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
DOCS_DIR=	${PREFIX}/share/wmthemeinstall

pre-build:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/wmOptions.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmthemeinstall ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCS_DIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCS_DIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCS_DIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCS_DIR}
	@${ECHO}
	@${ECHO} "Documentation was installed in ${DOCS_DIR}."
	@${ECHO}
.endif

.include <bsd.port.mk>
