PORTNAME=	fvwm3
DISTVERSION=	1.1.0
PORTREVISION=	8
CATEGORIES=	x11-wm
MASTER_SITES=	https://github.com/fvwmorg/fvwm3/releases/download/${DISTVERSION}/ \
		http://fvwm.sourceforge.net/generated/icon_download/:icons

MAINTAINER=	zirias@FreeBSD.org
COMMENT=	F? Virtual Window Manager
WWW=		https://www.fvwm.org/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent \
		libfreetype.so:print/freetype2 \
		libfontconfig.so:x11-fonts/fontconfig

USES=		compiler:c11 cpe pkgconfig python readline xorg
CPE_VENDOR=	fvwm
CPE_PRODUCT=	fvwm
USE_XORG=	ice sm x11 xext xft xrandr xrender xt

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	ac_cv_path_PYTHON=${PYTHON_CMD}

CONFLICTS_INSTALL=	fvwm
PLIST_SUB=		DISTVERSION=${DISTVERSION}

OPTIONS_DEFINE=		FRIBIDI GO ICONS ICONV MANPAGES NLS PERL PNG SVG \
			XCURSOR XPM
OPTIONS_DEFAULT=	FRIBIDI GO ICONV MANPAGES PERL PNG XCURSOR
OPTIONS_SUB=		yes
GO_DESC=		Build and install modules written in Go

FRIBIDI_LIB_DEPENDS=		libfribidi.so:converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	bidi

_GO_MAXVERSION=		1.23
_GO_VERSIONARG=		${${GO_DEFAULT:S/-devel//:S/.//} > \
			${_GO_MAXVERSION:S/.//}:?${_GO_MAXVERSION},:}
GO_USES=		go:${_GO_VERSIONARG}no_targets
GO_CONFIGURE_ENABLE=	golang

FVWM_ICONS=		fvwm_icons-20070101
ICONS_IMPLIES=		XPM
ICONS_DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${FVWM_ICONS}.tar.bz2:icons

ICONV_USES=		iconv:translit
ICONV_CONFIGURE_ENABLE=	iconv

MANPAGES_IMPLIES=	PERL
MANPAGES_BUILD_DEPENDS=	rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
MANPAGES_USES=		gmake
MANPAGES_CONFIGURE_ENABLE=	mandoc

NLS_USES=		gettext-runtime
NLS_CONFIGURE_ENABLE=	nls

PERL_USES=		perl5
PERL_CONFIGURE_ENABLE=	perllib

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_CONFIGURE_ENABLE=	png

SVG_USES=		gnome
SVG_USE=		gnome=cairo,glib20,gdkpixbuf,librsvg2
SVG_CONFIGURE_ENABLE=	rsvg

XCURSOR_USE=			xorg=xcursor
XCURSOR_CONFIGURE_ENABLE=	xcursor

XPM_USE=		xorg=xpm
XPM_CONFIGURE_OFF=	--with-xpm-library=no

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/,${LOCALBASE}/etc/,g' \
		${WRKSRC}/bin/fvwm-menu-desktop.in

post-install-ICONS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/fvwm3/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${FVWM_ICONS}/*.xpm \
		${STAGEDIR}${PREFIX}/share/fvwm3/pixmaps

post-install-PERL-off:
.for script in fvwm-convert-2.6 fvwm-menu-directory fvwm-menu-xlock fvwm-perllib
	${RM} ${STAGEDIR}${PREFIX}/bin/${script}
.endfor
.for script in FvwmConsoleC.pl FvwmPerl
	${RM} ${STAGEDIR}${PREFIX}/libexec/fvwm3/${DISTVERSION}/${script}
.endfor

.include <bsd.port.mk>
