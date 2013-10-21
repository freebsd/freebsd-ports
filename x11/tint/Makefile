# $FreeBSD$

PORTNAME=	tint2
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	yamagi@yamagi.org
COMMENT=	Lightweight freedesktop-compliant panel/taskbar/systray/clock

LIB_DEPENDS=	libcairo.so:${PORTSDIR}/graphics/cairo

PROJECTHOST=	tint2
USE_BZIP2=	yes
USES=		cmake pkgconfig
USE_GNOME=	pango glib20
USE_XORG=	xinerama xrandr xdamage xcomposite
USE_EFL=	imlib2

CMAKE_ARGS=	-DENABLE_BATTERY:BOOL=ON -DMANDIR:PATH=man

OPTIONS_DEFINE=	PYCONF DOCS EXAMPLES
OPTIONS_DEFAULT=	PYCONF
OPTIONS_SUB=	yes
PYCONF_DESC=	Configuration editing tool (req. python)

EXAMPLES=	icon_and_text_1.tint2rc icon_and_text_2.tint2rc \
		icon_and_text_3.tint2rc icon_and_text_4.tint2rc \
		icon_only_1.tint2rc icon_only_2.tint2rc icon_only_3.tint2rc \
		icon_only_4.tint2rc icon_only_6.tint2rc icon_only_7.tint2rc \
		text_only_1.tint2rc text_only_2.tint2rc text_only_3.tint2rc \
		text_only_4.tint2rc text_only_5.tint2rc text_only_6.tint2rc tint2rc
DOCS=		AUTHORS ChangeLog README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPYCONF}
USE_PYTHON=	yes
USE_GNOME=	gtk20 pygtk2
CMAKE_ARGS+=	-DENABLE_TINT2CONF:BOOL=ON
PYCONF_SRC=	${WRKSRC}/src/tint2conf
.else
CMAKE_ARGS+=	-DENABLE_TINT2CONF:BOOL=OFF
.endif

.if ${PORT_OPTIONS:MPYCONF}
post-patch:
	@${MV} ${PYCONF_SRC}/tintwizard.py ${PYCONF_SRC}/tintwizard.py.Dist
	@${SED} -e 's#pidof#pgrep#g' ${PYCONF_SRC}/tintwizard.py.Dist \
		> ${PYCONF_SRC}/tintwizard.py
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tint2 ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/tint2
	${INSTALL_DATA} ${WRKSRC}/default_icon.png ${STAGEDIR}${PREFIX}/share/tint2
	${INSTALL_MAN} ${WRKSRC}/doc/tint2.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/sample; ${INSTALL_DATA} ${EXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.if ${PORT_OPTIONS:MPYCONF}
	${INSTALL_PROGRAM} ${PYCONF_SRC}/tint2conf ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${PYCONF_SRC}/tintwizard.py ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.desktop ${STAGEDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.png ${STAGEDIR}${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${PYCONF_SRC}/tint2conf.svg ${STAGEDIR}${PREFIX}/share/pixmaps
.endif

.include <bsd.port.mk>
