# ex:ts=8
# Ports collection makefile for:	xbindkeys_config
# Date created:			Mar 4, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys_config
PORTVERSION=	0.0.3
CATEGORIES=	x11
MASTER_SITES=	http://www.netchampagne.com/xbindkeys_config/

MAINTAINER=	ports@FreeBSD.org

USE_GTK=	yes
MAKE_ENV=	CC="${CC} ${CFLAGS}"

post-patch:
	@${PERL} -pi -e "s,gtk-config,${GTK_CONFIG},g ; \
		s,^CC,#CC,g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
