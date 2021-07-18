PORTNAME=	xpra-html5
PORTVERSION=	4.2
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Browser-based client for x11/xpra

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli:archivers/brotli

USES=		python:3.6+

OPTIONS_DEFINE=		MINIFY
OPTIONS_DEFAULT=	MINIFY

MINIFY_DESC=		Minify JavaScript source files
MINIFY_BUILD_DEPENDS=	yuicompressor:www/yuicompressor
MINIFY_VARS=		minifier=yuicompressor
MINIFY_VARS_OFF=	minifier=copy

USE_PYTHON=	noflavors

USE_GITHUB=	yes
GH_ACCOUNT=	Xpra-org

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install ${STAGEDIR}${PREFIX}/share/xpra/www ${MINIFIER}

.include <bsd.port.mk>
