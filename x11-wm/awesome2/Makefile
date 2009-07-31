# New ports collection makefile for:   awesome2
# Date created:                February 26, 2009
# Whom:                        Nikos Ntarmos <ntarmos@cs.uoi.gr>
#
# $FreeBSD$
#

PORTNAME=	awesome2
PORTVERSION=	2.3.6
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/
DISTNAME=	awesome-${PORTVERSION}

MAINTAINER=	ntarmos@cs.uoi.gr
COMMENT=	A tiling window manager initially based on a dwm code rewriting

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	confuse.0:${PORTSDIR}/devel/libconfuse \
		cairo.2:${PORTSDIR}/graphics/cairo \
		freetype.9:${PORTSDIR}/print/freetype2

USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_EFL=	imlib2
USE_GNOME=	pango
USE_XORG=	x11 xft xext xinerama xt xrandr xproto

MAN1=		awesome2.1 \
		awesome2-client.1 \
		awesome2-menu.1 \
		awesome2-message.1
MAN5=		awesome2rc.5
PORTDOCS=	AUTHORS LICENSE README STYLE UPGRADE
PORTEXAMPLES=	awesomerc

post-patch:
	@${REINPLACE_CMD} -e 's, "$$(DESTDIR)$$(docdir)";,;,g' \
			  -e 's,\([[:space:]]\)install-docDATA ,\1,g' \
			  -e 's,awesome_,awesome2_,g' \
			  -e 's,awesomerc\.5,awesome2rc\.5,g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e  "s,PACKAGE='awesome',PACKAGE='awesome2',g" \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e  "s,awesomerc,awesome2rc,g" \
		${WRKSRC}/common/configopts.c
.	for man in ${MAN1} ${MAN5}
		@${MV} ${WRKSRC}/${man:S%awesome2%awesome%}.txt ${WRKSRC}/${man}.txt
		@${REINPLACE_CMD} -e 's,awesome,awesome2,g' \
				  -e 's,\~/\.awesome2,~/.awesome,g' \
			${WRKSRC}/${man}.txt
.	endfor

post-configure:
	@${REINPLACE_CMD} -E '/^awesome2_(message_)?LDADD/s/$$/ -liconv/g; \
			      /^doc_DATA/s/=.*$$/=/g' \
		${WRKSRC}/Makefile

post-install:
.	if !defined(NOPORTDOCS)
		@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
		@${MKDIR} ${DOCSDIR}
.		for doc in ${PORTDOCS}
			${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.		endfor
.	endif
.	if !defined(NOPORTEXAMPLES)
		@${ECHO_MSG} "installing example config file to ${EXAMPLESDIR}"
		@${MKDIR} ${EXAMPLESDIR}
.		for example in ${PORTEXAMPLES}
			${INSTALL_DATA} ${WRKSRC}/${example} ${EXAMPLESDIR}
.		endfor
.	endif

.include <bsd.port.mk>
