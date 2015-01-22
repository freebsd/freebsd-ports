# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
PORTVERSION=	0.8.1.${GITVERSION}
PORTEPOCH=	1
CATEGORIES=	x11
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/
DISTNAME=	${PORTNAME}-${GITVERSION}

MAINTAINER=	kmoore@FreeBSD.org
COMMENT=	Lumina Desktop Environment

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	xorg>=0:${PORTSDIR}/x11/xorg \
		fluxbox:${PORTSDIR}/x11-wm/fluxbox \
		fluxbox-tenr-styles-pack>=0:${PORTSDIR}/x11-themes/fluxbox-tenr-styles-pack \
		kde4-icons-oxygen>=0:${PORTSDIR}/x11-themes/kde4-icons-oxygen \
		xscreensaver:${PORTSDIR}/x11/xscreensaver \
		xscreensaver-demo:${PORTSDIR}/x11/xscreensaver \
		xbrightness:${PORTSDIR}/x11/xbrightness \
		numlockx:${PORTSDIR}/x11/numlockx

MAKE_JOBS_UNSAFE=yes

GITVERSION=	1421890927
USE_XORG=	x11 xcomposite xdamage xrender
USE_XCB=		x11extras wm
USE_LDCONFIG=	yes
USE_QT5=	core gui network svg linguist multimedia imageformats \
		buildtools x11extras
USES=		qmake tar:bzip2

WRKSRC=		${WRKDIR}/lumina

QMAKE_ARGS=	CONFIG+="configure"

.include <bsd.port.mk>
