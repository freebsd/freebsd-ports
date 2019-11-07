# Created by: gahr
# $FreeBSD$

PORTNAME=	obpager
PORTVERSION=	1.8
CATEGORIES=	x11-wm
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight pager for netwm compatible window managers

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:textproc/gsed

USES=		compiler gmake xorg
USE_XORG=	x11 xext

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing
MAKE_ARGS=	CDEFS="${CXXFLAGS}"
PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g; \
	    s|%%LOCALBASE%%|${LOCALBASE}|g; \
	    s|%%CXX%%|${CXX}|g; \
	    s|sed|gsed|g' ${WRKSRC}/Makefile
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
