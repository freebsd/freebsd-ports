# New ports collection makefile for:	afterstep-i18n
# Version required:	1.0
# Date created:		23 October 1998
# Whom:			issei@jp.FreeBSD.ORG
#
# $Id: Makefile,v 1.3 1998/11/19 22:03:49 kuriyama Exp $
#

DISTNAME=	AfterStep-1.0
PKGNAME=	afterstep-i18n-1.0
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.afterstep.org/archives/ \
		http://www.freebsd.org/~kuriyama/distfiles/ \
		http://www.itlb.te.noda.sut.ac.jp/~manome/afterstep/archive/ \
		http://www.itlb.te.noda.sut.ac.jp/~manome/afterstep/archive/icons/
DISTFILES=      ${DISTNAME}.tar.gz \
		unofficial-I18N.98Feb27.tar.gz \
		kterm.xpm kterm2.xpm KTerm-AS.xpm netscape4.xpm

PATCH_DIST_STRIP=       -p1

MAINTAINER=	issei@jp.FreeBSD.ORG

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm

EXTRACT_ONLY=	${DISTNAME}.tar.gz \
		unofficial-I18N.98Feb27.tar.gz
DIST_SUBDIR=	afterstep
USE_X_PREFIX=	yes
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 asclock.1 Animate.1 Audio.1 Auto.1 Banner.1 \
		Pager.1 Wharf.1
AFTERSTEPDIR=	${PREFIX}/lib/X11/afterstep
ICONDIR=	${PREFIX}/include/X11/pixmaps

SRCDIRS=	afterstep \
		modules/Animate modules/Audio modules/Auto \
		modules/Banner modules/Pager modules/Wharf \
		modules/Wharf/ASSound

pre-patch:
	@ ${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/as10+I18N.98Feb27.diff

post-patch:
	@ ${CP} ${WRKSRC}/sample.steprc ${WRKSRC}/sample.steprc.ja_JP.EUC
	@ ${PATCH} ${PATCH_DIST_ARGS} < ${FILESDIR}/steprc.ja.diff
	@ for i in ${SRCDIRS}; do \
		cd ${WRKSRC}/$$i; \
		mv Imakefile Imakefile.orig; \
		sed -e 's/#ifdef AlphaArchitecture/#if defined(AlphaArchitecture) \&\& !defined(FreeBSDArchitecture)/' < Imakefile.orig  >  Imakefile; \
	done

pre-build:
	@ cd ${WRKSRC}; ${SH} MakeMakefiles

post-install:
	@ ${MKDIR} ${AFTERSTEPDIR}/backgrounds
	${INSTALL_DATA} ${WRKSRC}/backgrounds/* ${AFTERSTEPDIR}/backgrounds
	@ ${MKDIR} ${AFTERSTEPDIR}/sounds
	${INSTALL_DATA} ${WRKSRC}/sounds/* ${AFTERSTEPDIR}/sounds
	@ ${MKDIR} ${PREFIX}/include/X11/pixmaps
	${INSTALL_DATA} ${WRKSRC}/icons/*.xpm ${ICONDIR}
	${INSTALL_DATA} ${_DISTDIR}/kterm.xpm ${ICONDIR}
	${INSTALL_DATA} ${_DISTDIR}/kterm2.xpm ${ICONDIR}
	${INSTALL_DATA} ${_DISTDIR}/KTerm-AS.xpm ${ICONDIR}
	${INSTALL_DATA} ${_DISTDIR}/netscape4.xpm ${ICONDIR}/ja-netscape4.xpm
	${INSTALL_DATA} ${WRKSRC}/sample.steprc.ja_JP.EUC ${AFTERSTEPDIR}/system.steprc.ja_JP.EUC

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${PREFIX}/share/doc/afterstep
.for i in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/doc/afterstep
.endfor
.for i in CHANGES.I18N README.I18N README.I18N.jis
	${INSTALL_DATA} ${WRKDIR}/$i ${PREFIX}/share/doc/afterstep
.endfor
.endif

.include <bsd.port.mk>
