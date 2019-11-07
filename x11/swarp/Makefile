# Created by: Daniel Roethlisberger <daniel@roe.ch>
# $FreeBSD$

PORTNAME=	swarp
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	X11 generic pointer warping utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		xorg
USE_XORG=	x11
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lX11" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include \
			-DVERSION=\\\"${PORTVERSION}\\\"" \
		LD="${CC}"

PORTDOCS=	README
PLIST_FILES=	bin/swarp

OPTIONS_DEFINE=	DOCS

post-patch:
	@${ECHO_CMD} -n > ${WRKSRC}/config.mk

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
