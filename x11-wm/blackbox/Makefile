# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	blackbox
PORTVERSION=	0.70.1
PORTREVISION=	5
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}wm/${PORTNAME}wm/Blackbox%20${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	Small and fast window manager for X11R6

LICENSE=	MIT

GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig iconv
USE_XORG=	x11 xft
LDFLAGS+=	${ICONV_LIB}

PORTDOCS=	README.bbtools README.bsetbg

OPTIONS_DEFINE=		TOOLS_ONLY
TOOLS_ONLY_DESC=	Do not install window manager, only tools

.include <bsd.port.options.mk>

.if ${ARCH} == "armv6" || ${ARCH} == "armv6hf"
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-src_Toolbar.cc
.endif

.if ${PORT_OPTIONS:MTOOLS_ONLY}
PKGNAMESUFFIX=	-tools
COMMENT+=	(tools only)
MAKE_ARGS=	SUBDIRS="doc lib util" bin_PROGRAMS=bsetroot
INSTALL_TARGET=	-C util install		# XXX dirty hack :(
.else
PORTDOCS+=	AUTHORS COMPLIANCE ChangeLog README RELNOTES TODO
.endif

post-patch:
# Fix the build with libX11 > 1.40
	@${REINPLACE_CMD} -e 's/_XUTIL_H_/_X11&/' ${WRKSRC}/lib/Util.hh

post-install:
.if ${PORT_OPTIONS:MTOOLS_ONLY}
	@${REINPLACE_CMD} -E '/[^s]\/blackbox|bstyleconvert|lib|include/d' \
		${TMPPLIST}
	${INSTALL_MAN} ${MAN1:S#^#${WRKSRC}/doc/#} ${STAGEDIR}${MANPREFIX}/man/man1
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
