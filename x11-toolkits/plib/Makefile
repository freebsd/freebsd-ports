PORTNAME=	plib
PORTVERSION=	1.8.5
PORTREVISION=	8
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://plib.sourceforge.net/dist/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Portable library for joystick/sound/OpenGL GUI/3D math
WWW=		http://plib.sourceforge.net/

LICENSE=	LGPL20
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gl gmake localbase:ldflags xorg
CPE_VENDOR=	${PORTNAME}_project
USE_GL=		glu
USE_XORG=	xt xi xmu xext x11

GNU_CONFIGURE=	yes

CXXFLAGS+=	-fPIC
LDFLAGS+=	-lpthread

EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src-js-jsBSD.cxx

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400091
CPPFLAGS+=  -Dregister=
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread||g ; \
		 s|-ldl||g ; \
		 s|-lc_r||g' ${WRKSRC}/configure
	@${ECHO} "JS component is not compiled with new usb stack"

post-build:
	${CC} ${CFLAGS} -o ${WRKDIR}/plib-jscal ${FILESDIR}/jsBSDCal.c

post-install:
	${INSTALL_PROGRAM} ${WRKDIR}/plib-jscal ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
