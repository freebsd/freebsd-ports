# ex:ts=8
# Ports collection makefile for:	viewklass
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	viewklass
PORTVERSION=	0.7.0
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ViewKlass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Framework for Motif

USE_X_PREFIX=	yes
USE_MOTIF=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 3
BUILD_DEPENDS+=	xmkmf:${PORTSDIR}/devel/imake
.else
BUILD_DEPENDS+=	xmkmf:${PORTSDIR}/devel/imake-4
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/^CFLAGS=/CFLAGS+=/g ; \
		s/^CXXFLAGS=/CXXFLAGS+=/g ; \
		s/-g -Wall//g' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
