# New ports collection makefile for:	Internationalized fvwm2
# Version required:	2.0.45
# Date created:		02 Mar 1997
# Whom:			Makoto Matsushita <matusita@jp.freebsd.org>,
#			based on Hidekazu Kuroki's work of 2.0.43.
#
# $Id: Makefile,v 1.5 1997/03/03 11:31:40 asami Exp $
#

DISTNAME=	fvwm-2.0.45
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/sources/2.0.x/ \
		ftp://ftp.ics.es.osaka-u.ac.jp/pub/CFAN/fvwm-users-jp/kits/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/sources/2.0.x/ \
		ftp://ftp.TokyoNet.AD.JP/pub/X/fvwm/fvwm-users-jp/kits/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} fvwm-users-jp-kits.97Jan24.tar.gz

MAINTAINER=	matusita@jp.freebsd.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes

# filenames.
PATCH_FIXIT=	kits/patch/fix-2.0.45
PATCH_I18N=	kits/patch/PATCH.i18n-jp
PATCH_MAN=	kits/doc/diffs-fvwm.man
TARBALL_SWDESK=	kits/tool/swdesk.tar.gz

USE_PATCHFILES=	${PATCH_FIXES} ${PATCH_I18N} ${PATCH_MAN}
SWDESKDIR=	${WRKDIR}/swdesk

# targets for swdesk
post-extract:
	@(cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${TARBALL_SWDESK} ${EXTRACT_AFTER_ARGS})

pre-patch:
	@for i in ${USE_PATCHFILES}; do \
		${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/$$i; \
	 done;

post-configure:
	@(cd ${SWDESKDIR} && ${XMKMF})

post-build:
	@(cd ${SWDESKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${ALL_TARGET})

post-install:
	@(cd ${SWDESKDIR} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${INSTALL_TARGET})
.endif
	@${MKDIR} ${PREFIX}/lib/X11/${FVWMNAME}/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm \
		${PREFIX}/lib/X11/${FVWMNAME}/pixmaps

.include <bsd.port.mk>
