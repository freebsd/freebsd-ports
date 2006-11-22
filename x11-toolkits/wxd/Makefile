# New ports collection makefile for:   wxd
# Date created:        29 August 2006
# Whom:                Jona Joachim <walkingshadow@grummel.net>
#
# $FreeBSD$
#

PORTNAME=	wxd
PORTVERSION=	0.08
CATEGORIES=	x11-toolkits devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=		.tgz

MAINTAINER=	walkingshadow@grummel.net
COMMENT=	wxWidgets bindings for the D programming language

BUILD_DEPENDS=	gdc:${PORTSDIR}/lang/gdc

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_WX=		2.6
WX_UNICODE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

pre-patch:
	@${RM} ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/wxc/Makefile
	@${MV} ${WRKSRC}/wxc/GNUmakefile ${WRKSRC}/wxc/Makefile
	@${RM} ${WRKSRC}/wx/Makefile
	@${MV} ${WRKSRC}/wx/GNUmakefile ${WRKSRC}/wx/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	@${CP} -R ${WRKSRC}/Samples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	needs FreeBSD 5.x or later
.endif

.include <bsd.port.post.mk>
