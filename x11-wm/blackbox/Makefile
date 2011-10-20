# New ports collection makefile for:	Blackbox
# Date created:				June 15, 1998
# Whom:					Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	blackbox
PORTVERSION=	0.70.1
PORTREVISION=	4
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}wm/${PORTNAME}wm/Blackbox%20${PORTVERSION}

MAINTAINER=	A.J.Caines@halplant.com
COMMENT=	A small and fast window manager for X11R6

LICENSE=	MIT

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_GNOME=	gnomehack pkgconfig
USE_XORG=	x11 xft

MAN1=		bsetbg.1 bsetroot.1
PORTDOCS=	README.bbtools README.bsetbg

OPTIONS=	TOOLS_ONLY "Do not install window manager, only tools" off

.include <bsd.port.options.mk>

.if defined(WITH_TOOLS_ONLY)
PKGNAMESUFFIX=	-tools
COMMENT+=	(tools only)
MAKE_ARGS=	SUBDIRS="doc lib util" bin_PROGRAMS=bsetroot
INSTALL_TARGET=	-C util install		# XXX dirty hack :(
.else
MAN1+=		blackbox.1
PORTDOCS+=	AUTHORS COMPLIANCE ChangeLog README RELNOTES TODO
.endif

post-patch:
# Fix the build with libX11 > 1.40
	@${REINPLACE_CMD} -e 's/_XUTIL_H_/_X11&/' ${WRKSRC}/lib/Util.hh

post-install:
.if defined(WITH_TOOLS_ONLY)
	@${REINPLACE_CMD} -E '/[^s]\/blackbox|bstyleconvert|lib|include/d' \
		${TMPPLIST}
	${INSTALL_MAN} ${MAN1:S#^#${WRKSRC}/doc/#} ${MANPREFIX}/man/man1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S#^#${WRKSRC}/#} ${DOCSDIR}
.endif

.include <bsd.port.mk>
