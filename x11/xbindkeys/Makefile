PORTNAME=	xbindkeys
PORTVERSION=	1.8.7
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.nongnu.org/xbindkeys/

MAINTAINER=	guru@unixarea.de
COMMENT=	Allows you to launch shell commands under X with your keyboard
WWW=		https://www.nongnu.org/xbindkeys/xbindkeys.html

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		xorg
USE_XORG=	x11 xi
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

PLIST_FILES=	bin/xbindkeys %%EXAMPLESDIR%%/xbindkeysrc share/man/man1/xbindkeys.1.gz

OPTIONS_DEFINE=	GUILE TCL

TCL_USES=		tk
TCL_CONFIGURE_OFF=	--disable-tk
TCL_PLIST_FILES=	bin/xbindkeys_show share/man/man1/xbindkeys_show.1.gz
GUILE_USES=		guile:1.8,2.2,3.0 autoreconf gettext-tools pkgconfig
GUILE_CONFIGURE_ENABLE=	guile

post-patch-TCL-on:
	@${REINPLACE_CMD} -e 's| wish | ${WISH} |g' ${WRKSRC}/xbindkeys_show

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/xbindkeysrc ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
