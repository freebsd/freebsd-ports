# New ports collection makefile for:	videogen
# Date created:				21 Feb 2005
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	videogen
PORTVERSION=	0.21
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/xutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Generate modelines for XFree86 servers

USE_X_PREFIX=	yes
USE_REINPLACE=	yes

MAN1=		${PORTNAME}.1

PLIST_FILES=	bin/${PORTNAME} share/${PORTNAME}/some_modes.sh
PLIST_DIRS=	share/${PORTNAME}

post-extract:
	@${REINPLACE_CMD} -e '/^CFLAGS/d; s/gcc/$${CC}/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/bin/bash,/bin/sh,' ${WRKSRC}/some_modes.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/some_modes.sh ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/${MAN1}x ${MANPREFIX}/man/man1/${MAN1}

.include <bsd.port.mk>
