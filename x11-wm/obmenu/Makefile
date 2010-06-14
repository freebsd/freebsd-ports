# New ports collection makefile for:	obmenu
# Date created:				2007-12-18
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	obmenu
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Menu manager for Openbox supporting both static and pipe menus

LICENSE=	GPLv2

USE_GNOME=		pygtk2
USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	obMenu

PORTDOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
