# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.0.1
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include"

MAN1=	xbindkeys.1 xbindkeys_show.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
