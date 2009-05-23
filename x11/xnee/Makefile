# New ports collection makefile for:	xnee
# Date created:				27 May 2002
# Whom:					Alexey Dokuchaev <danfe@regency.nsu.ru>
#
# $FreeBSD$
#

PORTNAME=	xnee
PORTVERSION=	3.03
CATEGORIES=	x11
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X events recorder and player

OPTIONS=	GNEE "Build the GUI frontend" off \
		PNEE "Build the Gnome Panel frontend" off

USE_XORG=	xtst
USE_GNOME=	gnomehack
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cli --disable-doc

MAN1=		cnee.1 xnee.1
INFO=		xnee
PLIST_FILES=	bin/cnee \
		share/pixmaps/xnee.png \
		share/pixmaps/xnee.xpm \
		%%DATADIR%%/example1.xns \
		%%DATADIR%%/simple_bash.sh \
		%%DATADIR%%/xnee.sh
PLIST_DIRS=	${PNEE_DIR} %%DATADIR%%

.include <bsd.port.pre.mk>

.if defined(WITH_GNEE)
USE_GNOME+=	gtk20
MAN1+=		gnee.1
PLIST_FILES+=	bin/gnee
.else
CONFIGURE_ARGS+=	--disable-gui
.endif

.if defined(WITH_PNEE)
USE_GNOME+=	gnomepanel
MAN1+=		pnee.1
PLIST_FILES+=	libdata/bonobo/servers/pnee.server \
		libexec/pnee \
		%%DATADIR%%/pixmaps/pnee-record.png \
		%%DATADIR%%/pixmaps/pnee-replay.png \
		%%DATADIR%%/pixmaps/pnee-stop-mini.png \
		%%DATADIR%%/pixmaps/pnee-stop.png
PNEE_DIR=	%%DATADIR%%/pixmaps
.else
CONFIGURE_ARGS+=	--disable-gnome-applet
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
		's|src test|src|g' ${WRKSRC}/libxnee/Makefile.in
	@${REINPLACE_CMD} -e \
		's|ap=NULL;|ap;|g' ${WRKSRC}/libxnee/src/feedback.c
	@${REINPLACE_CMD} -e \
		's|cp pnee|$$(INSTALL_DATA) pnee|g' ${WRKSRC}/pnee/Makefile.in
	@${REINPLACE_CMD} -e \
		's|cp $$(PNEE)|$$(INSTALL_PROGRAM) $$(PNEE)|g' ${WRKSRC}/pnee/src/Makefile.in
	@${REINPLACE_CMD} -e \
		'/<gnome.h>/d' ${WRKSRC}/pnee/src/pnee_impl.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/xnee.info ${PREFIX}/${INFO_PATH}

.include <bsd.port.post.mk>
