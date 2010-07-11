# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.8.3
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@eitanadler.com
COMMENT=	Allows you to launch shell commands under X with your keyboard

OPTIONS=	GUILE "Guile support" off \
		TCLTK "Tcl/Tk support" off

USE_XORG=	x11 xi
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xbindkeys.1
PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc
PLIST_DIRS=	%%EXAMPLESDIR%%

WISH=		${LOCALBASE}/bin/wish8.4

.include <bsd.port.pre.mk>

.if defined(WITH_GUILE)
LIB_DEPENDS+=	guile.20:${PORTSDIR}/lang/guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if defined(WITH_TCLTK)
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
MAN1+=		xbindkeys_show.1
PLIST_FILES+=	bin/xbindkeys_show
.else
CONFIGURE_ARGS+=	--disable-tk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${EXAMPLESDIR}

.include <bsd.port.post.mk>
