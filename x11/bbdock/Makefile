# New ports collection makefile for:	bbdock
# Date created:		July 31, 2006
# Whom:			Francis Bacque <idroxid01@yahoo.fr>
#
# $FreeBSD$
#

PORTNAME=		bbdock
PORTVERSION=		0.2.8
PORTREVISION=	2
CATEGORIES=		x11
MASTER_SITES=		http://bbdock.nethence.com/download/

MAINTAINER=		idroxid01@yahoo.fr
COMMENT=		BBDock displays one or more PNG icons in the BlackBox/FluxBox slit

LIB_DEPENDS=		png:${PORTSDIR}/graphics/png

PORTDOCS=		README
GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=		yes
USE_XORG=		ice sm x11 xau xcursor xdmcp xext xfixes xi

PLIST_FILES=		bin/bbdock

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
