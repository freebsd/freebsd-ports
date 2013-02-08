# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	xnee
PORTVERSION=	3.15
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	X events recorder and player

LIB_DEPENDS=	pthread-stubs:${PORTSDIR}/devel/libpthread-stubs \
		xcb:${PORTSDIR}/x11/libxcb

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XORG=	x11 xau xdmcp xext xi xtst
USE_GNOME=	gnomehack
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--enable-cli --disable-doc --disable-xinput2

MAN1=		cnee.1 xnee.1
INFO=		xnee

OPTIONS_DEFINE=	GNEE PNEE
GNEE_DESC=	GUI frontend
PNEE_DESC=	GNOME panel frontend

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNEE}
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre \
		cairo:${PORTSDIR}/graphics/cairo \
		png15:${PORTSDIR}/graphics/png \
		freetype:${PORTSDIR}/print/freetype2 \
		expat:${PORTSDIR}/textproc/expat2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig

CONFIGURE_ARGS+=--enable-gui
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_XORG+=	pixman xcomposite xcursor xdamage xfixes xinerama xrandr xrender
USE_GNOME+=	gdkpixbuf2 gtk20 libgnomeui
MAN1+=		gnee.1
PLIST_SUB+=	GNEE=""
DESKTOP_ENTRIES=	"Gnee" "${COMMENT}" "${PORTNAME}.png" \
			"gnee" "Development;" true
.else
CONFIGURE_ARGS+=--disable-gui
PLIST_SUB+=	GNEE="@comment "
.endif

.if ${PORT_OPTIONS:MPNEE}
BROKEN=		Does not build, needs newer gnomepanel
CONFIGURE_ARGS+=-enable-gnome-applet
USE_GNOME+=	gnomepanel
MAN1+=		pnee.1
PLIST_SUB+=	PNEE=""
.else
CONFIGURE_ARGS+=	--disable-gnome-applet
CONFIGURE_ENV+=	libgnomeui_CFLAGS="${TRUE}" \
		libgnomeui_LIBS="${TRUE}"
PLIST_SUB+=	PNEE="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${libdir}/gnome-panel|$${prefix}/libexec|g ; \
		 s|$${libdir}/bonobo/|$${prefix}/libdata/bonobo/|g ; \
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
	@${REINPLACE_CMD} -e \
		's|cp pnee|$$(INSTALL_DATA) pnee|g' ${WRKSRC}/pnee/Makefile.in
	@${REINPLACE_CMD} -e \
		's|cp $$(PNEE)|$$(INSTALL_PROGRAM) $$(PNEE)|g' ${WRKSRC}/pnee/src/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
