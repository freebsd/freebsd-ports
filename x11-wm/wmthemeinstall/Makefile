# New ports collection makefile for:	WindowMaker Theme Installer
# Version required:	0.62
# Date created:		09 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

DISTNAME=	wmthemeinstall-0.62
CATEGORIES=	x11-wm
MASTER_SITES=	http://hellblazer.dhis.org/projects/wmthemeinstall/download/

MAINTAINER=	andrews@technologist.com

RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker
LIB_DEPENDS=	gtk12.2:${PORTSDIR}/x11-toolkits/gtk12

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	GTK_CONFIG="${X11BASE}/bin/gtk12-config"
DOCS_DIR=	${PREFIX}/share/wmthemeinstall

pre-build:
	@${SED} -e s,/usr/local,${PREFIX},g ${WRKSRC}/wmOptions.c \
		> ${WRKSRC}/wmOptions.c.new
	@${MV} ${WRKSRC}/wmOptions.c.new ${WRKSRC}/wmOptions.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmthemeinstall ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCS_DIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCS_DIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCS_DIR}
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCS_DIR}
	@${ECHO}
	@${ECHO} "Documentation was installed in ${DOCS_DIR}."
	@${ECHO}
.endif

.include <bsd.port.mk>
