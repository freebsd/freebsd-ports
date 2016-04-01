# Created by: ijliao
# $FreeBSD$

PORTNAME=	xbindkeys
PORTVERSION=	1.8.6
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/xbindkeys/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows you to launch shell commands under X with your keyboard

LICENSE=	GPLv2

OPTIONS_DEFINE=	GUILE TCL

USE_XORG=	x11 xi
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc man/man1/xbindkeys.1.gz

TCL_USES=		tk
TCL_CONFIGURE_OFF=	--disable-tk
TCL_PLIST_FILES=	bin/xbindkeys_show man/man1/xbindkeys_show.1.gz
GUILE_LIB_DEPENDS=	libguile.so:lang/guile
GUILE_CONFIGURE_OFF=	--disable-guile

post-patch:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
