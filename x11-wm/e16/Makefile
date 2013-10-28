# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	e16
PORTVERSION=	1.0.13.003
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	SF/enlightenment/${PORTNAME}/Snapshots/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Enlightenment DR16 window manager

OPTIONS_DEFINE=	DOCS NLS SOUND
SOUND_DESC=	Sound support via pulseaudio/libsndfile

USE_XORG=	compositeproto damageproto xextproto x11 xbitmaps xcomposite xdamage \
		xext xfixes xft xinerama xrandr xrender xxf86vm
USES=		gettext gmake iconv pkgconfig
USE_EFL=	imlib2
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-rpath --enable-mans SHELL=/bin/sh

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSOUND}
LIB_DEPENDS+=	libpulse.so:${PORTSDIR}/audio/pulseaudio \
		libsndfile.so:${PORTSDIR}/audio/libsndfile
CONFIGURE_ARGS+=--enable-sound \
		--enable-sound-pulse \
		--with-sndldr=sndfile
.else
CONFIGURE_ARGS+=--disable-sound \
		--with-sndldr=none
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
CONFIGURE_ARGS+=--enable-docs=yes
.else
CONFIGURE_ARGS+=--enable-docs=no
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's|$$(USER)|${SHAREOWN}:${SHAREGRP}|g' \
	    ${WRKSRC}/themes/Makefile.am ${WRKSRC}/themes/Makefile.in

.include <bsd.port.mk>
