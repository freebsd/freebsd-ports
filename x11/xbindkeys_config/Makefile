# ex:ts=8
# Ports collection makefile for:	xbindkeys_config
# Date created:			Mar 4, 2002 # Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys_config
PORTVERSION=	0.1.3
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	trevor

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An easy to use gtk program for configuring Xbindkeys

PLIST_FILES=	bin/xbindkeys_config
USE_GNOME=	gtk20
MAKE_ENV=	CC="${CC} ${CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s,gtk-config,pkg-config gtk+-2.0,g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
