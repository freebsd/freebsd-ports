PORTNAME=	xnee
PORTVERSION=	3.19
PORTREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	zab@zltech.eu
COMMENT=	X11 events recorder and player
WWW=		http://www.sandklef.com/xnee/

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USES=		gmake pathfix xorg
USE_XORG=	x11 xtst

CONFIGURE_ARGS=	--enable-cli --disable-doc --disable-xinput2

INFO=		${PORTNAME}

OPTIONS_DEFINE=	GNEE
OPTIONS_SUB=	yes

GNEE_DESC=	GUI frontend
GNEE_CONFIGURE_ENABLE=	gui
GNEE_USES=	gnome pkgconfig
GNEE_USE=	GNOME=gtk20

GNEE_DESKTOP_ENTRIES=	"Gnee" "" "${PORTNAME}.png" \
			"gnee" "Development;" true

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/gnome-panel|$${prefix}/libexec|g ; \
		 s|"CCC"|""|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|@PIXMAP_DIR@|pixmap|g ; \
		 s|@DOC_DIR@||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|make man|$$(MAKE) man|g' ${WRKSRC}/cnee/Makefile.in
	@${REINPLACE_CMD} -e \
		's|: install-docDATA|:|g' ${WRKSRC}/cnee/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|$$(libgnomeui_CFLAGS)||g ; \
		 s|$$(libgnomeui_LIBS)||g' ${WRKSRC}/gnee/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|src test|src|g' ${WRKSRC}/libxnee/Makefile.in
	@${REINPLACE_CMD} -E 's,} (${_ENUM_NAMES:ts|}),},' \
		${WRKSRC}/libxnee/include/libxnee/xnee.h \
		${WRKSRC}/libxnee/include/libxnee/xnee_grab.h \
		${WRKSRC}/libxnee/include/libxnee/xnee_internal.h \
		${WRKSRC}/libxnee/include/libxnee/xnee_window.h
	@${REINPLACE_CMD} -e \
		's|^xnee_option_t|extern &|' ${WRKSRC}/cnee/src/cnee_demo.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

# We must trim the names from enums below to build with -fno-common
_ENUM_NAMES=	_bool_string_values _cont_proc_commands _return_values \
		_xnee_grab_modes _xnee_protocol_data_numbers \
		_xnee_replay_backend _xnee_resolution_states \
		xnee_data_types xnee_grab_modifiers_control xnee_mode \
		xnee_option_type xnee_override_display xnee_window_types

.include <bsd.port.mk>
