# ex:ts=8
# Ports collection makefile for:	xbindkeys_config
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys_config
PORTVERSION=	0.1.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy to use gtk program for configuring Xbindkeys

USE_GNOME=	gtk12
USE_REINPLACE=	yes
MAKE_ENV=	CC="${CC} ${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s,gtk-config,${GTK_CONFIG},g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
