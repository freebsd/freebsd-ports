# Created by: ijliao
# $FreeBSD$

PORTNAME=	xbindkeys
PORTVERSION=	1.8.6
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/xbindkeys/

MAINTAINER=	guru@unixarea.de
COMMENT=	Allows you to launch shell commands under X with your keyboard

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_XORG=	x11 xi
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc man/man1/xbindkeys.1.gz

OPTIONS_DEFINE=	GUILE TCL

TCL_USES=		tk
TCL_CONFIGURE_OFF=	--disable-tk
TCL_PLIST_FILES=	bin/xbindkeys_show man/man1/xbindkeys_show.1.gz
GUILE_LIB_DEPENDS=	libguile.so:lang/guile
GUILE_CONFIGURE_OFF=	--disable-guile

post-patch-TCL-on:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
