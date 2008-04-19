# New ports collection makefile for:   awesome
# Date created:                September 26, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	awesome
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A tiling window manager initially based on a dwm code rewriting

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse \
		cairo.2:${PORTSDIR}/graphics/cairo \
		freetype.9:${PORTSDIR}/print/freetype2

USE_XORG=	x11 xft xext xinerama xt xrandr xproto

MAN1=		awesome.1 \
		awesome-client.1
PLIST_FILES=	bin/awesome \
		bin/awesome-client
PORTDOCS=	AUTHORS LICENSE README
PORTEXAMPLES=	awesomerc

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} "installing example config file to ${EXAMPLESDIR}"
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_MAN} ${WRKSRC}/awesomerc ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
