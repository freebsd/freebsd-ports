# New ports collection makefile for:	xtermcontrol
# Date created:				23.12.2004
# Whom:					krion
#
# $FreeBSD$
#

PORTNAME=	xtermcontrol
PORTVERSION=	2.7
CATEGORIES=	x11
MASTER_SITES=	http://www.thrysoee.dk/xtermcontrol/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Tool for dynamic control of xterm properties

RUN_DEPENDS=	xterm-static:${PORTSDIR}/x11/xterm

USE_X_PREFIX=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LIBS="-L${X11BASE}/lib -L${LOCALBASE}/lib"

PLIST_FILES=	bin/xtermcontrol
MAN1=		${PORTNAME}.1

.include <bsd.port.mk>
