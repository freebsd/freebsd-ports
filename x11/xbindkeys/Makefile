# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.6.5
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to launch shell commands under X with your keyboard

USE_XLIB=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=	xbindkeys.1

WISH=		${LOCALBASE}/bin/wish8.4

.if defined(WITH_GUI)
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
MAN1+=		xbindkeys_show.1
PLIST_SUB+=	WITH_GUI=""
.else
CONFIGURE_ARGS+=	--disable-tk
PLIST_SUB+=	WITH_GUI="@comment "
.endif

pre-everything::
.if !defined(WITH_GUI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	Define WITH_GUI to install xbindkeys_show (requires Tk)"
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
