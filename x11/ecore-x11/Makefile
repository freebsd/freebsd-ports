# New ports collection makefile for:	ecore-x11
# Date created:				17 September 2007
# Whom:					Stanislav Sedov <stas@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	x11
PORTVERSION=	0.9.9.042
PORTREVISION=	0
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.springdaemons.com/pub/snapshots/e17/ \
		http://download.enlightenment.org/snapshots/2008-01-25/
PKGNAMEPREFIX=	ecore-
DISTNAME=	ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Enlightenment core abstraction library (x11 module)

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gnomehack pkgconfig gnometarget
USE_LDCONFIG=	yes
USE_EFL=	ecore
USE_EFL_ECORE=	txt
BUILD_WRKSRC=	${WRKSRC}/src/lib/ecore_x
INSTALL_WRKSRC=	${BUILD_WRKSRC}
XEXTDIR=	${LOCALBASE}/include/X11/extensions

CONFIGURE_ARGS=	--disable-ecore-con \
		--disable-ecore-config \
		--disable-ecore-desktop \
		--disable-ecore-directfb \
		--disable-ecore-evas \
		--disable-ecore-file \
		--disable-ecore-ipc \
		--disable-ecore-job \
		--disable-ecore-sdl \
		--disable-ecore-txt \
		--enable-ecore-x \
		--disable-ecore-imf \
		--disable-ecore-imf_evas

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
		-e 's,\$$\(top_builddir\)/src/lib/ecore_txt/\.libs,${LOCALBASE}/lib,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore/libecore\.la,-lecore,'\
		-e 's,\$$\(top_builddir\)/src/lib/ecore_txt/libecore_txt\.la,-lecore_txt,'\
		${BUILD_WRKSRC}/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/ecore-x.pc \
		${PREFIX}/libdata/pkgconfig/

.include <bsd.port.post.mk>
