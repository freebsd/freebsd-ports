# New ports collection makefile for:	wdm
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wdm
PORTVERSION= 	1.20
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://www.tcscs.com/wdm/wdm/ \
		http://www.de.freebsd.org/de/gif/bsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPIC}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	wraster.3:${PORTSDIR}/x11-wm/windowmaker

DIST_SUBDIR=	wdm
USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
AUTOMAKE=	automake -a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include \
			-DCSRG_BASED -DHAS_SETUSERCONTEXT" \
		LIBS="-L${LOCALBASE}/lib ${LIBPAM}"
CONFIGURE_ARGS=	--with-logdir=/var/log \
		--with-runlockdir=/var/run \
		--with-wdmdir=${PREFIX}/lib/X11/wdm \
		--with-Logo=Earth200x130.xpm \
		--with-defuserpath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin:${LOCALBASE}/bin \
		--with-defsystempath=/bin:/usr/bin:/sbin:/usr/sbin:${X11BASE}/bin \
		--with-wmlist=wmaker:afterstep:blackbox:ctwm:enlightenment:fvwm:fvwm2:fvwm95:olvwm:qvwm:tvtwm

MAN1=	wdm.1 wdmLogin.1

DAEMONPIC=	daemon1-HQ-1280x960.jpg

.if defined(WITH_PAM)
CONFIGURE_ARGS+=	--enable-pam
LIBPAM=		-lpam
.endif

pre-fetch:
.if !defined(WITH_PAM)
	@${ECHO_MSG} "To build this port with PAM support, define \"WITH_PAM\"."
.endif

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/*.man

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${DAEMONPIC} ${PREFIX}/lib/X11/wdm/pixmaps

.include <bsd.port.mk>
