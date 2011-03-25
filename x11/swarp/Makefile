# Ports collection makefile for:	swarp
# Date created:				2008-01-15
# Whom:					Daniel Roethlisberger <daniel@roe.ch>
#
# $FreeBSD$
#

PORTNAME=	swarp
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://dl.suckless.org/tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 generic pointer warping utility

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_XORG=	x11
MAKE_ARGS=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lX11" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include \
			-DVERSION=\\\"${PORTVERSION}\\\"" \
		LD="${CC}"

PORTDOCS=	README
PLIST_FILES=	bin/swarp

post-patch:
	@${ECHO_CMD} -n > ${WRKSRC}/config.mk

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
