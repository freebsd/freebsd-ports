# New ports collection makefile for:   dwm
# Date created:                July 24, 2006
# Whom:                        Jeroen Schot <schot@a-eskwadraat.nl>
#
# $FreeBSD$
#

PORTNAME=	dwm
PORTVERSION=	6.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://dl.suckless.org/${PORTNAME}/ \
		http://schot.a-eskwadraat.nl/files/

MAINTAINER=	schot@a-eskwadraat.nl
COMMENT=	A dynamic, small, fast and simple window manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

OPTIONS=	XINERAMA	"Enable Xinerama support" On

USE_XORG=	x11

MAN1=		dwm.1
PLIST_FILES=	bin/dwm
PORTDOCS=	README

.include <bsd.port.options.mk>

.if defined(WITH_XINERAMA)
USE_XORG+=	xinerama
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
.if defined(WITHOUT_XINERAMA)
	@${REINPLACE_CMD} -e 's,$${XINERAMALIBS},,g' \
	         -e 's,$${XINERAMAFLAGS},,g' ${WRKSRC}/config.mk
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
