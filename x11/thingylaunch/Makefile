PORTNAME=	thingylaunch
DISTVERSION=	3.0.3
CATEGORIES=	x11
MASTER_SITES=	https://code.ptrcrt.ch/${PORTNAME}/tarball/${DISTVERSION}/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Lightweight launcher for X
WWW=		https://code.ptrcrt.ch/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		compiler:c++11-lib pkgconfig xorg
USE_XORG=	xorgproto xcb
LIB_DEPENDS+=	libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-keysyms.so:x11/xcb-util-keysyms

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} '/^CXXFLAGS/s|-O3||' ${WRKSRC}/Makefile

.include <bsd.port.mk>
