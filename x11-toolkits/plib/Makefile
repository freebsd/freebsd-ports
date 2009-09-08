# New ports collection makefile for:	plib
# Date created:		26 June 1999
# Whom:			Brian Buchanan <brian@CSUA.Berkeley.EDU>
#
# $FreeBSD$
#

PORTNAME=	plib
PORTVERSION=	1.8.5
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A portable library for joystick/sound/OpenGL GUI/3D math

USE_XORG=	xt xi xmu xext x11
USE_GNOME=	gnometarget
USE_GL=		glu
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CXXFLAGS+=	-fPIC
CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800064
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-js-jsBSD.cxx
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g ; \
		 s|-ldl||g ; \
		 s|-lc_r||g' ${WRKSRC}/configure
.if ${OSVERSION} >= 800064
	@${ECHO} "JS component is not compiled with new usb stack"
.endif

post-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/plib-jscal ${FILESDIR}/jsBSDCal.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/plib-jscal ${PREFIX}/bin

.include <bsd.port.post.mk>
