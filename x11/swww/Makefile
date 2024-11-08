PORTNAME=	swww
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Solution to your Wayland Wallpaper Woes
WWW=		https://github.com/LGFae/swww

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc
LIB_DEPENDS+=	liblz4.so:archivers/liblz4

USES=		cargo shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	LGFae

SHEBANG_FILES=	example_scripts/*.sh

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_RUN_DEPENDS=	bash:shells/bash

post-build:
	${WRKSRC}/doc/gen.sh

post-install:
	${INSTALL_PROGRAM} ${CARGO_TARGET_DIR}/release/swww-daemon \
		${STAGEDIR}${PREFIX}/bin/
	(cd ${WRKSRC}/doc/generated && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/share/man/man1/)

post-install-EXAMPLES-on:
	(cd ${WRKSRC}/example_scripts && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
