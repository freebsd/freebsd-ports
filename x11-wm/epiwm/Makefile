# New ports collection makefile for:	epiwm
# Date created:				2002-06-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	epiwm
PORTVERSION=	0.5.6
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.nongnu.org/epiwm/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another fast, small, configurable window manager

LIB_DEPENDS=	Imlib.5:${PORTSDIR}/graphics/imlib \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif

CONFIG=		icons key menu start style window workspace
DOCS=		AUTHORS BUGS COPYING ChangeLog EPIwm-0.5.6.lsm INSTALL NEWS \
		README TODO
GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes

post-patch:
	${REINPLACE_CMD} 's|/etc/X11/epiwm|${PREFIX}/etc/epiwm|' \
	    ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
