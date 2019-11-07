# Created by: Matthew West <mwest@uct.ac.za>
# $FreeBSD$

PORTNAME=	xmotd
DISTVERSION=	1.17.3b
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://www.ee.ryerson.ca/~elf/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Message-of-the-day browser for X11 and dumb-terminals

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GNU

USES=		imake:noman xorg
USE_XORG=	ice sm x11 xaw xext xmu xt

PLIST_FILES=	bin/xmotd \
		man/man8/xmotd.8.gz

OPTIONS_DEFINE=	HTML MOTIF XPM

HTML_DESC=		Use HTML widget instead of ASCII text
HTML_MAKE_ARGS=		-DHAVE_HTML
HTML_BROKEN=		Does not compile when WITH_HTML is set

MOTIF_MAKE_ARGS=	-DMOTIF
MOTIF_USES=		motif

XPM_USE=		XORG=xpm

post-extract:
	@${TOUCH} ${WRKSRC}/xmotd.man

post-patch:
	@${REINPLACE_CMD} -e 's:/usr/local/bin/::g' ${WRKSRC}/xmotd.8
.for file in libhtmlw/HTML-PSformat.c main.c textmode.c xmotd.c
	@${REINPLACE_CMD} -e 's:malloc.h:stdlib.h:' ${WRKSRC}/${file}
.endfor

post-patch-HTML-on:
	@${REINPLACE_CMD} -e 's:XCOMM #define HAVE_HTML:#define HAVE_HTML:g' ${WRKSRC}/Imakefile

post-patch-MOTIF-on:
	@${REINPLACE_CMD} -e 's:XCOMM #define MOTIF:#define MOTIF:g' ${WRKSRC}/Imakefile

post-patch-XPM-on:
	@${REINPLACE_CMD} -e 's:XCOMM #define HAVE_XPM:#define HAVE_XPM:g' ${WRKSRC}/Imakefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmotd ${STAGEDIR}${LOCALBASE}/bin/xmotd
	${INSTALL_MAN} ${WRKSRC}/xmotd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
