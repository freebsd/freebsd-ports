# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.7.1
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to launch shell commands under X with your keyboard

USE_XLIB=	yes
USE_GNOME=	gnometarget
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xbindkeys.1

WISH=		${LOCALBASE}/bin/wish8.4

OPTIONS=	GUILE "Guile support" off \
		TCLTK "Tcl/Tk support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GUILE)
LIB_DEPENDS+=	guile.15:${PORTSDIR}/lang/guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if defined(WITH_TCLTK)
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
MAN1+=		xbindkeys_show.1
PLIST_SUB+=	TCLTK=""
.else
CONFIGURE_ARGS+=	--disable-tk
PLIST_SUB+=	TCLTK="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
