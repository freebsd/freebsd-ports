# Created by: Alexey Dokuchaev <danfe@regency.nsu.ru>
# $FreeBSD$

PORTNAME=	xnee
PORTVERSION=	3.19
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 events recorder and player

LICENSE=	GPLv3

GNU_CONFIGURE=	yes
USES=		gmake pathfix xorg
USE_XORG=	xtst

CONFIGURE_ARGS=	--enable-cli --disable-doc --disable-xinput2

INFO=		${PORTNAME}

OPTIONS_DEFINE=	GNEE
OPTIONS_SUB=	yes

GNEE_DESC=	GUI frontend
GNEE_CONFIGURE_ENABLE=	gui
GNEE_USES=	pkgconfig
GNEE_USE=	GNOME=gtk20

GNEE_DESKTOP_ENTRIES=	"Gnee" "" "${PORTNAME}.png" \
			"gnee" "Development;" true

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

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

.include <bsd.port.mk>
