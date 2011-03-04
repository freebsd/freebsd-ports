# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	3.09
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	c0rn@o2.pl
COMMENT=	X events recorder and player

LICENSE=	GPLv3

OPTIONS=	GNEE "Build the GUI frontend" off \
		PNEE "Build the Gnome Panel frontend" off

USE_XORG=	xtst
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--enable-cli --disable-doc --disable-xinput2

MAN1=		cnee.1 xnee.1
INFO=		xnee

.include <bsd.port.pre.mk>

.if defined(WITH_GNEE)
USE_GNOME+=	gtk20
MAN1+=		gnee.1
PLIST_SUB+=	GNEE=""
DESKTOP_ENTRIES=	"Gnee" "${COMMENT}" "${PREFIX}/share/pixmaps/xnee.png" \
			"gnee" "Development;" true
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB+=	GNEE="@comment "
.endif

.if defined(WITH_PNEE)
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

.include <bsd.port.post.mk>
