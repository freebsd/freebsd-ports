# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION=	0.15.8
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/OldFiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small window manager

USE_XORG=	x11 xext
USE_GMAKE=	yes
REINPLACE_ARGS=	-i '' -e
CC=		${CXX}

post-extract:

post-patch:
	${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/data.inst
.for ii in data/menu/default windowmanager.cc
	${REINPLACE_CMD} "s|/usr|${PREFIX}|g" ${WRKSRC}/${ii}
.endfor
	${CP} ${WRKSRC}/data.inst ${WRKSRC}/sapphire.inst

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sapphire.inst ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/sapphire/menu
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu
	# so the sapphire-themes port can restore the original menu when the
	# themes are de-installed
	${INSTALL_DATA} ${WRKSRC}/data/menu/default ${PREFIX}/share/sapphire/menu/default.orig
	@${MKDIR} ${PREFIX}/share/sapphire/themes
	${INSTALL_DATA} ${WRKSRC}/data/themes/*.theme ${PREFIX}/share/sapphire/themes
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
.endif

.include <bsd.port.mk>
