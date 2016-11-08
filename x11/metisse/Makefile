# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metisse
PORTVERSION=	0.4.1
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/metisse/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Innovative X-based window system

LICENSE=	GPLv3

LIB_DEPENDS=	libNucleo.so:x11-toolkits/nucleo \
		libpng.so:graphics/png
RUN_DEPENDS=	xorg-fonts>0:x11-fonts/xorg-fonts

CONFLICTS=	fvwm-1.* fvwm-2.*

BROKEN_aarch64=	Fails to build: error: GETLEFTBITS_ALIGNMENT must be 1

USES=		gettext libtool pathfix pkgconfig python shebangfix tar:bzip2
SHEBANG_FILES=	${WRKSRC}/fvwm-insitu/bin/fvwm-convert-2.4.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-convert-2.6.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-menu-desktop.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-menu-directory.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-menu-headlines.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-menu-xlock.in \
		${WRKSRC}/fvwm-insitu/bin/fvwm-perllib.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmConsole/FvwmConsoleC.pl.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmDebug/FvwmDebug.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmDebug/FvwmGtkDebug.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmPerl/FvwmPerl.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmTabs/FvwmTabs.in \
		${WRKSRC}/fvwm-insitu/modules/FvwmWindowMenu/FvwmWindowMenu.in
perl_OLD_CMD=	@PERL@
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fontdir=${LOCALBASE}/share/fonts
USE_LDCONFIG=	yes
USE_XORG=	xcursor xft xinerama xpm xrender xt xtst
WANT_GNOME=	yes
MAKE_ARGS=	METISSE_DOC_DIR="${DOCSDIR}"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	GLX ATSPI STROKE RPLAY FRIBIDI GLIB GTK2 GCONF \
		DOCS
OPTIONS_DEFINE_i386=	GLX_X86 MMX
OPTIONS_DEFINE_amd64=	MMX
OPTIONS_SUB=	yes

GLX_X86_DESC=	GLX with x86 optimizations
ATSPI_DESC=	Widget tracking support
RPLAY_DESC=	RPlay support in FvwmEvent
GLIB_DESC=	Use GLib 2.x for module integration
GTK2_DESC=	Use GDK-PixBuf-2.0 for image loading

OPTIONS_DEFAULT=	GLX
OPTIONS_DEFAULT_i386=	GLX_X86 MMX
OPTIONS_DEFAULT_amd64=	MMX

MMX_CONFIGURE_ENABLE=	mmx
GLX_CONFIGURE_ENABLE=	glx
GLX_X86_CONFIGURE_ENABLE=	glx-x86
ATSPI_USE=	GNOME=atspi
STROKE_LIB_DEPENDS=	libstroke.so:devel/libstroke
MRPLAY_LIB_DEPENDS=	librplay.so:audio/rplay
FRIBIDI_LIB_DEPENDS=	libfribidi.so:converters/fribidi
GLIB_USE=	GNOME=glib20
GTK2_USE=	GNOME=gtk20

GCONF_USE_GNOME+=	gconf2 libglade2

post-patch:
# Catch up with new <fribidi-types.h> header name
	@${REINPLACE_CMD} -e 's,fribidi_types\.h,fribidi-types.h,' \
		${WRKSRC}/fvwm-insitu/libs/FBidi.c
# Fix desktop entries path
	@${REINPLACE_CMD} -E 's,^(configdir =).*,\1 ${DESKTOPDIR},' \
		${WRKSRC}/fvwm-insitu/opale/session/Makefile.in
	@${REINPLACE_CMD} -e 's,return;,return 0;,' \
		${WRKSRC}/fvwm-insitu/configure

post-patch-GCONF-off:
	@${REINPLACE_CMD} -e 's, install-gladeDATA,,' \
		${WRKSRC}/fvwm-insitu/modules/FvwmConfig/Makefile.in

.include <bsd.port.mk>
