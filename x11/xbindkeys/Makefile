# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.5.5
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org

INSTALL_TARGET=	install-binPROGRAMS

.if defined(WITH_GUI)
RUN_DEPENDS=	wish:${PORTSDIR}/x11-toolkits/tk83
PLIST_SUB+=	WITH_GUI=""
SCRIPTS_ENV+=	WITH_GUI="YES"
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${X11BASE}/include"

MAN1=	xbindkeys.1
.if defined(WITH_GUI)
MAN1+=	 xbindkeys_show.1
.endif

pre-fetch:
.if !defined(WITH_GUI)
	@${ECHO} ""
	@${ECHO} "	Define WITH_GUI to install xbindkeys_show (requires Tk)"
	@${ECHO} ""
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif
	${INSTALL_MAN} ${WRKSRC}/xbindkeys.1 ${MANPREFIX}/man/man1
.if defined(WITH_GUI)
	${INSTALL_MAN} ${WRKSRC}/xbindkeys_show.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
