# Created by: Brett Taylor <brett@peloton.physics.montana.edu>
# $FreeBSD$

PORTNAME=	afterstep
PORTVERSION=	2.2.12
PORTREVISION=	5
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	AFTERSTEP/stable
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	Stable version of the AfterStep window manager

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libgif.so:graphics/giflib \
		libpng.so:graphics/png \
		libtiff.so:graphics/tiff
RUN_DEPENDS=	xli:graphics/xli

USES=		gmake gnome jpeg pkgconfig shebangfix tar:bzip2 xorg
USE_CSTD=	gnu89
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 librsvg2 pango
USE_XORG+=	ice sm x11 xcomposite xcursor xdamage xext xfixes xi xinerama \
		xrandr xrender
GNU_CONFIGURE=	yes
SHEBANG_FILES=	tools/ascommand.pl \
		tools/importasmenu
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS+=--disable-ascp \
		--enable-i18n \
		--disable-send-postcard-to-developer \
		--with-helpcommand="xterm -e man" \
		--x-includes="${LOCALBASE}/include" \
		--with-jpeg-includes="${LOCALBASE}/include" \
		--with-png-includes="${LOCALBASE}/include" \
		--with-gif
MAKE_ENV+=	HOME=-

WRKSRC=		${WRKDIR}/${PORTNAME}-devel-${PORTVERSION}

.if defined(WITH_DIFFERENT_LOOKNFEELS)
CONFIGURE_ARGS+=	--enable-different-looknfeels
.endif

.if !defined(WITH_SAVEWINDOWS)
CONFIGURE_ARGS+=	--disable-savewindows
.endif

.include <bsd.port.pre.mk>

.if exists(${PREFIX}/share/gnome/wm-properties)
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

post-extract:
	${CP} ${FILESDIR}/monitor_bsd.xpm \
		${WRKSRC}/afterstep/desktop/icons/xml/monitor-bsd.xpm

post-patch:
.for f in afterstep/database
	@${REINPLACE_CMD} -e 's,linux-penguin,monitor-bsd,' \
		${WRKSRC}/${f}
.endfor
.for f in libAfterBase/Makefile.in libAfterImage/Makefile.in
	@${REINPLACE_CMD} -e 's,^install\.,noinstall.,g ; \
		 s,^install:,install:#,g' ${WRKSRC}/${f}
.endfor
.for f in libAfterBase/configure libAfterImage/configure
	@${REINPLACE_CMD} -e 's,="-O3",="$$CFLAGS",g' \
		${WRKSRC}/${f}
.endfor
.for f in libAfterStep/afterstep-config.in
	@${REINPLACE_CMD} -e 's,ft_version,libafterstep_version,g' \
		${WRKSRC}/${f}
.endfor
.for f in configure libAfterBase/configure libAfterConf/Makefile.in libAfterImage/configure tools/makeastheme.pl.in tools/installastheme.pl.in
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/${f}
.endfor

.if exists(${PREFIX}/share/gnome/wm-properties)
pre-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/gnome/wm-properties
.endif

.include <bsd.port.post.mk>
