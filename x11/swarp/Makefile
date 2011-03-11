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
MASTER_SITES=	http://www.suckless.org/download/ \
		http://mirror.roe.ch/dist/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 generic pointer warping utility

MAKE_ARGS=	LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -lX11" \
		CFLAGS="${CFLAGS} -I${LOCALBASE}/include \
			-DVERSION=\\\"${PORTVERSION}\\\"" \
		LD=${CC}

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

USE_XORG=	x11
PLIST_FILES=	bin/swarp
PORTDOCS=	README

post-patch:
	@${ECHO} -n > ${WRKSRC}/config.mk

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
