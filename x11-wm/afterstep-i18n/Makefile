# Created by: issei@jp.FreeBSD.org
# $FreeBSD$

PORTNAME=	afterstep-i18n
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP:S/$/:afterstep/} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://www.itlb.te.noda.tus.ac.jp/~manome/afterstep/archive/:i18n \
		http://www.itlb.te.noda.tus.ac.jp/~manome/afterstep/archive/icons/:icon
MASTER_SITE_SUBDIR=	archives/1.0/:afterstep kuriyama/:local
DISTNAME=	AfterStep-1.0
DISTFILES=	${DISTNAME}.tar.gz:afterstep,local \
		unofficial-I18N.98Feb27.tar.gz:local,i18n \
		kterm.xpm:icon kterm2.xpm:icon KTerm-AS.xpm:icon \
		netscape4.xpm:icon
EXTRACT_ONLY=	${DISTNAME}.tar.gz \
		unofficial-I18N.98Feb27.tar.gz

PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The NeXTstep clone window manager with Fontset support

RUN_DEPENDS=	asclock:${PORTSDIR}/x11-clocks/asclock

DEPRECATED=	Unmaintained since 2002
EXPIRATION_DATE=	2014-04-17
DIST_SUBDIR=	afterstep
USE_XORG=	xpm
USES=		imake
INSTALL_TARGET=	install install.man
MANCOMPRESSED=	yes
MAN1=		afterstep.1 Animate.1 Audio.1 Auto.1 Banner.1 Pager.1 Wharf.1
AFTERSTEPDIR=	${PREFIX}/lib/X11/afterstep
ICONDIR=	${PREFIX}/include/X11/pixmaps

SRCDIRS=	afterstep \
		modules/Animate modules/Audio modules/Auto \
		modules/Banner modules/Pager modules/Wharf \
		modules/Wharf/ASSound

NO_STAGE=	yes
pre-patch:
	@ ${PATCH} ${PATCH_DIST_ARGS} < ${WRKDIR}/as10+I18N.98Feb27.diff

post-patch:
	@ ${CP} ${WRKSRC}/sample.steprc ${WRKSRC}/sample.steprc.ja_JP.EUC
	@ ${PATCH} ${PATCH_DIST_ARGS} < ${FILESDIR}/steprc.ja.diff
	for i in ${SRCDIRS}; do \
		${REINPLACE_CMD} -e 's/#ifdef AlphaArchitecture/#if defined(AlphaArchitecture) \&\& !defined(FreeBSDArchitecture)/' ${WRKSRC}/$${i}/Imakefile ; \
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
	@ ${MKDIR} ${DOCSDIR}
.for i in CHANGES CREDITS README README.8bit INSTALL FAQ module-interface.txt
	${INSTALL_DATA} ${WRKSRC}/$i ${DOCSDIR}
.endfor
.for i in CHANGES.I18N README.I18N README.I18N.jis
	${INSTALL_DATA} ${WRKDIR}/$i ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
