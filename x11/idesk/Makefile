PORTNAME=	idesk
PORTVERSION=	0.7.9
CATEGORIES=	x11

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Place launch icons and background directly on your desktop
WWW=		https://github.com/neagix/idesk

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libImlib2.so:graphics/imlib2 \
		libXft.so:x11-fonts/libXft

USE_GITHUB=	yes
GH_ACCOUNT=	neagix
GH_TAGNAME=	15f0b51dc7c7adbdf191481423793d7726fa8fab

USES=		autoreconf gmake localbase:ldflags pkgconfig \
		tar:bzip2 xorg
USE_XORG=	ice sm x11

GNU_CONFIGURE=	yes

MAKE_ARGS=	cc="${CXX}" \
		cflags="${CXXFLAGS}"
SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=		DOCS SHAPE SN
OPTIONS_DEFAULT=	SHAPE

SHAPE_DESC=	Support of XShape extension
SN_DESC=	Startup notification support

SHAPE_USE=		XORG=xext
SHAPE_CONFIGURE_ENABLE=	shape

SN_LIB_DEPENDS=		libstartup-notification-1.so:x11/startup-notification
SN_CONFIGURE_ON=	--enable-libsn

post-patch:
	${REINPLACE_CMD} -e 's|0.7.8|${PORTVERSION}|g' ${WRKSRC}/configure.ac

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/idesk ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
