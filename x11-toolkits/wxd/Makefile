# Created by: Jona Joachim <walkingshadow@grummel.net>
# $FreeBSD$

PORTNAME=	wxd
PORTVERSION=	0.14
PORTREVISION=	4
CATEGORIES=	x11-toolkits devel
MASTER_SITES=	SF/${PORTNAME}/wxD/${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	jochen@daten-chaos.de
COMMENT=	wxWidgets bindings for the D programming language

DEPRECATED=	Depends on deprecated lang/gdc
EXPIRATION_DATE=2013-09-01

BUILD_DEPENDS=	gdc:${PORTSDIR}/lang/gdc

USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_WX=		2.8
WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	UNICODE
OPTIONS_DEFAULT=	UNICODE

.include <bsd.port.options.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
BROKEN=		does not compile
.endif

.if ${PORT_OPTIONS:MUNICODE}
WX_UNICODE=	yes
.endif

pre-patch:
	@${RM} ${WRKSRC}/Makefile
	@${MV} ${WRKSRC}/GNUmakefile ${WRKSRC}/Makefile
	@${RM} ${WRKSRC}/wxc/Makefile
	@${MV} ${WRKSRC}/wxc/GNUmakefile ${WRKSRC}/wxc/Makefile
	@${RM} ${WRKSRC}/wx/Makefile
	@${MV} ${WRKSRC}/wx/GNUmakefile ${WRKSRC}/wx/Makefile

.include <bsd.port.mk>
