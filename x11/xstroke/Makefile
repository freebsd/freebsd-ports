# ex:ts=8
# Ports collection makefile for:	xstroke
# Date created:			May 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xstroke
PORTVERSION=	0.5.12
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.handhelds.org/pub/projects/xstroke/release-${PORTVERSION:R}/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_BISON=	yes
USE_IMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lgnugetopt

MAN1=	xstroke.1

post-patch:
	@${PERL} -pi -e "s,-lpthread,${PTHREAD_LIBS},g ; \
		s,%%CFLAGS%%,${CFLAGS},g ; \
		s,%%LDFLAGS%%,${LDFLAGS},g" ${WRKSRC}/Imakefile
	@${PERL} -pi -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/etc/Imakefile

.include <bsd.port.mk>
