# Ports collection makefile for:	xstroke
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xstroke
PORTVERSION=	0.5.12
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://xstroke.org/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen gesture recognition

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/libXft

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_BISON=	yes
USE_IMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS=	-I${LOCALBASE}/include -I.
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

MAN1=	xstroke.1

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/etc/Imakefile
	@${REINPLACE_CMD} -e "s,etc/,${PREFIX}/etc/,g" ${WRKSRC}/args.h

.include <bsd.port.mk>
