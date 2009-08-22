# ex:ts=8
# Ports collection makefile for:	viewklass
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	viewklass
PORTVERSION=	0.7.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/ViewKlass-${PORTVERSION}
DISTNAME=	ViewKlass-${PORTVERSION}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	C++ Framework for Motif

BUILD_DEPENDS=	imake:${PORTSDIR}/devel/imake

USE_MOTIF=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS=/CFLAGS+=/g ; \
		s/^CXXFLAGS=/CXXFLAGS+=/g ; \
		s/-g -Wall//g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
