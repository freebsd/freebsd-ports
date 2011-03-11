# Ports collection makefile for:	xstroke
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xstroke
PORTVERSION=	0.5.12
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/projects/xstroke/release-0.5/ \
		http://www.handhelds.org/download/projects/xstroke/release-0.5/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen gesture recognition

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_BISON=	build
USE_XORG=	xft x11 xext xi xtst
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
