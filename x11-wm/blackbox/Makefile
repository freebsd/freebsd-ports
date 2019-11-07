# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	blackbox
PORTVERSION=	0.70.1
PORTREVISION=	6
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}wm/${PORTNAME}wm/Blackbox%20${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Small and fast window manager for X11R6

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		pathfix pkgconfig iconv xorg
USE_XORG=	x11 xft

GNU_CONFIGURE=	yes
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README.bbtools README.bsetbg
MANPAGES=	bsetbg.1 bsetroot.1

OPTIONS_DEFINE=	TOOLS_ONLY DOCS

TOOLS_ONLY_DESC=	Do not install window manager, only tools

TOOLS_ONLY_INSTALL_TARGET=	-C util install # XXX dirty hack :(
TOOLS_ONLY_MAKE_ARGS=		SUBDIRS="doc lib util" bin_PROGRAMS=bsetroot
TOOLS_ONLY_VARS=		PKGNAMESUFFIX=-tools \
				COMMENT+="(tools only)"
TOOLS_ONLY_VARS_OFF=		PORTDOCS+="AUTHORS COMPLIANCE ChangeLog README RELNOTES TODO"

.include <bsd.port.options.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_Toolbar.cc
.endif

post-patch:
# Fix the build with libX11 > 1.40
	@${REINPLACE_CMD} -e 's/_XUTIL_H_/_X11&/' ${WRKSRC}/lib/Util.hh

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${STAGEDIR}${DOCSDIR}

post-install-TOOLS_ONLY-on:
	@${REINPLACE_CMD} -E '/[^s]\/blackbox|bstyleconvert|lib|include/d' \
		${TMPPLIST}
	${INSTALL_MAN} ${MANPAGES:S#^#${WRKSRC}/doc/#} ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
