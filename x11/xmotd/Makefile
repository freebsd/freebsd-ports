# New ports collection makefile for:	xmotd
# Date created:		29 January 2001
# Whom:			Matthew West <mwest@uct.ac.za>
#
# $FreeBSD$
#

PORTNAME=	xmotd
PORTVERSION=	1.16
CATEGORIES=	x11
MASTER_SITES=	http://www.ee.ryerson.ca/~elf/pub/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A message-of-the-day browser for X11 and dumb-terminals

USE_IMAKE=	yes
USE_PERL5_BUILD=yes
NO_INSTALL_MANPAGES=	yes
XFREE86_HTML_MAN=	no

MAN8=		xmotd.8
PLIST_FILES=	bin/xmotd

.if defined(USE_HTML)
MAKE_ARGS+=	-DHAVE_HTML
.endif

.if defined(USE_MOTIF)
MAKE_ARGS+=	-DMOTIF
.endif

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	USE_HTML=yes	uses HTML widget instead of ASCII text"
	@${ECHO} "	USE_MOTIF=yes	uses Motif widget library"
	@${ECHO} "	USE_XPM=yes	allows colour XPM pixmaps"
	@${ECHO} ""

post-extract:
	@${TOUCH} ${WRKSRC}/xmotd.man

post-patch:
	@${PERL} -pi -e 's:/usr/local/bin/::g' ${WRKSRC}/xmotd.8
.for file in libhtmlw/HTML-PSformat.c main.c textmode.c xmotd.c
	@${PERL} -pi -e 's:malloc.h:stdlib.h:' ${WRKSRC}/${file}
.endfor
.if defined(USE_HTML)
	@${PERL} -pi.orig -e 's:XCOMM #define HAVE_HTML:#define HAVE_HTML:g' ${WRKSRC}/Imakefile
.endif
.if defined (USE_MOTIF)
	@${PERL} -pi.orig -e 's:XCOMM #define MOTIF:#define MOTIF:g' ${WRKSRC}/Imakefile
.endif
.if defined(USE_XPM)
	@${PERL} -pi.orig -e 's:XCOMM #define HAVE_XPM:#define HAVE_XPM:g' ${WRKSRC}/Imakefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmotd ${X11BASE}/bin/xmotd
	${INSTALL_MAN} ${WRKSRC}/xmotd.8 ${MANPREFIX}/man/man8

.include <bsd.port.mk>
