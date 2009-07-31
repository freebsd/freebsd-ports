# New ports collection makefile for:	wdm
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdm
PORTVERSION=	1.28
PORTREVISION=	7
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://voins.program.ru/wdm/:wdm \
		http://wolfram.schneider.org/bsd/gif/bsd/:pic_large \
		${MASTER_SITE_LOCAL:S/$/:pic_small/}
MASTER_SITE_SUBDIR=	tg/:pic_small
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:wdm \
		beastie.xpm:pic_small \
		daemon1-HQ-1280x960.jpg:pic_large
DIST_SUBDIR=	wdm
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	xride@FreeBSD.org
COMMENT=	WINGs Display Manager; an xdm replacement

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker

NOT_FOR_ARCHS=	sparc64

USE_XORG=	x11 xmu
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		DEF_SERVER="${DEF_SERVER}" XRDB_PATH="${XRDB_PATH}"
CONFIGURE_ARGS=	--with-logdir=/var/log \
		--with-runlockdir=/var/run \
		--with-wdmdir=${WDMDIR} \
		--with-gfxdir=${WDMDIR}/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-Logo=beastie.xpm \
		--with-gfx-incs=${LOCALBASE}/include \
		--with-gfx-libs=${LOCALBASE}/lib \
		--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${LOCALBASE}/bin \
		--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${LOCALBASE}/bin \
		--with-wmlist=wmaker:afterstep:blackbox:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

MAN1=	wdm.1 wdmLogin.1

CPPFLAGS=	-I${LOCALBASE}/include -DCSRG_BASED -DHAS_SETUSERCONTEXT
LDFLAGS=	-L${LOCALBASE}/lib -lintl

DEF_SERVER?=	${LOCALBASE}/bin/X
XRDB_PATH?=	${LOCALBASE}/bin/xrdb

WDMDIR=		${PREFIX}/lib/X11/wdm

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_PAM)
WITH_PAM=	yes
CONFIGURE_ARGS+=	--with-pamdir=${LOCALBASE}/etc/pam.d/
PLIST_SUB+=	PAM=""
.else
PLIST_SUB+=	PAM="@comment "
.endif

.if !defined(WITH_PAM)
CONFIGURE_ARGS+=	--disable-pam
.endif

pre-everything::
.if !defined(WITH_PAM)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with PAM support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_PAM=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g' ${WRKSRC}/configs/KillConsole
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g' ${WRKSRC}/configs/Xclients.in
	@${REINPLACE_CMD} -e \
		's|/usr/X11R6|${PREFIX}|g' ${WRKSRC}/configs/Xsession.in
	@${REINPLACE_CMD} -e \
		's|$$(DESTDIR)$$(PAMDIR)/wdm||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g ; \
		 s|/authdir||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@FAILSAFE@|@FAILSAFE_PATH@|g' ${WRKSRC}/configs/Xsession.in
	@${REINPLACE_CMD} -e \
		's|#configdir#|${WDMDIR}|g' ${WRKSRC}/doc/wdm.man.in
	@${REINPLACE_CMD} -e \
		's|/etc/X11/wdm|${WDMDIR}|g' ${WRKSRC}/doc/wdmLogin.man

pre-install:
.if exists(${WDMDIR}/wdm-config)
	${MV} ${WDMDIR}/wdm-config ${WDMDIR}/wdm-config.preserve
.endif
.if exists(${WDMDIR}/Xsetup_0)
	${MV} ${WDMDIR}/Xsetup_0 ${WDMDIR}/Xsetup_0.preserve
.endif

post-install:
	@${CP} ${WDMDIR}/wdm-config ${WDMDIR}/wdm-config.dist
.if exists(${WDMDIR}/wdm-config.preserve)
	${MV} ${WDMDIR}/wdm-config.preserve ${WDMDIR}/wdm-config
.endif
	@${CP} ${WDMDIR}/Xsetup_0 ${WDMDIR}/Xsetup_0.dist
.if exists(${WDMDIR}/Xsetup_0.preserve)
	${MV} ${WDMDIR}/Xsetup_0.preserve ${WDMDIR}/Xsetup_0
.endif
.for file in beastie.xpm daemon1-HQ-1280x960.jpg
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WDMDIR}/pixmaps
.endfor
.if defined(WITH_PAM)
	${INSTALL_DATA} ${FILESDIR}/wdm.pam ${LOCALBASE}/etc/pam.d/wdm
.endif

.include <bsd.port.post.mk>
