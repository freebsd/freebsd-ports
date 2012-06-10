# New ports collection makefile for:	slim
# Date created:				8 Jan 2006
# Whom:					Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$

PORTNAME=	slim
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	http://slim.berlios.de/releases/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.release.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	henry.hu.sh@gmail.com
COMMENT=	Graphical login manager for X11, derived from Login.app

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		ck-connector.0:${PORTSDIR}/sysutils/consolekit \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

LICENSE=	GPLv2

USE_CMAKE=	yes
USE_XORG=	x11 xft xmu xorg-server xrender
USE_GL=		glut
USE_RC_SUBR=	slim.sh
SUB_FILES=	pkg-message

CMAKE_ARGS=	-DUSE_CONSOLEKIT=yes

MAN1=		slim.1

.include <bsd.port.pre.mk>

verify: checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.release.asc

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' ${WRKSRC}/${PORTNAME}.conf
	@${REINPLACE_CMD} -e 's|"/etc"|"${PREFIX}/etc"|' \
	    -e 's|slim.conf|slim.conf.sample|' \
	    -e 's|set(MANDIR "$${CMAKE_INSTALL_PREFIX}/share/man")|set(MANDIR "${PREFIX}/man")|' \
	    ${WRKSRC}/CMakeLists.txt
	@${MV} ${WRKSRC}/slim.conf ${WRKSRC}/slim.conf.sample
	@${REINPLACE_CMD} -e 's|std::snprintf|snprintf|' ${WRKSRC}/Ck.cpp

# Fix a previous bad install
pre-install:
	@/bin/rm -f ${LOCALBASE}/share/man/man1/slim.1
	@/bin/rmdir ${LOCALBASE}/share/man/man1 2>/dev/null || true
	@/bin/rmdir ${LOCALBASE}/share/man 2>/dev/null || true

post-install:
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
	@if [ ! -f ${PREFIX}/etc/slim.conf ]; then \
		${CP} ${PREFIX}/etc/slim.conf.sample ${PREFIX}/etc/slim.conf ; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
