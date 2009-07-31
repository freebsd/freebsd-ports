# New ports collection makefile for:	epiwm
# Date created:				2002-06-04
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	epiwm
PORTVERSION=	0.5.6
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.nongnu.org/epiwm/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another fast, small, configurable window manager

USE_XORG=	x11 xpm
USE_GNOME=	imlib
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/X11/epiwm|${PREFIX}/etc/epiwm|' \
		${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ii in AUTHORS BUGS ChangeLog EPIwm-0.5.6.lsm COPYING INSTALL NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
