# ex:ts=8
# New ports collection makefile for:	xbindkeys
# Date created:			Dec 29, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xbindkeys
PORTVERSION=	1.7.2
CATEGORIES=	x11
MASTER_SITES=	http://hocwp.free.fr/xbindkeys/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to launch shell commands under X with your keyboard

USE_XLIB=	yes
USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		xbindkeys.1

WISH=		${LOCALBASE}/bin/wish8.4

OPTIONS=	GUILE "Guile support" off \
		TCLTK "Tcl/Tk support" off

PEXAMPLESDIR=	${EXAMPLESDIR:S,^${PREFIX}/,,}
PLIST_FILES=	bin/xbindkeys ${PEXAMPLESDIR}/xbindkeysrc
PLIST_DIRS=	${PEXAMPLESDIR}

.include <bsd.port.pre.mk>

.if defined(WITH_GUILE)
LIB_DEPENDS+=	guile.15:${PORTSDIR}/lang/guile
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
