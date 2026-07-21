PORTNAME=	awww
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	https://codeberg.org/LGFae/${PORTNAME}/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Answer to your Wayland Wallpaper Woes
WWW=		https://codeberg.org/LGFae/awww

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc \
		wayland-protocols>=1.44:graphics/wayland-protocols \
		wayland>=1.23.1:graphics/wayland
LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		cargo pkgconfig shebangfix

SHEBANG_FILES=	example_scripts/*.sh

CARGO_INSTALL_PATH=	client daemon

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

EXAMPLES_RUN_DEPENDS=	bash:shells/bash

post-build:
	${WRKSRC}/doc/gen.sh

post-install:
	cd ${WRKSRC}/doc/generated && \
		${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/share/man/man1/

post-install-EXAMPLES-on:
	cd ${WRKSRC}/example_scripts && \
		${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
