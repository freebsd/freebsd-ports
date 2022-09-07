PORTNAME=	xpra-html5
PORTVERSION=	5.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	x11

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Browser-based client for x11/xpra
WWW=		https://xpra.org/

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	brotli:archivers/brotli

USES=		python:3.6+,build

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
ETCDIR=		${PREFIX}/etc/xpra/html5-client

do-install:
	cd ${WRKSRC} && ${PYTHON_CMD} setup.py install ${STAGEDIR} ${PREFIX}/share/xpra/www ${ETCDIR} ${MINIFIER}

.include <bsd.port.mk>
