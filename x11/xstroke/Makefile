# ex:ts=8
# Ports collection makefile for:	xstroke
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xstroke
PORTVERSION=	0.5.12
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/projects/xstroke/release-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
USE_BISON=	yes
USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lgnugetopt

MAN1=	xstroke.1

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,%%CFLAGS%%,${CFLAGS},g ; \
		s,%%LDFLAGS%%,${LDFLAGS},g" ${WRKSRC}/Imakefile
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/etc/Imakefile
	@${REINPLACE_CMD} -e "s,etc/,${PREFIX}/etc/,g" ${WRKSRC}/args.h

.include <bsd.port.mk>
