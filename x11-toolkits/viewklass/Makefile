# ex:ts=8
# Ports collection makefile for:	viewklass
# Date created:			Jun 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	viewklass
PORTVERSION=	0.5.2
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ViewKlass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	C++ Framework for Motif

USE_REINPLACE=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s/^CFLAGS=/CFLAGS+=/g ; s/^CXXFLAGS=/CXXFLAGS+=/g ; \
		s/-g -Wall//g" ${WRKSRC}/Makefile.in

post-install:
.for file in libvk.a libvkhelp.a
	@${STRIP_CMD} ${PREFIX}/lib/${file}
.endfor

.include <bsd.port.mk>
