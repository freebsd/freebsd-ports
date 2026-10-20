PORTNAME=	bvwm
DISTVERSION=	1.1.5-bvwm.6
CATEGORIES=	x11-wm
# Extra icons tarball (optional); GitHub distfile comes from USE_GITHUB.
MASTER_SITES=	http://fvwm.sourceforge.net/generated/icon_download/:icons

MAINTAINER=	dteske@FreeBSD.org
COMMENT=	B? Virtual Window Manager (fvwm3 fork)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libevent.so:devel/libevent \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2 \
		libxkbcommon.so:x11/libxkbcommon

USES=		compiler:c11 localbase:ldflags meson perl5 pkgconfig python \
		shebangfix xorg
USE_GITHUB=	yes
GH_ACCOUNT=	FrauBSD
USE_XORG=	ice sm x11 xext xft xrandr xrender xt xtrans
SHEBANG_FILES=	bin/fvwm-menu-desktop.in bin/FvwmCommand.in
python_OLD_CMD=	@PYTHON@

BINARY_ALIAS=	python3=${PYTHON_CMD}

# libexec/bvwm/<ver>/ follows meson.project_version() (.current-version).
BVWM_VERSION=	${DISTVERSION:C/-.*//}
PLIST_SUB=	BVWM_VERSION=${BVWM_VERSION}

OPTIONS_DEFINE=		FRIBIDI GO ICONS ICONV MANPAGES NLS PNG SVG XCURSOR XPM
OPTIONS_DEFAULT=	FRIBIDI GO ICONV MANPAGES PNG XCURSOR
OPTIONS_SUB=		yes
GO_DESC=		Build and install modules written in Go

FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
FRIBIDI_MESON_ENABLED=	bidi

# modules: vendor dir is in the tarball.
# no_targets: meson runs go; this port only borrows the toolchain.
GO_USES=		go:modules,no_targets
GO_MESON_ENABLED=	golang

FVWM_ICONS=	fvwm_icons-20070101
ICONS_IMPLIES=	XPM
# Append-only: USE_GITHUB already provides the primary distfile.
ICONS_DISTFILES=	${FVWM_ICONS}.tar.bz2:icons

ICONV_USES=		iconv:translit
ICONV_MESON_ENABLED=	iconv

MANPAGES_BUILD_DEPENDS=	rubygem-asciidoctor>0:textproc/rubygem-asciidoctor
MANPAGES_MESON_TRUE=	mandoc

NLS_USES=		gettext
NLS_MESON_ENABLED=	nls

PNG_LIB_DEPENDS=	libpng.so:graphics/png
PNG_MESON_ENABLED=	png

SVG_USES=		gnome
SVG_USE=		GNOME=librsvg2
SVG_MESON_ENABLED=	svg

XCURSOR_USE=		XORG=xcursor,xfixes
XCURSOR_MESON_ENABLED=	xcursor xfixes

XPM_USE=		XORG=xpm
XPM_MESON_ENABLED=	xpm

# After `make patch`, so makepatch does not record this substitution.
pre-configure:
	@${REINPLACE_CMD} -e 's,/etc/,${LOCALBASE}/etc/,g' \
		${WRKSRC}/bin/fvwm-menu-desktop.in

post-install-GO-on:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bvwm-FvwmPrompt

post-install-ICONS-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/bvwm/pixmaps
	${INSTALL_DATA} ${WRKDIR}/${FVWM_ICONS}/*.xpm \
		${STAGEDIR}${PREFIX}/share/bvwm/pixmaps

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGO}
# bin/FvwmPrompt/meson.build runs go itself. GO_CMD and GO_BUILDFLAGS
# are written into a wrapper at configure time (quoted -ldflags stay
# shell syntax, and -C stays the first flag). GO_ENV is still needed
# when that wrapper runs.
CONFIGURE_ENV+=	${GO_ENV} \
		GO_BUILDFLAGS="${GO_BUILDFLAGS}" \
		GO_CMD="${GO_CMD}" \
		GOMAXPROCS=${MAKE_JOBS_NUMBER} \
		GOPROXY=off
MAKE_ENV+=	${GO_ENV} \
		GOMAXPROCS=${MAKE_JOBS_NUMBER} \
		GOPROXY=off
.endif

.include <bsd.port.post.mk>
