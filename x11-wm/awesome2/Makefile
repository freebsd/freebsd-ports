# Created by: Nikos Ntarmos <ntarmos@cs.uoi.gr>
# $FreeBSD$

PORTNAME=	awesome2
PORTVERSION=	2.3.6
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/
DISTNAME=	awesome-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiling window manager initially based on a dwm code rewriting

BUILD_DEPENDS=	asciidoc:${PORTSDIR}/textproc/asciidoc \
		xmlto:${PORTSDIR}/textproc/xmlto
LIB_DEPENDS=	libconfuse.so:${PORTSDIR}/devel/libconfuse \
		libcairo.so:${PORTSDIR}/graphics/cairo \
		libfreetype.so:${PORTSDIR}/print/freetype2

USES=		iconv pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	PYTHON=${PYTHON_CMD}
USE_EFL=	imlib2
USE_GNOME=	pango
USE_PYTHON_BUILD=	yes
USE_XORG=	x11 xft xext xinerama xt xrandr xproto
LDFLAGS+=	-lX11 -lXext ${ICONV_LIB}

MAN1=		awesome2.1 \
		awesome2-client.1 \
		awesome2-menu.1 \
		awesome2-message.1
MAN5=		awesome2rc.5
PORTDOCS=	AUTHORS LICENSE README STYLE UPGRADE
PORTEXAMPLES=	awesomerc

OPTIONS_DEFINE=	DOCS EXAMPLES

NO_STAGE=	yes

.include <bsd.port.options.mk>

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
	@${REINPLACE_CMD} -E '/^awesome2_(message_)?LDADD/s/$$/ ${ICONV_LIB}/g; \
			      /^doc_DATA/s/=.*$$/=/g' \
		${WRKSRC}/Makefile

post-install:
.	if ${PORT_OPTIONS:MDOCS}
		@${ECHO_MSG} "installing additional documentation to ${DOCSDIR}"
		@${MKDIR} ${DOCSDIR}
.		for doc in ${PORTDOCS}
			${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.		endfor
.	endif
.	if ${PORT_OPTIONS:MEXAMPLES}
		@${ECHO_MSG} "installing example config file to ${EXAMPLESDIR}"
		@${MKDIR} ${EXAMPLESDIR}
.		for example in ${PORTEXAMPLES}
			${INSTALL_DATA} ${WRKSRC}/${example} ${EXAMPLESDIR}
.		endfor
.	endif

.include <bsd.port.mk>
