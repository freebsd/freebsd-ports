# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	xnee
PORTVERSION=	3.16
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	pawel@FreeBSD.org
COMMENT=	X events recorder and player

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USE_XORG=	xtst
USES=		gmake pathfix
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--enable-cli --disable-doc --disable-xinput2

MAN1=		cnee.1 xnee.1
INFO=		xnee

OPTIONS_DEFINE=	GNEE PNEE
OPTIONS_SUB=	yes
GNEE_DESC=	GUI frontend
PNEE_DESC=	GNOME panel frontend

GNEE_CONFIGURE_ENABLE=	gui
PNEE_CONFIGURE_ENABLE=	gnome-applet

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGNEE}
USE_GNOME+=	gtk20
MAN1+=		gnee.1
DESKTOP_ENTRIES=	"Gnee" "${COMMENT}" "${PORTNAME}.png" \
			"gnee" "Development;" true
.endif

.if ${PORT_OPTIONS:MPNEE}
BROKEN=		Does not build, needs newer gnomepanel
USE_GNOME+=	gnomepanel
MAN1+=		pnee.1
.else
CONFIGURE_ENV+=	libgnomeui_CFLAGS="${TRUE}" \
		libgnomeui_LIBS="${TRUE}"
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
