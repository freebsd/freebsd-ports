# ex:ts=8
# Ports collection makefile for:	twin
# Date created:			Jul 7, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	twin
PORTVERSION=	0.4.4
CATEGORIES=	x11
MASTER_SITES=	http://linuz.sns.it/~max/twin/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

MAN1=	twin.1

post-patch:
	@${REINPLACE_CMD} -e "s/-lpthread/${PTHREAD_LIBS}/g" ${WRKSRC}/configure

.include <bsd.port.mk>
