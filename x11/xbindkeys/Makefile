# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.6.2
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
INSTALL_TARGET=	install-binPROGRAMS

MAN1=	xbindkeys.1

.if defined(WITH_GUI)
RUN_DEPENDS=	wish8.3:${PORTSDIR}/x11-toolkits/tk83
MAN1+=		xbindkeys_show.1
PLIST_SUB+=	WITH_GUI=""
SCRIPTS_ENV+=	WITH_GUI="YES"
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

pre-everything::
.if !defined(WITH_GUI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	Define WITH_GUI to install xbindkeys_show (requires Tk)"
	@${ECHO_MSG} ""
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/xbindkeys.1 ${MANPREFIX}/man/man1
.if defined(WITH_GUI)
	${INSTALL_MAN} ${WRKSRC}/xbindkeys_show.1 ${MANPREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
