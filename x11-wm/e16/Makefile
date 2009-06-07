# New ports collection makefile for:	enlightenment
# Date created:			10 June 1997
# Whom:				Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	e16
DISTVERSION=	1.0.0
CATEGORIES=	x11-wm
MASTER_SITES=	SF/enlightenment

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	A very artistic X window manager

E16_REVISION=	000

USE_XORG=	compositeproto damageproto xextproto x11 xbitmaps xcomposite xdamage \
		xext xfixes xft xinerama xrandr xrender xxf86vm
USE_ICONV=	yes
USE_GMAKE=	yes
USE_EFL=	imlib2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-esdtest --disable-dependency-tracking \
		--disable-rpath

.if !defined(WITHOUT_ESOUND)
USE_GNOME=	esound
.else
CONFIGURE_ARGS+=--disable-sound
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	xmlto:${PORTSDIR}/textproc/xmlto
CONFIGURE_ARGS+=--enable-docs=yes
.else
CONFIGURE_ARGS+=--enable-docs=no
post-patch:
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
