# Created by: ijliao
# $FreeBSD$

PORTNAME=	genmenu
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://gtk.no/archive/genmenu/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Generating menus for Bbox, Fbox, Obox, WM and E

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

PLIST_FILES=	bin/genmenu
NO_BUILD=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|^#!/bin/bash|#!${LOCALBASE}/bin/bash|" ${WRKSRC}/genmenu

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/genmenu ${PREFIX}/bin

.include <bsd.port.mk>
