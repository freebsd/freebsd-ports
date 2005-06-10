# New ports collection makefile for:	afterstep-stable
# Date created:		1 May 1998
# Whom:			Brett Taylor
#
# $FreeBSD$
#

PORTNAME=	afterstep
PORTVERSION=	2.1.1
CATEGORIES=	x11-wm afterstep
MASTER_SITES=	ftp://ftp.afterstep.org/stable/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	AfterStep-${PORTVERSION}

MAINTAINER=	glewis@FreeBSD.org
COMMENT=	A stable version of the AfterStep window manager

LIB_DEPENDS=	rplay.1:${PORTSDIR}/audio/rplay \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		tiff.4:${PORTSDIR}/graphics/tiff
RUN_DEPENDS=	${X11BASE}/bin/xli:${PORTSDIR}/graphics/xli

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_XPM=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=--enable-i18n \
		--disable-ascp \
		--disable-send-postcard-to-developer \
		--with-ungif \
		--with-png-includes="${LOCALBASE}/include" \
		--with-png-libs="${LOCALBASE}/lib" \
		--with-jpeg-includes="${LOCALBASE}/include" \
		--with-jpeg-libs="${LOCALBASE}/lib" \
		--with-helpcommand="xterm -e man"
MAKE_ENV=	INCS_PRIVATE="${CPPFLAGS}" LIBS_PRIVATE="${LDFLAGS}"

MAN1=		ASDatabase.1x ASDatabaseEntry.1x AfterStep.1x Align.1x \
		Animate.1x AnimateTypes.1x Arrange.1x Audio.1x AudioEvents.1x \
		AutoExec.1x Base.1x Bevel.1x ColorScheme.1x Feel.1x \
		FeelWindowBox.1x Functions.1x Gravity.1x Look.1x \
		MyBackground.1x MyFrame.1x MyStyle.1x Pager.1x \
		PagerDecorations.1x Placement.1x SupportedHints.1x \
		TbarLayout.1x Wharf.1x WharfSounds.1x WinList.1x WinTabs.1x \
		afterstep_faq.1x asimagexml.1x

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

.if defined(WITH_DIFFERENT_LOOKNFEELS)
CONFIGURE_ARGS+=	--enable-different-looknfeels
.endif

.if !defined(WITH_SAVEWINDOWS)
CONFIGURE_ARGS+=	--disable-savewindows
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not build on sparc64"
.endif

post-extract:
	${CP} ${FILESDIR}/monitor_bsd.xpm \
		${WRKSRC}/afterstep/desktop/icons/xml/monitor-bsd.xpm

post-patch:
.for file in afterstep/database
	@${PERL} -pi -e 's,linux-penguin,monitor-bsd,' \
		${WRKSRC}/${file}
.endfor
.for file in libAfterBase/Makefile.in libAfterImage/Makefile.in
	@${PERL} -pi.orig -e 's,^install\.,noinstall.,g ; \
		 s,^install:,install:#,g' ${WRKSRC}/${file}
.endfor
.for file in libAfterBase/configure libAfterImage/configure
	@${PERL} -pi.orig -e 's,="-O3",="$$CFLAGS",g' \
		${WRKSRC}/${file}
.endfor
.for file in libAfterStep/afterstep-config.in
	@${PERL} -pi -e 's,ft_version,libafterstep_version,g' \
		${WRKSRC}/${file}
.endfor

.include <bsd.port.post.mk>
