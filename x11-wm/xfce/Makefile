# New ports collection makefile for:	xfce
# Date created:		30 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	xfce
PORTVERSION=	3.8.8b
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.xfce.org/archive/

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GTK=	yes
USE_XPM=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-conf-dir=${PREFIX}/etc/xfce \
		--with-data-dir=${PREFIX}/share/xfce \
		--with-locale-dir=${PREFIX}/share/locale \
		--with-xpm=${X11BASE} \
		--disable-xinerama

.include <bsd.port.pre.mk>

.if defined(WITH_XFT) && ${WITH_XFT} == yes
CONFIGURE_ARGS+= --enable-xft
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to enable anti-aliased font support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_XFT=yes\""
	@${ECHO_MSG}
.endif

MAN1=		glob.1 xfbd.1 xfce.1 xfclock.1 xfglob.1 xfgnome.1 xfhelp.1 \
		xflock.1 xfmountdev.1 xfmouse.1 xfpager.1 xfprint.1 xfrun.1 \
		xfsound.1 xfterm.1 xftrash.1 xftree.1 xfwm.1

pre-patch:
	@${PERL} -pi -e \
		's|DATADIRNAME=lib|DATADIRNAME=share|g ; \
		 s|USE_INCLUDED_LIBINTL=yes|#USE_INCLUDED_LIBINTL=yes|g ; \
		 s|\$$\(top_builddir\)/intl/libintl.a|-lintl|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|gtk-config|${GTK_CONFIG:T}|g' ${WRKSRC}/xfce/setup.c
	@${PERL} -pi -e 's|xfplay|internal|g' ${WRKSRC}/other/xfsoundrc.in

pre-build:
	${LN} -sf ${LOCALBASE}/bin/libtool ${WRKSRC}/libtool

.include <bsd.port.post.mk>
