# New ports collection makefile for:	termit
# Date created:				2008/06/20
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	termit
PORTVERSION=	2.7.0
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://cloud.github.com/downloads/nonstop/termit/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small terminal emulator

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_GNOME=	vte
USE_LUA=	yes
USE_GETTEXT=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/doc/s|^|#|' ${WRKSRC}/CMakeLists.txt

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.desktop ${PREFIX}/share/applications
	@${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/doc/${PORTNAME}.svg ${PREFIX}/share/pixmaps
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in README lua_api.txt rc.lua.example
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
