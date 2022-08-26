PORTNAME=	ittywm
DISTVERSION=	g20180507
CATEGORIES=	x11-wm

MAINTAINER=	pyrus@bsdmail.com
COMMENT=	Ridiculously tiny libxcb window manager

LICENSE=	PD
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		localbase xorg
USE_GITHUB=	yes
GH_ACCOUNT=	marshallmason
GH_TAGNAME=	cc290ed
USE_XORG=	xau xcb xdmcp

PLIST_FILES=	bin/${PORTNAME}

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${LIBS} -o ${WRKSRC}/${PORTNAME} ${WRKSRC}/ittywm.c -lxcb

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
