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

pre-build:
	@${PERL} -pi -e "s:/usr/local:${PREFIX}:g" ${WRKSRC}/wmOptions.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmthemeinstall ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${ECHO}
	@${ECHO} "Documentation was installed in ${DOCSDIR}."
	@${ECHO}
.endif

.include <bsd.port.mk>
