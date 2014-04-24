# $FreeBSD$

PORTNAME=	herbstluftwm
PORTVERSION=	0.6.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://herbstluftwm.org/tarballs/

MAINTAINER=	crshd@mail.com
COMMENT=	Manual tiling window manager for X11

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USES=		gmake pkgconfig
USE_XORG=	x11 xinerama
USE_GNOME=	glib20

MAKE_ARGS=	PREFIX=${PREFIX} SYSCONFDIR=${PREFIX}/etc \
		DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR} \
		MANDIR=${PREFIX}/man

OPTIONS_DEFINE=	BASH ZSH DOCS EXAMPLES
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

post-patch:
	${REINPLACE_CMD} -e '/-[LI]\/usr/s,/usr,${LOCALBASE},' \
		${WRKSRC}/config.mk
	${REINPLACE_CMD} -e '/LICENSEDIR/d' ${WRKSRC}/Makefile
	${GREP} -Rl --null '^#!/bin/bash' ${WRKSRC} | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's,/bin/bash,/usr/bin/env bash,'
.if ! ${PORT_OPTIONS:MBASH}
	${REINPLACE_CMD} -e '/BASHCOMPLETIONDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MZSH}
	${REINPLACE_CMD} -e '/ZSHCOMPLETIONDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/DOCDIR/d' ${WRKSRC}/Makefile
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	${REINPLACE_CMD} -e '/EXAMPLESDIR/d' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
