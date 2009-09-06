# New ports collection makefile for:	afterstep-stable
# Date created:		1 May 1998
# Whom:			Brett Taylor <brett@peloton.physics.montana.edu>
#
# $FreeBSD$
#

PORTNAME=	afterstep
PORTVERSION=	2.2.9
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		SF/${PORTNAME}/AfterStep/${PORTVERSION}

DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A stable version of the AfterStep window manager

LIB_DEPENDS=	cairo.2:${PORTSDIR}/graphics/cairo \
		execinfo.1:${PORTSDIR}/devel/libexecinfo \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		rplay.1:${PORTSDIR}/audio/rplay \
		rsvg-2.2:${PORTSDIR}/graphics/librsvg2 \
		tiff.4:${PORTSDIR}/graphics/tiff \
		ungif.5:${PORTSDIR}/graphics/libungif
RUN_DEPENDS=	xli:${PORTSDIR}/graphics/xli

USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 pango
USE_ICONV=	yes
USE_XORG+=	ice sm x11 xcursor xext xfixes xi xinerama xrandr xrender
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--disable-ascp \
		--enable-i18n \
		--disable-send-postcard-to-developer \
		--with-helpcommand="xterm -e man" \
		--with-jpeg-includes="${LOCALBASE}/include" \
		--with-jpeg-libs="${LOCALBASE}/lib" \
		--with-png-includes="${LOCALBASE}/include" \
		--with-png-libs="${LOCALBASE}/lib" \
		--with-ungif

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
.for file in afterstep/database
	@${REINPLACE_CMD} -e 's,linux-penguin,monitor-bsd,' \
		${WRKSRC}/${file}
.endfor
.for file in libAfterBase/Makefile.in libAfterImage/Makefile.in
	@${REINPLACE_CMD} -e 's,^install\.,noinstall.,g ; \
		 s,^install:,install:#,g' ${WRKSRC}/${file}
.endfor
.for file in libAfterBase/configure libAfterImage/configure
	@${REINPLACE_CMD} -e 's,="-O3",="$$CFLAGS",g' \
		${WRKSRC}/${file}
.endfor
.for file in libAfterStep/afterstep-config.in
	@${REINPLACE_CMD} -e 's,ft_version,libafterstep_version,g' \
		${WRKSRC}/${file}
.endfor
.for file in configure libAfterBase/configure libAfterConf/Makefile.in libAfterImage/configure
	@${REINPLACE_CMD} -e 's,%%LOCALBASE%%,${LOCALBASE},g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
