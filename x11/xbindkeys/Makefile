# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.4.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	obraun@informatik.unibw-muenchen.de

INSTALL_TARGET=	install-binPROGRAMS install-man

.if defined(WITH_GUI)
RUN_DEPENDS=	wish:${PORTSDIR}/x11-toolkits/tk83
PLIST_SUB+=	WITH_GUI=""
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include"

MAN1=	xbindkeys.1 xbindkeys_show.1

pre-fetch:
.if !defined(WITH_GUI)
	@${ECHO} ""
	@${ECHO} "	Define WITH_GUI to install xbindkeys_show (requires Tk)"
	@${ECHO} ""
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
