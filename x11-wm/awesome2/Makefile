# New ports collection makefile for:   awesome
# Date created:                September 26, 2007
# Whom:                        Nikos Ntarmos <ntarmos@ceid.upatras.gr>
#
# $FreeBSD$
#

PORTNAME=	awesome
PORTVERSION=	1.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://awesome.naquadah.org/download/

MAINTAINER=	ntarmos@ceid.upatras.gr
COMMENT=	A tiling window manager initialy based on a dwm code rewriting

LIB_DEPENDS=	config.4:${PORTSDIR}/devel/libconfig

USE_XLIB=	yes

MAN1=		awesome.1
PLIST_FILES=	bin/awesome
PORTDOCS=	AUTHORS LICENSE README
PORTEXAMPLES=	awesomerc

OPTIONS=	LWRFLT "Support lowering of floating windows" on \
		WARP "Support mouse warping" on

.include <bsd.port.pre.mk>

.if defined(WITH_LWRFLT)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-lowerfloat
.endif

.if defined(WITH_WARP)
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-warp
.endif

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

.include <bsd.port.post.mk>
