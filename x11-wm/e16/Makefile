# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	e16
PORTVERSION=	1.0.16
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	SF/enlightenment/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Enlightenment DR16 window manager

LICENSE=	MIT

LIB_DEPENDS=	libImlib2.so:${PORTSDIR}/graphics/imlib2

OPTIONS_DEFINE=		DOCS NLS SOUND
OPTIONS_SUB=		yes
SOUND_DESC=		Sound support via pulseaudio/libsndfile
SOUND_LIB_DEPENDS=	libpulse.so:${PORTSDIR}/audio/pulseaudio \
    			libsndfile.so:${PORTSDIR}/audio/libsndfile
SOUND_CONFIGURE_ON=	--enable-sound \
			--enable-sound-pulse \
			--with-sndldr=sndfile
SOUND_CONFIGURE_OFF=	--disable-sound \
			--with-sndldr=none
NLS_USES=		gettext
NLS_CONFIGURE_OFF=	--disable-nls
DOCS_CONFIGURE_ON=	--enable-docs=yes
DOCS_CONFIGURE_OFF=	--enable-docs=no

USE_XORG=	compositeproto damageproto xextproto x11 xbitmaps xcomposite xdamage \
		xext xfixes xft xinerama xrandr xrender xxf86vm
USES=		gettext gmake iconv libtool perl5 pkgconfig shebangfix
SHEBANG_FILES=	scripts/e_gen_menu
CFLAGS+=	-Wno-unused-parameter
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-dependency-tracking \
		--disable-rpath --enable-mans SHELL=/bin/sh

.include <bsd.port.options.mk>

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^SUBDIRS/s|docs ||' \
	    ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
.endif
	${REINPLACE_CMD} -e 's|$$(USER)|${SHAREOWN}:${SHAREGRP}|g' \
	    ${WRKSRC}/themes/Makefile.am ${WRKSRC}/themes/Makefile.in

.include <bsd.port.mk>
