PORTNAME=	thingylaunch
DISTVERSION=	4.0.0
CATEGORIES=	x11
MASTER_SITES=	https://code.ptrcrt.ch/${PORTNAME}/tarball/${DISTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight launcher for X
WWW=		https://code.ptrcrt.ch/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		compiler:c++11-lib pkgconfig xorg
USE_XORG=	x11 xorgproto

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} '/^CXXFLAGS/s|-O3||' ${WRKSRC}/Makefile

.include <bsd.port.mk>
