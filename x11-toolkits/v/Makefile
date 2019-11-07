# Created by: Donald Burr <dburr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	v
PORTVERSION=	1.90
PORTREVISION=	7
CATEGORIES=	x11-toolkits devel graphics
MASTER_SITES=	SF/${PORTNAME}gui/V%20GUI/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}a-patch${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ GUI development framework for X11 and Microsoft Windows

USES=		compiler dos2unix gmake xorg
USE_XORG=	x11 xt xmu xaw
MAKE_ENV=	INSTALLDIR=${PREFIX} HOMEV=${WRKSRC}
# Build ignores CXXFLAGS
CFLAGS+=	${CFLAGS_${CHOSEN_COMPILER_TYPE}}
CFLAGS_clang=	-Wno-c++11-narrowing

WRKSRC=		${WRKDIR}/home/vgui

OPTIONS_DEFINE=	OPENGL # DOCS (commented out, see below)
OPTIONS_DEFAULT=	OPENGL

OPENGL_USES=	gl
OPENGL_USE=	GL=glu

post-patch:
# For gmake>=3.82
	@${REINPLACE_CMD} -e 's/^	cd/#	cd/' ${WRKSRC}/srcx/Makefile
# Fix parallel builds: call make(1) correctly, register target dependencies
	@${REINPLACE_CMD} -E 's/cd (.+) ; (\$$\(MAKE\))/\2 -C \1/' \
		${WRKSRC}/Makefile
	@${ECHO_CMD} test appgen iconed draw bmp2vbm examp drawex icons \
		tutor: srcx >> ${WRKSRC}/Makefile

do-configure:
	${CP} ${WRKSRC}/configs/ConfigX.mk ${WRKSRC}/Config.mk

pre-build:
	@${MKDIR} ${WRKSRC}/obj/bsd ${WRKSRC}/objm/bsd ${WRKSRC}/lib/bsd \
		${WRKSRC}/bin/bsd

post-build:
	${RANLIB} ${WRKSRC}/lib/libVx.a
	${RANLIB} ${WRKSRC}/lib/libVxgl.a

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/viconedx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/b2v ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/icondemox ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/protox ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tutappx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vdrawx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vdrawexx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vgenx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vtestlibx ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libVx.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libVxgl.a ${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/include/v
	${INSTALL_DATA} ${WRKSRC}/includex/v/*.h ${STAGEDIR}${PREFIX}/include/v
	${INSTALL_DATA} ${WRKSRC}/includex/v/*.cxx ${STAGEDIR}${PREFIX}/include/v

.include <bsd.port.mk>
