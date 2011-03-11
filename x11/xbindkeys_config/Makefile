# ex:ts=8
# Ports collection makefile for:	xbindkeys_config
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys_config
PORTVERSION=	0.1.3
PORTREVISION=	9
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy to use gtk program for configuring Xbindkeys

DEPRECATED=	Upstream disapear and distfile is no more available
EXPIRATION_DATE=	2011-05-01

RUN_DEPENDS=	${LOCALBASE}/bin/xbindkeys:${PORTSDIR}/x11/xbindkeys

USE_GNOME=	gtk20
CC+=		${CFLAGS}

PLIST_FILES=	bin/xbindkeys_config

post-patch:
	@${REINPLACE_CMD} -e "s,gtk-config,pkg-config gtk+-2.0,g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
