# New ports collection makefile for:   qvwm
# Version required:    1.0b4c
# Date created:        30 Sep 1996
# Whom:                Yukihiro Nakai<nakai@mlab.t.u-tokyo.ac.jp>
#
# $Id: porting.sgml,v 1.25 1996/08/01 00:12:11 asami Exp $
#

DISTNAME=       qvwm-1.0b4c
CATEGORIES+=    x11
MASTER_SITES=   ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/

MAINTAINER=     nakai@mlab.t.u-tokyo.ac.jp

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=      yes

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/qvwm ${PREFIX}/bin
	@ ${MKDIR} -p ${PREFIX}/lib/X11/qvwm/pixmaps
	@ for pix in ${WRKSRC}/pixmaps/* ;do \
		${INSTALL_DATA} $$pix ${PREFIX}/lib/X11/qvwm/pixmaps; done
	@ ${INSTALL_DATA} ${WRKSRC}/system.qvwmrc ${PREFIX}/lib/X11/qvwm
	@ # For Japanese Kanji users
	@ ${INSTALL_DATA} ${WRKSRC}/kanji.qvwmrc ${PREFIX}/lib/X11/qvwm
.if !defined(NOPORTDOCS)
	@ ${MKDIR} -p ${PREFIX}/share/doc/qvwm
	@ ${INSTALL_DATA} ${FILESDIR}/*.en ${PREFIX}/share/doc/qvwm
.endif


.include <bsd.port.mk>
