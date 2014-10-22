# Created by: Ken Moore <ken@pcbsd.org>
# $FreeBSD$

PORTNAME=	lumina
GITVERSION=	1413916751
PORTVERSION=	0.7.0.${GITVERSION}
PORTEPOCH=	1
CATEGORIES=	x11
DISTNAME=	${PORTNAME}-${GITVERSION}
MASTER_SITES=	http://www.pcbsd.org/~kris/software/ \
		ftp://ftp.pcbsd.org/pub/software/

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
		numlockx:${PORTSDIR}/x11/numlockx \
		phonon-gstreamer>=0:${PORTSDIR}/multimedia/phonon-gstreamer \
		gstreamer-plugins-ogg>=0:${PORTSDIR}/audio/gstreamer-plugins-ogg
LIB_DEPENDS=	libQtSolutions_SingleApplication-head.so:${PORTSDIR}/devel/qt4-qtsolutions-singleapplication \
		libjpeg.so:${PORTSDIR}/graphics/jpeg

MAKE_JOBS_UNSAFE=yes
USE_XORG=	x11 xcomposite xdamage xrender
USE_LDCONFIG=	yes
USE_QT4=	corelib gui network svg linguist phonon imageformats \
		moc_build rcc_build uic_build 
USES=		qmake tar:bzip2

WRKSRC=		${WRKDIR}/lumina

QMAKE_ARGS=	CONFIG+="configure"

.include <bsd.port.mk>
