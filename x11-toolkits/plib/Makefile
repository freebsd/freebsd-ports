# New ports collection makefile for:	plib
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=		plib
PORTVERSION= 		1.2.0
CATEGORIES=		x11-toolkits
MASTER_SITES=		http://plib.sourceforge.net/dist/

MAINTAINER=		ports@FreeBSD.org

LIB_DEPENDS=		GL.14:${PORTSDIR}/graphics/Mesa3

USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CPPFLAGS=-I${X11BASE}/include
CONFIGURE_ARGS+=	--includedir=$(PREFIX)/include/plib \
			--with-glut=${PREFIX}
USE_GMAKE=		yes
USE_NEWGCC=		yes
MANCOMPRESSED=		yes

pre-configure:
	${PERL} -pi -e "s:-O6 ::g" ${WRKSRC}/configure

.include <bsd.port.mk>
