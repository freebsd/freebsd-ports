# New ports collection makefile for:    v
# Date created:         8 Feb 1998
# Whom:                 Donald Burr <dburr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	v
PORTVERSION=	1.90
PORTREVISION=	3
CATEGORIES=	x11-toolkits devel graphics
MASTER_SITES=	SF/${PORTNAME}gui/V%20GUI/${PORTVERSION}
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}a-patch${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ GUI development framework for X11 and Microsoft Windows

WRKSRC=		${WRKDIR}/home/vgui

USE_XORG=	x11 xt xmu xaw
USE_GMAKE=	YES
MAKE_ENV=	INSTALLDIR=${PREFIX} HOMEV=${WRKSRC}
USE_DOS2UNIX=	yes

.include <bsd.port.pre.mk>

.if ${ARCH} == "alpha"
BROKEN=		compiler error in function fixup_memory_subreg
.endif

do-configure:
	${CP} ${WRKSRC}/configs/ConfigX.mk ${WRKSRC}/Config.mk

pre-build:
	${MKDIR} ${WRKSRC}/obj/bsd ${WRKSRC}/objm/bsd ${WRKSRC}/lib/bsd ${WRKSRC}/bin/bsd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/viconedx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/b2v ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/icondemox ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/protox ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/tutappx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vdrawx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vdrawexx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vgenx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/vtestlibx ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/lib/libVx.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/lib/libVxgl.a ${PREFIX}/lib
	${MKDIR} ${PREFIX}/include/v
	${INSTALL_DATA} ${WRKSRC}/includex/v/*.h ${PREFIX}/include/v
	${INSTALL_DATA} ${WRKSRC}/includex/v/*.cxx ${PREFIX}/include/v

post-install:
	${RANLIB} ${PREFIX}/lib/libVx.a
	${RANLIB} ${PREFIX}/lib/libVxgl.a
#.ifdef NOPORTDOCS
#	@${ECHO_MSG} "==> Extra documentation WILL NOT be installed."
#.else
#	@${ECHO_MSG} "==> Installing extra docs under ${PREFIX}/share/doc/v..."
##	${MKDIR} ${PREFIX}/share/doc/v
#	${CP} -R ${WRKSRC}/doc/* ${PREFIX}/share/doc/v
#	${FIND} ${PREFIX}/share/doc/v -type d -exec ${CHMOD} 755 {} \;
#	${FIND} ${PREFIX}/share/doc/v -type f -exec ${CHMOD} 644 {} \;
#	@${ECHO_MSG} "==> Extra docs installed.  Note, you will need *tex to read 'em."
#.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
