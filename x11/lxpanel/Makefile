# Created by: Lin, Cheng-Tao <b89605222@ntu.edu.tw>
# $FreeBSD$

PORTNAME=	lxpanel
PORTVERSION=	0.6.2
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF/lxde/LXPanel%20%28desktop%20panel%29/LXPanel%20${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight X11 desktop panel

LICENSE=	GPLv2 MIT
LICENSE_COMB=	dual

LIB_DEPENDS=	libmenu-cache.so:x11/menu-cache \
		libsysinfo.so:devel/libsysinfo
RUN_DEPENDS=	${LOCALBASE}/share/desktop-directories/lxde-audio-video.directory:x11/lxmenu-data \
		xmessage:x11/xmessage

USE_AUTOTOOLS=	automake:env
USE_CSTD=	gnu89
USE_GNOME=	gtk20 libwnck intltool
USE_XORG=	x11 xmu
USES=		gmake pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--with-plugins=netstatus,volume,volumealsa,deskno,batt,kbled,xkb,thermal,cpu,cpufreq,monitors,wnckpager \
		--with-x --disable-silent-rules \
		CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CFLAGS+=	-I${WRKSRC}

SUB_FILES=	pkg-message
PORTDOCS=	AUTHORS README

OPTIONS_DEFINE=	ALSA DOCS NLS
OPTIONS_SUB=	yes

ALSA_LIB_DEPENDS=	libasound.so:audio/alsa-lib
ALSA_CONFIGURE_ENABLE=	alsa
NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools

post-patch:
	@${REINPLACE_CMD} -e '/g_thread_create/ \
		s|.*|        g_thread_new("tf", (GThreadFunc)thread_func,\
		thread_data);|' \
		${WRKSRC}/src/gtk-run.c
	@${REINPLACE_CMD} -e '/g_thread_init/d' \
		${WRKSRC}/src/panel.c
	@${REINPLACE_CMD} -e 's|structure_size :|.structure_size =|; \
		s|structure_version :|.structure_version =|' \
		${WRKSRC}/src/plugin.h
	@${REINPLACE_CMD} -e 's|    type *:|    .type =|; \
		s|    name *:|    .name =|; \
		s|    version *:|    .version =|; \
		s|    description *:|    .description =|; \
		s|    constructor *:|    .constructor =|; \
		s|    destructor  *:|    .destructor =|; \
		s|    config *:|    .config =|; \
		s|    save *:|    .save =|; \
		s|    panel_configuration_changed *:|   \
		.panel_configuration_changed =|; \
		s|    fname:|    .fname =|; \
		s|    count:|    .count =|; \
		s|    expand_available :|    .expand_available =|; \
		s|    expand_default :|    .expand_default =|; \
		s|    one_per_system :|    .one_per_system =|; \
		s|    not_unloadable :|    .not_unloadable =|' \
		${WRKSRC}/src/plugins/batt/batt.c \
		${WRKSRC}/src/plugins/cpu*/cpu*.c \
		${WRKSRC}/src/plugins/deskno/deskno.c \
		${WRKSRC}/src/plugins/kbled/kbled.c \
		${WRKSRC}/src/plugins/monitors/monitors.c \
		${WRKSRC}/src/plugins/netstatus/netstatus.c \
		${WRKSRC}/src/plugins/thermal/thermal.c \
		${WRKSRC}/src/plugins/wnckpager/wnckpager.c \
		${WRKSRC}/src/plugins/xkb/xkb-plugin.c \
		${WRKSRC}/src/plugins/volume*/volume*.c \
		${WRKSRC}/src/plugins/*.c
	@${REINPLACE_CMD} -e '/gdk_color_parse(b/ s|;||; \
		/gdk_color_parse(b/{p;s/.*/            ;/;}' \
		${WRKSRC}/src/plugins/batt/batt.c
	@${REINPLACE_CMD} -e 's|/sys|/compat/linux&|' \
		${WRKSRC}/src/plugins/batt/batt_sys.h
	@${REINPLACE_CMD} -e 's|/proc|/compat/linux&|' \
		${WRKSRC}/src/plugins/cpu/cpu.c \
		${WRKSRC}/src/plugins/monitors/monitors.c \
		${WRKSRC}/src/plugins/thermal/thermal.c
	@${REINPLACE_CMD} -e 's|%lld|%lu|g; s|bytes >=|bytes >|' \
		${WRKSRC}/src/plugins/netstatus/netstatus-dialog.c
	@${REINPLACE_CMD} -e '/NETSTATUS_ERROR, code/ s|error_message|"%s", &|' \
		${WRKSRC}/src/plugins/netstatus/netstatus-iface.c
	@${REINPLACE_CMD} -e '611s/signal_strength)/*&/' \
		${WRKSRC}/src/plugins/netstatus/netstatus-sysdeps.c
	@${REINPLACE_CMD} -e 's|linux|sys|' \
		${WRKSRC}/src/plugins/volume/volume-impl.c

post-patch-NLS-off:
	@${REINPLACE_CMD} -e 's|po man|man|' \
		${WRKSRC}/Makefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lxpanel/plugins/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
