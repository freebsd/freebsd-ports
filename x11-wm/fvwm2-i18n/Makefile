# New ports collection makefile for:	Internationalized fvwm2
# Version required:	2.0.45
# Date created:		02 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>,
#			based on Hidekazu Kuroki's work of 2.0.43.
#
# $Id: Makefile,v 1.8 1997/03/04 09:38:40 asami Exp $
#

DISTNAME=	fvwm-2.0.45
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/ \
		ftp://ftp.hpc.uh.edu/pub/fvwm/version-2/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm-users-jp-kits.97Jan24.tar.gz

MAINTAINER=	matusita@jp.freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

# filenames.
PATCH_FIXIT=	kits/patch/fix-2.0.45
PATCH_I18N=	kits/patch/PATCH.I18N

USE_PATCHFILES=	${PATCH_FIXIT} ${PATCH_I18N}

pre-patch:
	@for i in ${USE_PATCHFILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$i; \
	 done;

post-install:
	@${MKDIR} ${PREFIX}/lib/X11/fvwm2/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm \
		${PREFIX}/lib/X11/fvwm2/pixmaps

.include <bsd.port.mk>
