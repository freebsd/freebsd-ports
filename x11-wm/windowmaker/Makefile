# Created by: Brian Handy <handy@physics.montana.edu>
# $FreeBSD$

PORTNAME=	windowmaker
PORTVERSION=	0.95.5
PORTREVISION=	2
CATEGORIES=	x11-wm windowmaker
MASTER_SITES=	http://windowmaker.org/pub/%SUBDIR%/
MASTER_SITE_SUBDIR=	source/release
DISTNAME=	WindowMaker-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	GNUstep-compliant NeXTstep window manager clone

LICENSE=	GPLv2

LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng15.so:${PORTSDIR}/graphics/png \
		libjbig.so:${PORTSDIR}/graphics/jbigkit \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libwraster.so:${PORTSDIR}/x11-wm/libwraster
RUN_DEPENDS=	libwraster>=${PORTVERSION}:${PORTSDIR}/x11-wm/libwraster \
		${LOCALBASE}/share/WindowMaker/Themes/LeetWM.themed/style:${PORTSDIR}/graphics/wmicons

USES=		pathfix perl5 pkgconfig
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
USE_XORG=	xft xinerama xmu xpm
CONFIGURE_ENV=	ac_cv_header_sys_inotify_h=no
CONFIGURE_ARGS=	--with-pixmapdir=${PREFIX}/include/X11/pixmaps \
		--with-nlsdir=${PREFIX}/share/locale \
		--with-libs-from="-L${LOCALBASE}/lib" \
		--with-incs-from="-I${LOCALBASE}/include" \
		--with-gnustepdir="${PREFIX}/GNUstep" \
		--enable-modelock \
		--enable-xinerama --enable-usermenu \
		--with-x
CPPFLAGS+=	-DPREFIX=\\\"${PREFIX}\\\" -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
PORTDOCS=	AUTHORS BUGFORM BUGS ChangeLog FAQ FAQ.I18N INSTALL \
		INSTALL-WMAKER NEWS README README.definable-cursor TODO
LINGUAS=	be bg bs ca cs da de el es et fi fr gl hr hu hy it \
		ja ko ms nl no pl pt ro ru sk sv tr zh_CN zh_TW

OPTIONS_DEFINE=	DOCS NLS XRANDR
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENV=	LINGUAS="${LINGUAS}"
NLS_CONFIGURE_ENABLE=	locale
XRANDR_USE=	XORG=xrandr
XRANDR_CONFIGURE_ENABLE=	xrandr

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 && ${OSVERSION} < 800000
CONFIGURE_ENV+=	ac_cv_c_inline_asm=no
.endif
.if ${OSVERSION} < 800000
CPPFLAGS+=	-DHAVE_SYS_SELECT_H
.endif

post-install:
	@${MKDIR} \
	    ${STAGEDIR}${PREFIX}/GNUstep/Applications/WPrefs.app/xpm \
	    ${STAGEDIR}${PREFIX}/share/WindowMaker/Sounds
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
