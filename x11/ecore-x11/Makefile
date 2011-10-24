# New ports collection makefile for:	ecore-x11
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x11
DISTVERSION=	1.0.1
CATEGORIES=	x11 enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-05-25/base/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (x11 module)

LICENSE=	BSD
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	ecore libtool_hack
USE_EFL_ECORE=	input
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_x
INSTALL_WRKSRC=	${BUILD_WRKSRC}
XEXTDIR=	${LOCALBASE}/include/X11/extensions

.include "../../devel/ecore-main/Makefile.inc"

CONFIGURE_ARGS+=	--enable-ecore-x \
			--enable-ecore-input

OPTIONS=	XDAMAGE		"Enable Xdamage support (requires X11)" on \
		XDPMS		"Enable Xdpms support (requires X11)" on \
		XFIXES		"Enable Xfixes support (requires X11)" on \
		XINERAMA	"Enable Xinerama support (requires X11)" on \
		XPRINT		"Enable Xprint support (requires X11)" on \
		XRANDR		"Enable Xrandr support (requires X11)" on \
		XRENDER		"Enable Xrender support (requires X11)" on \
		XSS		"Enable Xscrnsaver support (requires X11)" on \
		XCURSOR		"Enable Xcursor support (requires X11)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XDAMAGE) || exists(${XEXTDIR}/Xdamage.h)
USE_XORG+=	xdamage
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XDPMS) || exists(${XEXTDIR}/dpms.h)
USE_XORG+=	xextproto
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XFIXES) || exists(${XEXTDIR}/Xfixes.h)
USE_XORG+=	xfixes
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XINERAMA) || exists(${XEXTDIR}/Xinerama.h)
USE_XORG+=	xineramaproto
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XPRINT) || exists(${XEXTDIR}/Print.h)
USE_XORG+=	printproto
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XRANDR) || exists(${XEXTDIR}/Xrandr.h)
USE_XORG+=	xrandr
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XRENDER) || exists(${XEXTDIR}/Xrender.h)
USE_XORG+=	xrender
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XSS) || exists(${XEXTDIR}/scrnsaver.h)
USE_XORG+=	xscrnsaver
WITH_X11=	yes
.endif

.if !defined(WITHOUT_XCURSOR) \
	|| exists(${LOCALBASE}/include/X11/Xcursor/Xcursor.h)
USE_XORG+=	xcursor
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
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
