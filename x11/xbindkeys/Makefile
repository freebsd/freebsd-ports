# Created by: ijliao
# $FreeBSD$

PORTNAME=	xbindkeys
PORTVERSION=	1.8.5
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/xbindkeys/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	Allows you to launch shell commands under X with your keyboard

LICENSE=	GPLv2

OPTIONS_DEFINE=	GUILE TCL

USE_XORG=	x11 xi
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN1=		xbindkeys.1
PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc
PLIST_DIRS=	%%EXAMPLESDIR%%

WISH=		${LOCALBASE}/bin/wish8.4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	guile:${PORTSDIR}/lang/guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if ${PORT_OPTIONS:MTCL}
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

.include <bsd.port.mk>
