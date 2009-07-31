# New ports collection makefile for:   wxd
# Date created:        29 August 2006
# Whom:                Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	wxd
PORTVERSION=	0.14
PORTREVISION=	1
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	jochen@daten-chaos.de
COMMENT=	wxWidgets bindings for the D programming language

BUILD_DEPENDS=	gdc:${PORTSDIR}/lang/gdc

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_WX=		2.8
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS=	UNICODE "Build the Unicode version" On

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		does not compile
.endif

.if !defined(WITHOUT_UNICODE)
WX_UNICODE=	yes
.endif

pre-patch:
	@${RM} ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/wxc/Makefile
	@${MV} ${WRKSRC}/wxc/GNUmakefile ${WRKSRC}/wxc/Makefile
	@${RM} ${WRKSRC}/wx/Makefile
	@${MV} ${WRKSRC}/wx/GNUmakefile ${WRKSRC}/wx/Makefile

.include <bsd.port.post.mk>
