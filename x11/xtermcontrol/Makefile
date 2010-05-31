# New ports collection makefile for:	xtermcontrol
# Date created:				23.12.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xtermcontrol
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.thrysoee.dk/xtermcontrol/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Tool for dynamic control of xterm properties

RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/xtermcontrol
MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
