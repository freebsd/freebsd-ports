# New ports collection makefile for:	wdm
# Version required:	1.20
# Date created:		August 31, 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$

DISTNAME=	wdm-1.20
CATEGORIES=	x11 windowmaker
MASTER_SITES=	http://cortex.unice.fr/~jerome/WindowMaker/wdm/ \
		http://www.de.freebsd.org/de/gif/bsd/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DAEMONPIC}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	wraster.3:${PORTSDIR}/x11-wm/windowmaker
BUILD_DEPENDS=	automake:${PORTSDIR}/devel/automake

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	wdm
USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
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

post-extract:
	@${CP} ${FILESDIR}/*.patch ${WRKSRC}/patches

post-patch:
	@${PERL} -pi -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/doc/*.man

pre-configure:
	@(cd ${WRKSRC}; automake -a --include-deps)

post-install:
	${INSTALL_DATA} ${_DISTDIR}/${DAEMONPIC} ${PREFIX}/lib/X11/wdm/pixmaps

.include <bsd.port.mk>
