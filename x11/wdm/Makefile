# New ports collection makefile for:	wdm
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdm
PORTVERSION=	1.20
PORTREVISION=	3
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.tcscs.com/wdm/wdm/ \
		http://www.de.freebsd.org/de/gif/bsd/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tg
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPICS}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kris@FreeBSD.org

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker \
		PropList.2:${PORTSDIR}/devel/libPropList

DIST_SUBDIR=	wdm
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_AUTOMAKE_VER=14
AUTOMAKE_ARGS=	--include-deps
DEF_SERVER?=	${X11BASE}/bin/X
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-DCSRG_BASED -DHAS_SETUSERCONTEXT" \
		LIBS="-L${LOCALBASE}/lib ${LIBPAM}" \
		DEF_SERVER="${DEF_SERVER}"
CONFIGURE_ARGS=	--with-logdir=/var/log \
		--with-runlockdir=/var/run \
		--with-wdmdir=${PREFIX}/lib/X11/wdm \
		--with-Logo=beastie.xpm \
		--with-gfx-incs=${X11BASE}/include/WINGs \
		--with-gfx-libs=${X11BASE}/lib \
		--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
		--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin \
		--with-wmlist=wmaker:afterstep:blackbox:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
CFLAGS+=	-DHAVE_XINERAMA
CONFIGURE_ENV+=	LIBS="-Wl,-export-dynamic ${X11BASE}/lib/libXinerama.a"
.endif

MAN1=	wdm.1 wdmLogin.1

DAEMONPICS=	beastie.xpm daemon1-HQ-1280x960.jpg

.if ( ${OSVERSION} >= 500028 ) && !defined(WITHOUT_PAM)
WITH_PAM=	yes
.endif

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam --with-pamdir=${LOCALBASE}/etc/pam.d/
LIBPAM=		-lpam
PLIST_SUB+=	PAM=""
.else
PLIST_SUB+=	PAM="@comment "

pre-everything::
	@${ECHO_MSG} "To build this port with PAM support, define \"WITH_PAM\"."
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/*.man

pre-install:
	@if [ -e ${PREFIX}/lib/X11/wdm/wdm-config ]; then \
		${MV} ${PREFIX}/lib/X11/wdm/wdm-config \
			${PREFIX}/lib/X11/wdm/wdm-config.preserve; \
	fi
	@if [ -e ${PREFIX}/lib/X11/wdm/Xsetup_0 ]; then \
		${MV} ${PREFIX}/lib/X11/wdm/Xsetup_0 \
			${PREFIX}/lib/X11/wdm/Xsetup_0.preserve; \
	fi

post-install:
	@${CP} ${PREFIX}/lib/X11/wdm/wdm-config \
		${PREFIX}/lib/X11/wdm/wdm-config.dist
	@if [ -e ${PREFIX}/lib/X11/wdm/wdm-config.preserve ]; then \
		${MV} ${PREFIX}/lib/X11/wdm/wdm-config.preserve \
			${PREFIX}/lib/X11/wdm/wdm-config; \
	fi
	@${CP} ${PREFIX}/lib/X11/wdm/Xsetup_0 \
		${PREFIX}/lib/X11/wdm/Xsetup_0.dist
	@if [ -e ${PREFIX}/lib/X11/wdm/Xsetup_0.preserve ]; then \
		${MV} ${PREFIX}/lib/X11/wdm/Xsetup_0.preserve \
			${PREFIX}/lib/X11/wdm/Xsetup_0; \
	fi
.for file in ${DAEMONPICS}
	@${INSTALL_DATA} ${_DISTDIR}/${file} ${PREFIX}/lib/X11/wdm/pixmaps
.endfor
.if defined(WITH_PAM)
.if ( ${OSVERSION} >= 500028 )
	${INSTALL_DATA} ${FILESDIR}/wdm.pam ${LOCALBASE}/etc/pam.d/wdm
.else
	@${ECHO_CMD} "To finish installing this port, append the contents of ${FILESDIR}/wdm.pam to your /etc/pam.conf file"
.endif
.endif

.include <bsd.port.post.mk>
