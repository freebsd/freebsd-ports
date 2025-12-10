PORTNAME=	xpra-html5
DISTVERSIONPREFIX=	v
DISTVERSION=	19
CATEGORIES=	x11

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Browser-based client for x11/xpra
WWW=		https://xpra.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli:archivers/brotli

USES=		python:build
USE_GITHUB=	yes
GH_ACCOUNT=	Xpra-org
USE_PYTHON=	noflavors

ETCDIR=		${PREFIX}/etc/xpra/html5-client
NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFAULT=	YUICOMPRESSOR
OPTIONS_RADIO=		MINIFIER
OPTIONS_RADIO_MINIFIER=	HJSMIN YUICOMPRESSOR

HJSMIN_DESC=		Minify JavaScript with hjsmin (Haskell)
MINIFIER_DESC=		JavaScript sources minification
YUICOMPRESSOR_DESC=	Minify JavaScript with yuicompressor (Java)

HJSMIN_BUILD_DEPENDS=	hjsmin:www/hs-hjsmin
HJSMIN_VARS=		minifier=hjsmin
YUICOMPRESSOR_BUILD_DEPENDS=	yuicompressor:www/yuicompressor
YUICOMPRESSOR_VARS=		minifier=yuicompressor

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MYUICOMPRESSOR} && !${PORT_OPTIONS:MHJSMIN}
MINIFIER=	copy
.endif

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install ${STAGEDIR} ${PREFIX}/share/xpra/www ${ETCDIR} ${MINIFIER}

.include <bsd.port.mk>
