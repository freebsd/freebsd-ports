# ex:ts=8
# New ports collection makefile for:	motif
# Date created:		5 December 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	open-motif
PORTVERSION=	2.2.2
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://openmotif.opengroup.org/pub/%SUBDIR%/ \
		ftp://ftp.opengroup.org/pub/%SUBDIR%/ \
		ftp://ftp.kddlabs.co.jp/X11/%SUBDIR%/
MASTER_SITE_SUBDIR=	openmotif/R${PORTVERSION:R}/tars
DISTNAME=	openmotif-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	openmotif

MAINTAINER=	steve@FreeBSD.org
COMMENT=	Motif X11 Toolkit (industry standard GUI (IEEE 1295))

CONFLICTS=	lesstif-*
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-DCSRG_BASED -DXUSE_MTSAFE_API -DXNO_MTSAFE_PWDAPI"
INSTALLS_SHLIB=	yes
MAKE_ENV=	LANG=C

DEMOS_SRC=	${WRKSRC}/demos/programs

.ifdef USE_MOTIF
.error You have `USE_MOTIF' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} >= 4
RUN_DEPENDS=	imake:${PORTSDIR}/devel/imake-4
.endif

# User config option: Build and install Motif demos
.if defined(WITHOUT_OPENMOTIF_DEMOS)
PLIST_SUB+=	MOTIF_DEMOS="@comment "
.else
MAKE_ENV+=	DEMOS="demos"
PLIST_SUB+=	MOTIF_DEMOS=""
.endif

.include "${.CURDIR}/Makefile.man"

post-patch:
	@${FIND} ${DEMOS_SRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^install-data-am: |install-data-am: # |g'
# fix sections
	@${FIND} ${WRKSRC}/doc/man/man1 -name '*.1' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|user cmd|1|'
	@${FIND} ${WRKSRC}/doc/man/man3 -name '*.3' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|library call|3|'
# mwmrc is not a kernel interface!!
	@cd ${WRKSRC}/doc/man && ${CP} -f man4/mwmrc.4 man5/mwmrc.5
	@${FIND} ${WRKSRC}/doc/man/man5 -name '*.5' -maxdepth 1 | \
		${XARGS} ${REINPLACE_CMD} -e 's|special file|5| ; \
		 s|file formats|5|'

post-install:
.if !defined(WITHOUT_OPENMOTIF_DEMOS)
#
	${INSTALL_DATA} ${DEMOS_SRC}/Combo2/Combo.ad \
		${PREFIX}/lib/X11/app-defaults/Combo
	${INSTALL_DATA} ${DEMOS_SRC}/filemanager/XmdFilemanager.ad \
		${PREFIX}/lib/X11/app-defaults/XmdFilemanager
	${INSTALL_DATA} ${DEMOS_SRC}/i18ninput/XmdI18nInput.ad \
		${PREFIX}/lib/X11/app-defaults/XmdI18nInput
	${INSTALL_DATA} ${DEMOS_SRC}/periodic/XmdPeriodic.ad \
		${PREFIX}/lib/X11/app-defaults/XmdPeriodic
	${INSTALL_DATA} ${DEMOS_SRC}/setdate/XmdSetDate.ad \
		${PREFIX}/lib/X11/app-defaults/XmdSetDate
	${INSTALL_DATA} ${DEMOS_SRC}/todo/XmdTodo.ad \
		${PREFIX}/lib/X11/app-defaults/XmdTodo
#
	@${MKDIR} ${PREFIX}/lib/X11/help
.for i in filemanager getsubres i18ninput sampler2_0 todo
	${INSTALL_DATA} ${DEMOS_SRC}/${i}/${i}.help \
		${PREFIX}/lib/X11/help/${i}.help
.endfor
#
	@${MKDIR} ${PREFIX}/lib/X11/uid
	${INSTALL_DATA} ${DEMOS_SRC}/fileview/French.uid \
		${PREFIX}/lib/X11/uid/French.uid
	${INSTALL_DATA} ${DEMOS_SRC}/fileview/German.uid \
		${PREFIX}/lib/X11/uid/German.uid
	${INSTALL_DATA} ${DEMOS_SRC}/fileview/English.uid \
		${PREFIX}/lib/X11/uid/English.uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotif/hellomotif.uid \
		${PREFIX}/lib/X11/uid/hellomotif.uid
	${INSTALL_DATA} ${DEMOS_SRC}/periodic/periodic.uid \
		${PREFIX}/lib/X11/uid/periodic.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/C/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/C/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/C/uid/l_strings.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/english/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/english/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/english/uid/l_strings.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/french/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/french/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/french/uid/l_strings.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/hebrew/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/hebrew/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/hebrew/uid/l_strings.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/japanese/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/japanese/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/japanese/uid/l_strings.uid
	@${MKDIR} ${PREFIX}/lib/X11/uid/swedish/uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/swedish/uid/l_strings.uid \
		${PREFIX}/lib/X11/uid/swedish/uid/l_strings.uid
	${INSTALL_DATA} ${DEMOS_SRC}/hellomotifi18n/helloint.uid \
		${PREFIX}/lib/X11/uid
#
.for i in earth filemanager getsubres i18ninput panner piano sampler2_0 todo
	${INSTALL_MAN} ${DEMOS_SRC}/${i}/${i}.man \
		${MANPREFIX}/man/man1/${i}.1
.endfor
	${INSTALL_MAN} ${DEMOS_SRC}/popups/autopopups.man \
		${MANPREFIX}/man/man1/autopopups.1
	${INSTALL_MAN} ${DEMOS_SRC}/setdate/setDate.man \
		${MANPREFIX}/man/man1/setDate.1
.endif
#
	@${MKDIR} ${DOCSDIR}
.for i in BUGREPORT COPYRIGHT.MOTIF README RELNOTES
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.if !defined(NOPORTDOCS)
.for i in CLOSEDBUGS OPENBUGS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>
