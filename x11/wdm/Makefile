# New ports collection makefile for:	wdm
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdm
PORTVERSION=	1.20
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.tcscs.com/wdm/wdm/ \
		http://www.de.freebsd.org/de/gif/bsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPIC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	wraster.4:${PORTSDIR}/x11-wm/windowmaker \
		PropList.2:${PORTSDIR}/devel/libPropList

DIST_SUBDIR=	wdm
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
		--with-Logo=Earth200x130.xpm \
		--with-gfx-incs=${X11BASE}/include/WINGs \
		--with-gfx-libs=${X11BASE}/lib \
		--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
		--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin \
		--with-wmlist=wmaker:afterstep:blackbox:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

MAN1=	wdm.1 wdmLogin.1

DAEMONPIC=	daemon1-HQ-1280x960.jpg

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
LIBPAM=		-lpam
.endif

pre-everything::
.if !defined(WITH_PAM)
	@${ECHO_MSG} "To build this port with PAM support, define \"WITH_PAM\"."
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/*.man

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
	@${INSTALL_DATA} ${_DISTDIR}/${DAEMONPIC} ${PREFIX}/lib/X11/wdm/pixmaps

.include <bsd.port.mk>
