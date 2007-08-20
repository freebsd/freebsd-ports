# New ports collection makefile for:	sapphire
# Date created:		26 Jan 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	sapphire
PORTVERSION=	0.15.7
CATEGORIES=	x11-wm
MASTER_SITES=	SF

MAINTAINER=	thomas@goodking.ca
COMMENT=	Small window manager

USE_GMAKE=	yes
REINPLACE_ARGS=	-i'' -E
USE_X_PREFIX=	yes

post-extract:

post-patch:
	${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/data.inst
.for ii in data/menu/default data.inst sapphire.hh
	${REINPLACE_CMD} "s|/usr/local|${PREFIX}|g" ${WRKSRC}/${ii}
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
