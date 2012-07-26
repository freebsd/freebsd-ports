# New ports collection makefile for:	Window Maker
# Date created:				August 13, 1997
# Whom:					Brian Handy <handy@physics.montana.edu>
#
# $FreeBSD$

PORTNAME?=	windowmaker
PORTVERSION=	0.95.2
PORTREVISION?=	4
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	GNUstep-compliant NeXTstep window manager clone

LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png \
		jbig:${PORTSDIR}/graphics/jbigkit \
		tiff:${PORTSDIR}/graphics/tiff

.if !defined(LWR_SLAVE)
RUN_DEPENDS=	${LOCALBASE}/share/WindowMaker/Themes/LeetWM.themed/style:${PORTSDIR}/graphics/wmicons
USE_PERL5=	yes

OPTIONS=	XRANDR "xrandr support (EXPERIMENTAL)" off
.endif

MAKE_JOBS_SAFE=	yes

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GNOME=	gnomehack
USE_XORG=	xft xinerama xmu xpm
USE_GETTEXT=	yes
USE_PKGCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama --enable-usermenu \
		--with-x
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

.if !defined(LWR_SLAVE)

.if ${ARCH} == amd64 && ${OSVERSION} < 800000
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif

.if ${OSVERSION} < 800000
BROKEN=		does not compile on FreeBSD 7.X
.endif

.if defined(WITH_XRANDR)
USE_XORG+=	xrandr
CONFIGURE_ARGS+=	--enable-xrandr
.endif

CONFLICTS=	libwraster-0.*

MANLANG=	"" cs ru sk
MAN1=		geticonset.1x getstyle.1x seticons.1x setstyle.1x wdwrite.1x \
		wmaker.1x wmsetbg.1x wxcopy.1x wxpaste.1x

PORTDOCS=	AUTHORS BUGFORM BUGS ChangeLog FAQ FAQ.I18N INSTALL \
		INSTALL-WMAKER NEWS README README.definable-cursor TODO

LINGUAS=	be bg bs ca cs da de el es et fi fr gl hr hu hy it ja ko ms nl no pl pt ro ru sk sv tr zh_CN zh_TW
CONFIGURE_ENV+=	LINGUAS="${LINGUAS}"

pre-patch:
.for f in WINGs/wapplication.c WPrefs.app/Menu.c WPrefs.app/Paths.c \
    WindowMaker/*menu*
	@${REINPLACE_CMD} -e "s#/usr/local#${PREFIX}#g" ${WRKSRC}/${f}
.endfor
	@${REINPLACE_CMD} -e '/\/usr\/X11R6\/include\/X11\/pixmaps/d' \
	    -e '/\/usr\/share\/pixmaps/d' \
	    -e "s#\"/usr/local/share/pixmaps\",#\"${PREFIX}/share/pixmaps\"#" \
	    -e "s#/usr/share/icons#${PREFIX}/share/icons#" \
	    ${WRKSRC}/WindowMaker/Defaults/WindowMaker.in
	@${REINPLACE_CMD} -e "s#/usr/include/X11#${PREFIX}/share#" \
	    ${WRKSRC}/WPrefs.app/Paths.c
	@${REINPLACE_CMD} -e "s#WPrefs#${PREFIX}/GNUstep/Applications/WPrefs.app/WPrefs#" \
	    ${WRKSRC}/util/wmgenmenu.c
	@${REINPLACE_CMD} -e "764s#wPreferences.flags.restarting == 0#!wPreferences.flags.restarting#" \
	    ${WRKSRC}/src/startup.c

post-install:
	@${MKDIR} ${PREFIX}/GNUstep/Applications/WPrefs.app/xpm
	@${MKDIR} ${PREFIX}/share/WindowMaker/Sounds
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

update-LINGUAS: extract
	cd ${WRKSRC}/po && \
		${ECHO_CMD} *.po | ${SED} 's|\.po||g' > ${FILESDIR}/LINGUAS
.endif	# .if !defined(LWR_SLAVE)

.include <bsd.port.post.mk>
