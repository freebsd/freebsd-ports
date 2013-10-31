# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	enlightenment
PORTVERSION=	0.17.4
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Artistic X window manager

LICENSE=	BSD

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix iconv gmake pkgconfig
USE_EFL=	eina eet evas ecore eio edbus efreet edje \
		libtool_hack librt_hack modarch_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_EVAS_ENGINES=	buffer
USE_EFL_ECORE=	ipc
USE_LDCONFIG=	yes
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--with-profile=MEDIUM_PC \
		--disable-connman

OPTIONS_DEFINE=	ILLUME
ILLUME_DESC=	Enable illume module

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MILLUME}
CONFIGURE_ARGS+=--enable-illume2
PLIST_SUB+=	ILLUME=""
.else
CONFIGURE_ARGS+=--disable-illume2
PLIST_SUB+=	ILLUME="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS+=--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|\-relname||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|\(setuid_root_mode = a=rx,u+x\)s|\1|g' \
		${WRKSRC}/src/bin/Makefile.in
	@${REINPLACE_CMD} -e 's|@E_FM_LIBS@|@E_FM_LIBS@ -lehal -leukit|' \
		${WRKSRC}/src/bin/e_fm/Makefile.in

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: signal 10
.endif

.include <bsd.port.mk>
