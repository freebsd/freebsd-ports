# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	metisse
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	x11
MASTER_SITES=	http://insitu.lri.fr/metisse/download/metisse/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Innovative X-based window system

LICENSE=	GPLv3

CONFLICTS=	fvwm-1.* fvwm-2.*

LIB_DEPENDS=	libNucleo.so:${PORTSDIR}/x11-toolkits/nucleo \
		libpng15.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/libdata/xorg/fonts:${PORTSDIR}/x11-fonts/xorg-fonts

USES=		gettext libtool pathfix pkgconfig shebangfix tar:bzip2
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
CONFIGURE_ARGS=	--with-fontdir=${LOCALBASE}/lib/X11/fonts
USE_LDCONFIG=	yes
USE_PYTHON=	yes
USE_XORG=	xcursor xft xinerama xpm xrender xt xtst
WANT_GNOME=	yes
MAKE_ARGS=	METISSE_DOC_DIR="${DOCSDIR}"
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libpng15
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	MMX GLX ATSPI STROKE RPLAY FRIBIDI GLIB GTK2 GCONF \
		GTK1 IMLIB DOCS
OPTIONS_DEFINE_i386=	GLX_X86

GLX_X86_DESC=	GLX with x86 optimizations
ATSPI_DESC=	Widget tracking support
RPLAY_DESC=	RPlay support in FvwmEvent
GLIB_DESC=	Use GLib 2.x for module integration
GTK2_DESC=	Use GDK-PixBuf-2.0 for image loading
GTK1_DESC=	Legacy GTK+ 1.2.x support
IMLIB_DESC=	Imlib support in FvwmGtk

OPTIONS_DEFAULT=	MMX GLX
OPTIONS_DEFAULT_i386=	GLX_X86

.include <bsd.port.pre.mk>

.if ${MACHINE_CPU:Mmmx} && ${PORT_OPTIONS:MMMX}
CONFIGURE_ARGS+=	--enable-mmx
.endif

.if ${PORT_OPTIONS:MGLX}
CONFIGURE_ARGS+=	--enable-glx
.endif

.if ${PORT_OPTIONS:MGLX_X86}
CONFIGURE_ARGS+=	--enable-glx-x86
.endif

.if ${PORT_OPTIONS:MATSPI}
USE_GNOME+=	atspi
.endif

.if ${PORT_OPTIONS:MSTROKE}
LIB_DEPENDS+=	libstroke.so:${PORTSDIR}/devel/libstroke
.endif

.if ${PORT_OPTIONS:MRPLAY}
LIB_DEPENDS+=	librplay.so:${PORTSDIR}/audio/rplay
.endif

.if ${PORT_OPTIONS:MFRIBIDI}
LIB_DEPENDS+=	libfribidi.so:${PORTSDIR}/converters/fribidi
.endif

.if ${HAVE_GNOME:Mglib20} || ${PORT_OPTIONS:MGLIB}
USE_GNOME+=	glib20
.endif

.if ${HAVE_GNOME:Mgtk20} || ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
.endif

.if ${HAVE_GNOME:Mgconf2} && ${HAVE_GNOME:Mlibglade2} || ${PORT_OPTIONS:MGCONF}
USE_GNOME+=	gconf2 libglade2
PLIST_SUB+=	GCONF=""
.else
_NOGLADEDIR=	yes
PLIST_SUB+=	GCONF="@comment "
.endif

.if ${HAVE_GNOME:Mgtk12} || ${PORT_OPTIONS:MGTK1}
USE_GNOME+=	gtk12
.endif

.if ${HAVE_GNOME:Mimlib} || ${PORT_OPTIONS:MIMLIB}
USE_GNOME+=	imlib
.endif

_GTK=	${USE_GNOME:Mgtk12} ${USE_GNOME:Mimlib}
.if !empty(_GTK)
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

post-patch: .SILENT
# Catch up with new <fribidi-types.h> header name
	${REINPLACE_CMD} -e 's,fribidi_types\.h,fribidi-types.h,' \
		${WRKSRC}/fvwm-insitu/libs/FBidi.c
# Fix desktop entries path
	${REINPLACE_CMD} -E 's,^(configdir =).*,\1 ${DESKTOPDIR},' \
		${WRKSRC}/fvwm-insitu/opale/session/Makefile.in
.if defined(_NOGLADEDIR)
	${REINPLACE_CMD} -e 's, install-gladeDATA,,' \
		${WRKSRC}/fvwm-insitu/modules/FvwmConfig/Makefile.in
.endif
	${REINPLACE_CMD} -e 's,return;,return 0;,' \
		${WRKSRC}/fvwm-insitu/configure

.include <bsd.port.post.mk>
