# New ports collection makefile for:	wdm
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdm
PORTVERSION=	1.25
PORTREVISION=	2
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://voins.program.ru/wdm/ \
		http://www.de.freebsd.org/de/gif/bsd/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPICS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	wdm

MAINTAINER=	kris@FreeBSD.org
COMMENT=	WINGs Display Manager; an xdm replacement

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		DEF_SERVER="${DEF_SERVER}"
CONFIGURE_ARGS=	--with-logdir=/var/log \
		--with-runlockdir=/var/run \
		--with-wdmdir=${WDMDIR} \
		--with-gfxdir=${WDMDIR}/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-Logo=beastie.xpm \
		--with-gfx-incs=${LOCALBASE}/include \
		--with-gfx-libs=${LOCALBASE}/lib \
		--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
		--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin \
		--with-wmlist=wmaker:afterstep:blackbox:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

MAN1=	wdm.1 wdmLogin.1

CPPFLAGS=	-I${LOCALBASE}/include -DCSRG_BASED -DHAS_SETUSERCONTEXT
LDFLAGS=	-L${LOCALBASE}/lib

DEF_SERVER?=	${X11BASE}/bin/X

WDMDIR=		${PREFIX}/lib/X11/wdm

DAEMONPICS=	beastie.xpm daemon1-HQ-1280x960.jpg

.include <bsd.port.pre.mk>

.if ( ${OSVERSION} >= 500028 ) && !defined(WITHOUT_PAM)
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
	@${REINPLACE_CMD} -e 's|$$(DESTDIR)$$(PAMDIR)/wdm||g ; \
		 s| -D | |g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-ldl||g ; \
		 s|/authdir||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@FAILSAFE@|@FAILSAFE_PATH@|g' ${WRKSRC}/configs/Xsession.in
	@${REINPLACE_CMD} -e \
		's|#configdir#|${WDMDIR}|g' ${WRKSRC}/doc/wdm.man.in
	@${REINPLACE_CMD} -e \
		's|/etc/X11/wdm|${WDMDIR}|g' ${WRKSRC}/doc/wdmLogin.man
	@${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/src/TestLogin/TestLogin.c

pre-install:
	@${MKDIR} ${WDMDIR}/pixmaps
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
.for file in ${DAEMONPICS}
	@${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${file} ${WDMDIR}/pixmaps
.endfor
.if defined(WITH_PAM)
.if ( ${OSVERSION} >= 500028 )
	${INSTALL_DATA} ${FILESDIR}/wdm.pam ${LOCALBASE}/etc/pam.d/wdm
.else
	@${ECHO_MSG} "To finish installing this port, append the contents of"
	@${ECHO_MSG} "${FILESDIR}/wdm.pam to your /etc/pam.conf file"
.endif
.endif

.include <bsd.port.post.mk>
