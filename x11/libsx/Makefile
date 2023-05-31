PORTNAME=	libsx
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	XCONTRIB/libraries
DISTNAME=	${PORTNAME}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple X11 library

LIB_DEPENDS=	libXaw3d.so:x11-toolkits/Xaw3d

USES=		tar:Z xorg
USE_XORG=	x11 xaw xext xmu xt

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	src freq

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=       -Wno-error=int-conversion
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/src/libsx.a  ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/freq/libfreq.a  ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/X11/libsx
	${INSTALL_DATA} ${WRKSRC}/src/libsx.h ${STAGEDIR}${PREFIX}/include/X11/libsx
	${INSTALL_DATA} ${WRKSRC}/freq/freq.h ${STAGEDIR}${PREFIX}/include/X11/libsx

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/doc/libsx
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${PREFIX}/share/doc/libsx
	${GZIP_CMD} ${STAGEDIR}${PREFIX}/share/doc/libsx/*.doc

.include <bsd.port.post.mk>
