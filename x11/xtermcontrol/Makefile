# Created by: krion
# $FreeBSD$

PORTNAME=	xtermcontrol
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.thrysoee.dk/xtermcontrol/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Tool for dynamic control of xterm properties

RUN_DEPENDS=	xterm:${PORTSDIR}/x11/xterm

USES=		gettext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

PLIST_FILES=	bin/xtermcontrol man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
