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
MASTER_SITES=	ftp://ftp.handhelds.org/pub/projects/xstroke/release-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fullscreen gesture recognition

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft
PATCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/devel/libgnugetopt:extract

USE_REINPLACE=	yes
USE_BISON=	yes
USE_IMAKE=	yes
CFLAGS+=	${PTHREAD_CFLAGS}
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
MAKE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

.include <bsd.port.pre.mk>

GETOPTDIR!=	cd ${PORTSDIR}/devel/libgnugetopt; ${MAKE} -V WRKSRC

MAN1=	xstroke.1

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/etc/Imakefile
	@${REINPLACE_CMD} -e "s,etc/,${PREFIX}/etc/,g" ${WRKSRC}/args.h
	${CP} ${GETOPTDIR}/getopt* ${WRKSRC}

.include <bsd.port.post.mk>
