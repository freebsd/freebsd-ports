# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dwm
PORTVERSION=	6.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/ \
		http://schot.a-eskwadraat.nl/files/
PATCH_SITES=	http://dwm.suckless.org/patches/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	Dynamic, small, fast and simple window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig

OPTIONS_DEFINE=	XINERAMA DOCS
OPTIONS_DEFAULT=XINERAMA

XINERAMA_USE=	XORG=xinerama

USE_XORG=	x11 xft

PLIST_FILES=	bin/dwm \
		man/man1/dwm.1.gz
PORTDOCS=	README

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-${PORTVERSION} config.h-files may not work."

post-extract:
	@if [ -e "${DWM_CONF}" ]; then \
		${ECHO_MSG} "creating config.h from ${DWM_CONF}"; \
		${CP} "${DWM_CONF}" ${WRKSRC}/config.h; \
	fi

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX},g"

post-patch-XINERAMA-off:
	@${REINPLACE_CMD} -e 's,$${XINERAMALIBS},,g' \
	         -e 's,$${XINERAMAFLAGS},,g' ${WRKSRC}/config.mk

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
