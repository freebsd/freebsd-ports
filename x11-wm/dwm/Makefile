# Created by: Jeroen Schot <schot@a-eskwadraat.nl>
# $FreeBSD$

PORTNAME=	dwm
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/ \
		http://schot.a-eskwadraat.nl/files/
PATCH_SITES=	http://dwm.suckless.org/patches/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	Dynamic, small, fast and simple window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs

OPTIONS_DEFINE=	XINERAMA XFT DOCS
OPTIONS_DEFAULT=XINERAMA

USE_XORG=	x11 xau xcb xdmcp xext

MAN1=		dwm.1
PLIST_FILES=	bin/dwm
PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXINERAMA}
USE_XORG+=	xinerama
.endif

.if ${PORT_OPTIONS:MXFT}
LIB_DEPENDS+=	freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig
USE_XORG+=	xft xrender
PATCHFILES+=	${PORTNAME}-${PORTVERSION}-xft.diff
.endif

pre-everything::
	@${ECHO_MSG} "You can build dwm with your own config.h using the DWM_CONF knob:"
	@${ECHO_MSG} "make DWM_CONF=/path/to/dwm/config.h install clean"
	@${ECHO_MSG} "Note: Pre-6.0 config.h-files no longer work."

post-extract:
.if defined(DWM_CONF)
	@${ECHO_MSG} "creating config.h from ${DWM_CONF}"
	@${CP} ${DWM_CONF} ${WRKSRC}/config.h
.endif

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC}|${XARGS} ${REINPLACE_CMD} \
	         -e "s,%%PREFIX%%,${PREFIX},g" \
	         -e "s,%%LOCALBASE%%,${LOCALBASE},g" \
	         -e "s,%%MANPREFIX%%,${MANPREFIX},g"
.if empty(PORT_OPTIONS:MXINERAMA)
	@${REINPLACE_CMD} -e 's,$${XINERAMALIBS},,g' \
	         -e 's,$${XINERAMAFLAGS},,g' ${WRKSRC}/config.mk
.endif
.if empty(PORT_OPTIONS:MXFT)
	@${REINPLACE_CMD} -e 's,$${XFTLIBS},,g' \
	         -e 's,$${XFTINCS},,g' ${WRKSRC}/config.mk
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
