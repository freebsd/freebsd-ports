# Created by: ijliao
# $FreeBSD$

PORTNAME=	genmenu
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://gtk.no/archive/genmenu/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generating menus for Bbox, Fbox, Obox, WM and E

RUN_DEPENDS=	bash:shells/bash

USES=		shebangfix
NO_BUILD=	yes

PLIST_FILES=	bin/genmenu
SHEBANG_FILES=	genmenu

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genmenu ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
