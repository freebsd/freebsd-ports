# Created by: Stanislav Sedov <stas@FreeBSD.org>
# $FreeBSD$

PORTNAME=	x11
PORTVERSION=	1.7.8
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/
PKGNAMEPREFIX=	ecore-
DISTNAME=	${PKGNAMEPREFIX}${PORTVERSION}

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (x11 module)

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		gmake pkgconfig
USE_EFL=	ecore libtool_hack
USE_EFL_ECORE=	input
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_x
INSTALL_WRKSRC=	${BUILD_WRKSRC}
XEXTDIR=	${LOCALBASE}/include/X11/extensions

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-x \
			--enable-ecore-input

OPTIONS_DEFINE=	XCURSOR XDAMAGE XDPMS XFIXES XINERAMA XPRINT XRANDR XRENDER XSS
OPTIONS_DEFAULT=XCURSOR XDAMAGE XDPMS XFIXES XINERAMA XPRINT XRANDR XRENDER XSS
XDAMAGE_DESC=	X11 Xdamage extension support
XDPMS_DESC=	X11 Xdpms extension support
XFIXES_DESC=	X11 Xfixes extension support
XPRINT_DESC=	X11 Xprint extension support
XRENDER_DESC=	X11 Xrender extension support
XSS_DESC=	X11 Xscrnsaver extension support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXCURSOR} \
	|| exists(${LOCALBASE}/include/X11/Xcursor/Xcursor.h)
USE_XORG+=	xcursor
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXDAMAGE} || exists(${XEXTDIR}/Xdamage.h)
USE_XORG+=	xdamage
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXDPMS} || exists(${XEXTDIR}/dpms.h)
USE_XORG+=	xextproto
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXFIXES} || exists(${XEXTDIR}/Xfixes.h)
USE_XORG+=	xfixes
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXINERAMA} || exists(${XEXTDIR}/Xinerama.h)
USE_XORG+=	xineramaproto
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXPRINT} || exists(${XEXTDIR}/Print.h)
USE_XORG+=	printproto
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXRANDR} || exists(${XEXTDIR}/Xrandr.h)
USE_XORG+=	xrandr
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXRENDER} || exists(${XEXTDIR}/Xrender.h)
USE_XORG+=	xrender
WITH_X11=	yes
.endif

.if ${PORT_OPTIONS:MXSS} || exists(${XEXTDIR}/scrnsaver.h)
USE_XORG+=	xscrnsaver
WITH_X11=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's,\$$\(top_builddir\)/src/lib/ecore/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_input/libecore_input\.la,-lecore_input,'\
		${BUILD_WRKSRC}/Makefile.in \
		${BUILD_WRKSRC}/xcb/Makefile.in \
		${BUILD_WRKSRC}/xlib/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-x.pc \
		${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>
