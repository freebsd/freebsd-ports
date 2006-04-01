# New ports collection makefile for:	WindowMaker Theme Installer
# Date created:		09 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	wmthemeinstall
PORTVERSION=	0.62
PORTREVISION=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.jeremias.net/wmthemeinstall/download/

MAINTAINER=	adam-ports@blacktabby.org
COMMENT=	A neat theme manager for WindowMaker

RUN_DEPENDS=	wmaker:${PORTSDIR}/x11-wm/windowmaker

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog README
PLIST_FILES=	bin/wmthemeinstall

pre-build:
	@${REINPLACE_CMD} -e "s|/usr/local|${PREFIX}|g" ${WRKSRC}/wmOptions.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/wmthemeinstall ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
. for f in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
. endfor
	@${ECHO}
	@${ECHO} "Documentation was installed in ${DOCSDIR}."
	@${ECHO}
.endif

.include <bsd.port.mk>
