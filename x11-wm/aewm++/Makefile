# ex:ts=8
# Ports collection makefile for:	aewm++
# Date created:			Jan 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	aewm++
PORTVERSION=	1.0.15
CATEGORIES=	x11-wm
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	sapphire

MAINTAINER=	ports@FreeBSD.org

USE_X_PREFIX=	yes
USE_GMAKE=	yes
CXXFLAGS+=	-I${X11BASE}/include
LIBS+=		-L${X11BASE}/lib

MANCOMPRESSED=	yes
MAN1=	aewm++.1x

post-patch:
	@${PERL} -pi -e "s,^CC,#CC,g ; s,^CFLAGS,#CFLAGS,g ; \
		s,^prefix,#prefix,g ; s,prefix,PREFIX,g ; \
		s,CC,CXX,g ; s,CFLAGS,CXXFLAGS,g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
