# Created by: ijliao
# $FreeBSD$

PORTNAME=	xbindkeys
PORTVERSION=	1.8.6
PORTREVISION=	1
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

PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc man/man1/xbindkeys.1.gz
PLIST_DIRS=	%%EXAMPLESDIR%%

WISH=		${LOCALBASE}/bin/wish8.4

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUILE}
LIB_DEPENDS+=	libguile.so:${PORTSDIR}/lang/guile
.else
CONFIGURE_ARGS+=	--disable-guile
.endif

.if ${PORT_OPTIONS:MTCL}
RUN_DEPENDS+=	wish8.4:${PORTSDIR}/x11-toolkits/tk84
PLIST_FILES+=	bin/xbindkeys_show man/man1/xbindkeys_show.1.gz
.else
CONFIGURE_ARGS+=	--disable-tk
.endif

post-patch:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
