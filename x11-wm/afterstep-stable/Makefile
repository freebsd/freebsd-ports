# Created by: Brett Taylor <brett@peloton.physics.montana.edu>
# $FreeBSD$

PORTNAME=	afterstep
PORTVERSION=	2.2.12
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	${MASTER_SITE_AFTERSTEP}
MASTER_SITE_SUBDIR=	stable
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A stable version of the AfterStep window manager

LIB_DEPENDS=	dbus-1:${PORTSDIR}/devel/dbus \
		execinfo:${PORTSDIR}/devel/libexecinfo \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		gif:${PORTSDIR}/graphics/giflib \
		jpeg:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	xli:${PORTSDIR}/graphics/xli

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	atk cairo gdkpixbuf2 glib20 gtk20 librsvg2 pango
USE_XORG+=	ice sm x11 xcomposite xcursor xdamage xext xfixes xi xinerama \
		xrandr xrender
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_ARGS+=--disable-ascp \
		--enable-i18n \
		--disable-send-postcard-to-developer \
		--with-helpcommand="xterm -e man" \
		--x-includes="${LOCALBASE}/include" \
		--with-jpeg-includes="${LOCALBASE}/include" \
		--with-png-includes="${LOCALBASE}/include" \
		--with-gif

WRKSRC=		${WRKDIR}/${PORTNAME}-devel-${PORTVERSION}

MAN1=		ASDatabase.1x ASDatabaseEntry.1x AfterStep.1x Align.1x \
		Animate.1x AnimateTypes.1x Arrange.1x AutoExec.1x \
		BalloonContents.1x Base.1x Bevel.1x ColorScheme.1x \
		Feel.1x FeelWindowBox.1x Functions.1x Gravity.1x Look.1x \
		MyBackground.1x MyFrame.1x MyStyle.1x Pager.1x \
		PagerDecorations.1x Placement.1x Sound.1x SoundEvents.1x \
		SupportedHints.1x TbarLayout.1x Wharf.1x WharfFolders.1x \
		WharfSounds.1x WinCommand.1x WinList.1x WinTabs.1x \
		afterstep_faq.1x asimagexml.1x

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
.for f in configure libAfterBase/configure libAfterConf/Makefile.in libAfterImage/configure
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/${f}
.endfor

.include <bsd.port.post.mk>
